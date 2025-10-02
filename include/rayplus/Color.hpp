#pragma once

#include <cstdint>
#include <concepts>

namespace rayplus
{

struct Color
{
    using u8 = std::uint8_t;
    u8 r{}, g{}, b{}, a{};

    Color() = default;
    ~Color() = default;

    constexpr Color(u8 r, u8 g, u8 b, u8 a)
    : r(r), g(g), b(b), a(a)
    {}

    template <typename T>
    requires std::is_integral_v<T> && (sizeof(T) <= 4)
    constexpr Color(T r, T g, T b, T a)
    : r(static_cast<u8>(r)),
      g(static_cast<u8>(g)),
      b(static_cast<u8>(b)),
      a(static_cast<u8>(a))
    {}
    
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Color(T r, T g, T b, T a)
    : r(static_cast<u8>(r * 255)),
      g(static_cast<u8>(g * 255)),
      b(static_cast<u8>(b * 255)),
      a(static_cast<u8>(a * 255))
    {}
};

inline constexpr Color
lightgray  { 200, 200, 200, 255 },   // Light Gray
gray       { 130, 130, 130, 255 },   // Gray
darkgray   { 80, 80, 80, 255 },      // Dark Gray
yellow     { 253, 249, 0, 255 },     // Yellow
gold       { 255, 203, 0, 255 },     // Gold
orange     { 255, 161, 0, 255 },     // Orange
pink       { 255, 109, 194, 255 },   // Pink
red        { 230, 41, 55, 255 },     // Red
maroon     { 190, 33, 55, 255 },     // Maroon
green      { 0, 228, 48, 255 },      // Green
lime       { 0, 158, 47, 255 },      // Lime
darkgreen  { 0, 117, 44, 255 },      // Dark Green
skyblue    { 102, 191, 255, 255 },   // Sky Blue
blue       { 0, 121, 241, 255 },     // Blue
darkblue   { 0, 82, 172, 255 },      // Dark Blue
purple     { 200, 122, 255, 255 },   // Purple
violet     { 135, 60, 190, 255 },    // Violet
darkpurple { 112, 31, 126, 255 },    // Dark Purple
beige      { 211, 176, 131, 255 },   // Beige
brown      { 127, 106, 79, 255 },    // Brown
darkbrown  { 76, 63, 47, 255 },      // Dark Brown
white      { 255, 255, 255, 255 },   // White
black      { 0, 0, 0, 255 },         // Black
blank      { 0, 0, 0, 0 },           // Blank (Transparent)
magenta    { 255, 0, 255, 255 },     // Magenta
raywhite   { 245, 245, 245, 255 };   // raylib logo

} // namespace rayplus