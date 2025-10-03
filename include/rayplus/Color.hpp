#pragma once

#include <cstdint>
#include <concepts>

namespace rayplus
{

struct Color
{
    using u8 = std::uint8_t;
    u8 r{}, g{}, b{}, a{};

    constexpr Color() = default;

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

    static const Color 
        lightgray, // Light Gray
        gray,      // Gray
        darkgray,  // Dark Gray
        yellow,    // Yellow
        gold,      // Gold
        orange,    // Orange
        pink,      // Pink
        red,       // Red
        maroon,    // Maroon
        green,     // Green
        lime,      // Lime
        darkgreen, // Dark Green
        skyblue,   // Sky Blue
        blue,      // Blue
        darkblue,  // Dark Blue
        purple,    // Purple
        violet,    // Violet
        darkpurple,// Dark Purple
        beige,     // Beige
        brown,     // Brown
        darkbrown, // Dark Brown
        white,     // White
        black,     // Black
        blank,     // Blank (Transparent)
        magenta,   // Magenta
        raywhite;  // raylib logo
};

inline const Color 
    Color::lightgray  { 200, 200, 200, 255 },   // Light Gray
    Color::gray       { 130, 130, 130, 255 },   // Gray
    Color::darkgray   { 80, 80, 80, 255 },      // Dark Gray
    Color::yellow     { 253, 249, 0, 255 },     // Yellow
    Color::gold       { 255, 203, 0, 255 },     // Gold
    Color::orange     { 255, 161, 0, 255 },     // Orange
    Color::pink       { 255, 109, 194, 255 },   // Pink
    Color::red        { 230, 41, 55, 255 },     // Red
    Color::maroon     { 190, 33, 55, 255 },     // Maroon
    Color::green      { 0, 228, 48, 255 },      // Green
    Color::lime       { 0, 158, 47, 255 },      // Lime
    Color::darkgreen  { 0, 117, 44, 255 },      // Dark Green
    Color::skyblue    { 102, 191, 255, 255 },   // Sky Blue
    Color::blue       { 0, 121, 241, 255 },     // Blue
    Color::darkblue   { 0, 82, 172, 255 },      // Dark Blue
    Color::purple     { 200, 122, 255, 255 },   // Purple
    Color::violet     { 135, 60, 190, 255 },    // Violet
    Color::darkpurple { 112, 31, 126, 255 },    // Dark Purple
    Color::beige      { 211, 176, 131, 255 },   // Beige
    Color::brown      { 127, 106, 79, 255 },    // Brown
    Color::darkbrown  { 76, 63, 47, 255 },      // Dark Brown
    Color::white      { 255, 255, 255, 255 },   // White
    Color::black      { 0, 0, 0, 255 },         // Black
    Color::blank      { 0, 0, 0, 0 },           // Blank (Transparent)
    Color::magenta    { 255, 0, 255, 255 },     // Magenta
    Color::raywhite   { 245, 245, 245, 255 };   // raylib logo

} // namespace rayplus