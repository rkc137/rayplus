#include "rayplus/Drawler.hpp"

#include <raylib.h>

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

void DrawContext::draw_rect(Vector2<int> pos, Vector2<int> size)
{
    DrawRectangle(pos.x, pos.y, size.x, size.y, MAROON);
}

void DrawContext::clear()
{
    ClearBackground(RAYWHITE);
}

} // namespace rayplus