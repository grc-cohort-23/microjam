#include "any_game_name.h"
#include "bn_sprite_items_astronaut.h"
#include "bn_sprite_items_platform.h"
#include "bn_sprite_items_moon.h"
#include "mj/mj_small_sprite_font.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_items_bg.h"

#include "mj/mj_game_list.h"

namespace {
    constexpr bn::string_view code_credits[] = { "Anthony Margullis, Yousif Sultan" };
    constexpr bn::string_view graphics_credits[] = { "Anthony Margullis, Yousif Sultan" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(any::any_game_name)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace any {

any_game_name::any_game_name(int completed_games, const mj::game_data& data) :
    mj::game("any"),
    _has_lost(false)
{
    mj::difficulty_level difficulty = recommended_difficulty_level(completed_games, data);

    if (difficulty == mj::difficulty_level::EASY) {
        _platforms[0] = {0, 40};
        _platforms[1] = {-30, 10};
        _platforms[2] = {40, -20}; 
        _moon_y = -60;
    }
    else if (difficulty == mj::difficulty_level::NORMAL) {
        _platforms[0] = {0, 40};
        _platforms[1] = {-50, 5};  
        _platforms[2] = {40, -25}; 
        _moon_y = -60;
    }
    else { // HARD
        _platforms[0] = {0, 40};   
        _platforms[1] = {-40, 10};  
        _platforms[2] = {59, -30}; 
        _moon_y = -65;
    }

    _platform_sprite_1 = bn::sprite_items::platform.create_sprite(_platforms[0].x, _platforms[0].y); 
    _platform_sprite_2 = bn::sprite_items::platform.create_sprite(_platforms[1].x, _platforms[1].y); 
    _platform_sprite_3 = bn::sprite_items::platform.create_sprite(_platforms[2].x, _platforms[2].y);
    
    _moon_sprite = bn::sprite_items::moon.create_sprite(85, _moon_y);
    
    _astronaut_sprite = bn::sprite_items::astronaut.create_sprite(0, -20);
    _player.emplace(*_astronaut_sprite);

    _background = bn::regular_bg_items::bg.create_bg(0, 0);
    
    _background->set_priority(3);

    bn::sprite_text_generator text_generator(mj::small_sprite_font);
    text_generator.set_center_alignment();

    bn::string_view diff_text;
    if (difficulty == mj::difficulty_level::EASY) {
        diff_text = "EASY";
    } else if (difficulty == mj::difficulty_level::NORMAL) {
        diff_text = "MEDIUM";
    } else {
        diff_text = "HARD";
    }

    text_generator.generate(0, 55, diff_text, _text_sprites);
}



bn::string<16> any_game_name::title() const {
    return "Grab the Moon";
}

int any_game_name::total_frames() const {
    return 600;
}

mj::game_result any_game_name::play([[maybe_unused]] const mj::game_data& data) {
    if (data.pending_frames < 480 && !_text_sprites.empty()) {
        _text_sprites.clear();
    }

    if (_player) {
        _player->update(bn::span<const platform>(_platforms, 3));

        bn::fixed dx = _player->x() - 90;
        bn::fixed dy = _player->y() - _moon_y;

        if (bn::abs(dx) < 10 && bn::abs(dy) < 10) { 
            return mj::game_result(true, true); 
        }

        if (_player->y() > 80) {
            _has_lost = true; 
            return mj::game_result(true,false);
        }

    }

    return mj::game_result(false, false);
}

bool any_game_name::victory() const {
    if (_has_lost || !_player)
     return false;

    return bn::abs(_player->x() - 85) < 15 && bn::abs(_player->y() - _moon_y) < 15;
}

void any_game_name::fade_in([[maybe_unused]]const mj::game_data& data)
{
}

void any_game_name::fade_out([[maybe_unused]] const mj::game_data& data)
{    
}

}