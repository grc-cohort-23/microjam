#include "bal/bal_rocks.h"
#include "bn_sprite_items_bal_square.h"

namespace bal{
    rock::rock(int starting_x, int starting_y, bn::fixed rock_speed, bn::size rock_size) :
        sprite(bn::sprite_items::bal_square.create_sprite(starting_x, starting_y)),
        speed(rock_speed),
        size(rock_size),
        bounding_box(bn::rect(starting_x, starting_y, rock_size.width(), rock_size.height()))
        {}

    bool rock::update(){
        sprite.set_y(sprite.y() + speed);
        bounding_box = bn::rect(
            sprite.x().round_integer(),
            sprite.y().round_integer(),
            size.width(),
            size.height()
        );

        //checks if rock has reached the bottom
        return sprite.y() > MAX_Y;
    }
}