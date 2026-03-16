#include "mar/mar_player.h"

#include <bn_keypad.h>
#include <bn_rect.h>

#include "bn_sprite_items_square.h"
#include "bn_sprite_items_droid.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace mar
{

    /**
     * mar_player constructor
     *
     * @param starting_position the location to start the mar_player at
     * @param speed the pixels/frame the mar_player moves at in each dimension
     */
    mar_player::mar_player(
        bn::fixed_point starting_position,
        bn::fixed speed) : _sprite(bn::sprite_items::droid.create_sprite(starting_position)),
                           _speed(speed),
                           _rect(
                               bn::rect(
                                   starting_position.x().round_integer(),
                                   starting_position.y().round_integer(), 16, 16))
    {
    }

    /**
     * Reads from the d-pad and moves the mar_player by one frame accordingly.
     */
    void mar_player::update()
    {
        // If up is held moves up. If down is held moves down. Otherwise, moves down at a slower speed to simulate gravity.
        if (bn::keypad::up_held() && _sprite.y() > MIN_Y)
        {
            _sprite.set_y(_sprite.y() - _speed - 2);
            pause_timer = 30;
        }
        // count down the pause timer if it's greater than 0, which will cause the player to fall slower for a short time after moving up
        if (pause_timer > 0 && !bn::keypad::up_held())
        {
            --pause_timer;
            _sprite.set_y(_sprite.y() + _speed / 8);
        }

        else if (_sprite.y() < MAX_Y)
        {
            _sprite.set_y(_sprite.y() + _speed / 2);
        }

        if (bn::keypad::down_held() && _sprite.y() < MAX_Y)
        {
            _sprite.set_y(_sprite.y() + _speed);
        }

        _rect.set_position(_sprite.x().round_integer(), _sprite.y().round_integer());
    }
}