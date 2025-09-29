#pragma once

#include <concepts>

#include "Drawler.hpp"

namespace rayplus
{

template <typename T>
requires std::invocable<T, DrawContext&>
void draw(T&& func)
{
    Drawler drawler;
    func(Drawler::ctx);
}
    
}