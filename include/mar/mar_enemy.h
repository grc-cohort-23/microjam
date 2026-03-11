#ifndef MAR_ENEMY_H
#define MAR_ENEMY_H

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>

// All game functions/classes/variables/constants scoped to the namespace
namespace mar
{

    /**
     *
     */
    class mar_enemy
    {
        // The bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = -bn::display::height() / 2;

    public:
        /**
         * enemy constructor
         *
         * @param starting_position the location to start the enemy at
         * @param speed the pixels/frame the enemy moves at in each dimension
         */
        mar_enemy(bn::fixed_point starting_position, bn::fixed speed);

        // move the enemy
        void update();
        bn::rect &rect() { return _rect; }

    private:
        // The sprite to display the enemy
        bn::sprite_ptr _sprite;
        // The pixels/frame the enemy moves in each dimension
        bn::fixed _speed;

        bn::rect _rect;
    };

}

#endif