#pragma once

#include "Vector2.hpp"

namespace rayplus::mouse
{

enum class Button;
enum class Cursor;

[[nodiscard]] bool is_pressed(Button button);
[[nodiscard]] bool is_down(Button button);
[[nodiscard]] bool is_released(Button button);
[[nodiscard]] bool is_up(Button button);
[[nodiscard]] float get_mouse_wheel_move();
[[nodiscard]] Vector2<float> get_mouse_delta();
[[nodiscard]] Vector2<float> get_mouse_wheel_move_vector();
[[nodiscard]] Vector2<float> get_mouse_position();

void set_offset(Vector2<int> offset);
void set_scale(Vector2<float> scale);
void set_position(Vector2<float> pos);
void set_cursor(Cursor cursor);

enum class Button
{
    left    = 0,       // Mouse button left
    right   = 1,       // Mouse button right
    middle  = 2,       // Mouse button middle (pressed wheel)
    side    = 3,       // Mouse button side (advanced mouse device)
    extra   = 4,       // Mouse button extra (advanced mouse device)
    forward = 5,       // Mouse button forward (advanced mouse device)
    back    = 6,       // Mouse button back (advanced mouse device)
};

enum class Cursor
{
    normal        = 0,     // Default pointer shape
    arrow         = 1,     // Arrow shape
    ibeam         = 2,     // Text writing cursor shape
    crosshair     = 3,     // Cross shape
    pointing_hand = 4,     // Pointing hand cursor
    resize_ew     = 5,     // Horizontal resize/move arrow shape
    resize_ns     = 6,     // Vertical resize/move arrow shape
    resize_nwse   = 7,     // Top-left to bottom-right diagonal resize/move arrow shape
    resize_nesw   = 8,     // The top-right to bottom-left diagonal resize/move arrow shape
    resize_all    = 9,     // The omnidirectional resize/move cursor shape
    not_allowed   = 10     // The operation-not-allowed shape
};


}