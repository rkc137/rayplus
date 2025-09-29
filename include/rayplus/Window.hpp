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

static Vector2<int> window_size = {};

[[nodiscard]] WindowCloser init(Vector2<int> size, std::string title, int target_fps = 60);
[[nodiscard]] bool should_close();
void set_title(std::string title);

} // namespace rayplus::window