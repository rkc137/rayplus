#include "rayplus/Drawler.hpp"

#include <raylib.h>


constexpr ::Color to_raylib(const rayplus::Color& c)
{
    return { c.r, c.g, c.b, c.a };
}

namespace rayplus
{

Drawler::Drawler()
{
    BeginDrawing();
}

Drawler::~Drawler()
{
    EndDrawing();
}

} // namespace rayplus

void rayplus::DrawContext::clear(rayplus::Color color)
{
    ClearBackground(to_raylib(color));
}

void rayplus::DrawContext::draw_rect(rayplus::Vector2<int> pos, rayplus::Vector2<int> size, rayplus::Color color)
{
    DrawRectangle(pos.x, pos.y, size.x, size.y, to_raylib(color));
}