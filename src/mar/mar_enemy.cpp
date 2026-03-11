#include "mar/mar_enemy.h"
#include "bn_sprite_items_dot.h"


namespace mar{
	/**
     * mar_player constructor
     *
     * @param starting_position the location to start the mar_player at
     * @param speed the pixels/frame the mar_player moves at in each dimension
     */
    mar_enemy::mar_enemy(
        bn::fixed_point starting_position, 
        bn::fixed speed) :                              
            _sprite(
                bn::sprite_items::dot.create_sprite(
                    starting_position
                )
            ),
            _speed(speed), 
            _rect(bn::rect(
                starting_position.x().round_integer(), 
                starting_position.y().round_integer(), 8, 8)
            )
    {
    }

    void mar_enemy::update()
    {
        _sprite.set_x(_sprite.x() - _speed);
        _rect.set_position(_sprite.x().round_integer(), _sprite.y().round_integer()); 
    }
}