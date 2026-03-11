#include "mar_mars_escape.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include <bn_backdrop.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_display.h>
#include <bn_random.h>

#include "mj/mj_game_list.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = {"Buay Dak, Samuel Marchuk"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(mar::mar_mars_escape) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

// All game functions/classes/variables/constants scoped to the namespace
namespace mar
{

    /**
     * Constructor for an instance of an aub_test_game
     * @param completed_games how many microgames the player has completed so far
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    mar_mars_escape::mar_mars_escape([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("mar"),
                                                                                                                         _player(mar_player({20, 0}, 2))
    {

        bn::random rng = bn::random();
        for (int i = 0; i < 15; i++)
        {
            enemies.push_back(mar_enemy(
                {bn::display::width() / 2,
                 rng.get_int(-bn::display::height() / 2, bn::display::height() / 2)},
                1));
            rng.update();
        }
    }

    /**
     * The instructions given to the player at the beginning of the microgame.
     *
     * Must be <= 16 characters long
     */
    bn::string<16> mar_mars_escape::title() const
    {
        return "Escape Mars!";
    }

    /**
     * How long the timer for the game should be set to in frames.
     *
     * GBA runs at approx 60 frames per second.
     */
    int mar_mars_escape::total_frames() const
    {
        return 600; // 600 frames at 60fps = 10 seconds
    }

    /**
     * play is repeatedly called while the microgame is playing.
     *
     * You can think of it as what previously was in the while event loop.
     * You do NOT need to write your own while event loop
     * You do NOT need to call bn::core::update()
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
     */
    mj::game_result mar_mars_escape::play([[maybe_unused]] const mj::game_data &data)
    {
        // update the player position
        _player.update();
        for (int i = 0; i < enemies.size(); i++)
        {
            enemies[i].update();
            if (_player.rect().intersects(enemies[i].rect()))
            {
                collision = true;
                return mj::game_result(true, false);
            }
        }
        return mj::game_result(false, false);
    }

    bool mar_mars_escape::victory() const
    {
        return !collision;
        ;
    }

    /**
     * Called repeatedly as the game fades into view. Unused for this particular microgame.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void mar_mars_escape::fade_in([[maybe_unused]] const mj::game_data &data)
    {
    }

    /**
     * Called repeatedly as the game fades into view. Unused for this particular microgame.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void mar_mars_escape::fade_out([[maybe_unused]] const mj::game_data &data)
    {
    }
}