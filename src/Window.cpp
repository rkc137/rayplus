#include <rayplus/Window.hpp>

#include <raylib.h>

namespace rayplus::window
{

WindowCloser::~WindowCloser()
{
    if(is_closed) return;
    is_closed = true;
    CloseWindow();
}

WindowCloser init(Vector2<int> size, std::string title, int target_fps)
{
    InitWindow(size.x, size.y, title.c_str());
    SetTargetFPS(target_fps);
    return WindowCloser{};
}

bool should_close()
{
    return WindowShouldClose();
}

void set_title(std::string title)
{
    SetWindowTitle(title.c_str());
}

void set_size(Vector2<int> size)
{
    SetWindowSize(size.x, size.y);
}

Vector2<int> get_size()
{
    return {
        GetScreenWidth(),
        GetScreenHeight()
    };
}

} // namespace rayplus::window