#pragma once

#include "Color.hpp"
#include "Vector2.hpp"

namespace rayplus
{

struct DrawContext
{
    void draw_rect(Vector2<int> pos, Vector2<int> size, Color color);
    void clear(Color color);
};

class Drawler
{
public:
    inline static DrawContext ctx;
    Drawler();
    ~Drawler();
};

}