#include "rayplus/Keyboard.hpp"

#include <raylib.h>

namespace rayplus::keyboard
{


bool is_down(Key key)
{
    return IsKeyDown(static_cast<int>(key));
}

bool is_pressed_repeat(Key key)
{
    return IsKeyPressedRepeat(static_cast<int>(key));
}

bool is_up(Key key)
{
    return IsKeyUp(static_cast<int>(key));
}

bool is_released(Key key)
{
    return IsKeyReleased(static_cast<int>(key));
}

bool is_pressed(Key key)
{
    return IsKeyPressed(static_cast<int>(key));
}


} // namespace rayplus