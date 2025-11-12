#pragma once

#include <type_traits>

namespace rayplus
{

template <typename T>
requires (std::is_arithmetic_v<T>)
struct Vector2
{
    T x{}, y{};

    template <typename TC>
    requires (std::is_arithmetic_v<TC>)
    Vector2(TC x, TC y) : x(static_cast<T>(x)), y(static_cast<T>(y)) {}

    Vector2 operator-(const Vector2 &right) { return {
        x - right.x,
        y - right.y
    };}

    Vector2 operator+(const Vector2 &right) { return {
        x + right.x,
        y + right.y
    };}

    Vector2 operator/(const Vector2 &right) { return {
        x / right.x,
        y / right.y
    };}

    Vector2 operator*(const Vector2 &right) { return {
        x * right.x,
        y * right.y
    };}

    template <typename TC>
    requires (std::is_arithmetic_v<TC>)
    Vector2 operator-(const TC &right) { return {
        x - right,
        y - right
    };}

    template <typename TC>
    requires (std::is_arithmetic_v<TC>)
    Vector2 operator+(const TC &right) { return {
        x + right,
        y + right
    };}

    template <typename TC>
    requires (std::is_arithmetic_v<TC>)
    Vector2 operator/(const TC &right) { return {
        x / right,
        y / right
    };}

    template <typename TC>
    requires (std::is_arithmetic_v<TC>)
    Vector2 operator*(const TC &right) { return {
        x * right,
        y * right
    };}
};

} // namespace rayplus