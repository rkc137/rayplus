#include <rayplus/Mouse.hpp>

#include <raylib.h>

namespace rayplus::mouse
{
    
using raylib_button_t = int;
static constexpr raylib_button_t ci(Button button)
{
    return static_cast<raylib_button_t>(button);
}

bool is_pressed(Button button)
{
    return IsMouseButtonPressed(ci(button));
}

bool is_down(Button button)
{
    return IsMouseButtonDown(ci(button));
}

bool is_released(Button button)
{
    return IsMouseButtonReleased(ci(button));
}

bool is_up(Button button)
{
    return IsMouseButtonUp(ci(button));
}

float get_mouse_wheel_move()
{
    return GetMouseWheelMove();
}

Vector2<float> get_mouse_delta()
{
    auto delta = GetMouseDelta();
    return Vector2<float>{
        delta.x, delta.y
    };
}

Vector2<float> get_mouse_wheel_move_vector()
{
    auto vec = GetMouseWheelMoveV();
    return Vector2<float>{
        vec.x, vec.y
    };
}

Vector2<float> get_mouse_position()
{
    auto pos = GetMousePosition();
    return Vector2<float>{
        pos.x, pos.y
    };
}

void set_position(Vector2<float> pos)
{
    SetMousePosition(pos.x, pos.y);
}

void set_offset(Vector2<int> offset)
{
    SetMouseOffset(offset.x, offset.y);
}

void set_scale(Vector2<float> scale)
{
    SetMouseScale(scale.x, scale.y);
}

void set_cursor(Cursor cursor)
{
    SetMouseCursor(static_cast<int>(cursor));
}

}