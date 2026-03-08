#ifndef ANY_PLAYER_H
#define ANY_PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_span.h"

namespace any {

struct platform {
    bn::fixed x;
    bn::fixed y;
};

class player {
public:
    player(bn::sprite_ptr sprite) : _sprite(sprite) {}

    void update(bn::span<const platform> platforms) {
        if (bn::keypad::left_held()) { _sprite.set_x(_sprite.x() - 2); }
        else if (bn::keypad::right_held()) { _sprite.set_x(_sprite.x() + 2); }

        _dy += 0.2;
        _sprite.set_y(_sprite.y() + _dy);

       



        if (_dy > 0) {
            for (const platform& p : platforms) {
                if (_sprite.y() >= p.y - 5 && _sprite.y() <= p.y + 2 &&
                    _sprite.x() >= p.x - 20 && _sprite.x() <= p.x + 20) {
                    _dy = -4;
                    _sprite.set_y(p.y - 2);
                }
            }
        }
    }

    bn::fixed y() const { return _sprite.y(); }

private:
    bn::sprite_ptr _sprite;
    bn::fixed _dy = 0;
};

}

#endif