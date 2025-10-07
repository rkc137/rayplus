#pragma once

#include <string>
#include "Vector2.hpp"

namespace rayplus::window
{

class WindowCloser
{
public:
    WindowCloser() = default;
    ~WindowCloser();
private:
    inline static bool is_closed = false;
};

[[nodiscard]] Vector2<int> get_size();
[[nodiscard]] WindowCloser init(Vector2<int> size, std::string title, int target_fps = 60);
[[nodiscard]] bool should_close();
void toggle_fullscreen();
void toggle_borderless_windowed();
void set_target_fps(int fps);
void set_title(std::string title);
void set_size(Vector2<int> size);

} // namespace rayplus::window