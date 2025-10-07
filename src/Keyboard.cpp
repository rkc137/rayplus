#include "rayplus/Keyboard.hpp"

#include <raylib.h>

namespace rayplus::keyboard
{

using raylib_key_t = int;
static constexpr raylib_key_t ci(Key key)
{
    return static_cast<int>(key);
}

bool is_down(Key key)
{
    return IsKeyDown(ci(key));
}

bool is_pressed_repeat(Key key)
{
    return IsKeyPressedRepeat(ci(key));
}

bool is_up(Key key)
{
    return IsKeyUp(ci(key));
}

bool is_released(Key key)
{
    return IsKeyReleased(ci(key));
}

bool is_pressed(Key key)
{
    return IsKeyPressed(ci(key));
}

Key get_key_pressed()
{
    return static_cast<Key>(GetKeyPressed());
}

int get_char_pressed()
{
    return GetCharPressed();
}

void set_exit_key(Key key)
{
    SetExitKey(ci(key));
}

} // namespace rayplus