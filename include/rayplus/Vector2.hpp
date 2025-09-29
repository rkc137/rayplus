#pragma once

#include <type_traits>

namespace rayplus
{

template <typename T>
requires (std::is_arithmetic_v<T>)
struct Vector2
{
    T x, y;
};

} // namespace rayplus