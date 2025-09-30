#pragma once

#include <cstdint>
#include "Vector2.hpp"

namespace rayplus
{

struct Color
{
    std::uint8_t r, g, b, a;
};

struct DrawContext
{
    void draw_rect(Vector2<int> pos, Vector2<int> size, Color color);
    void clear(Color color);
};

class Drawler
{
public:
    inline static DrawContext ctx;
    Drawler();
    ~Drawler();
};

inline const Color
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

}