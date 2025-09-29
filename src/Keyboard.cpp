#include "rayplus/Keyboard.hpp"

#include <raylib.h>

namespace rayplus::keyboard
{

bool is_pressed(Key key)
{
    return IsKeyReleased(static_cast<int>(key));
}

} // namespace rayplus