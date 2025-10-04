
# Rayplus
- [What?](#what-is-this)
- [How?](#how-to-use-it)
- [Why?](#why-you-need-this)
### What is this?
A small wrapper for [raylib](https://www.raylib.com/) that makes it feel more C++ish.
### How to use it?
You can easily get it with CMake FetchContent:
```cmake
FetchContent_Declare(
    rayplus
    GIT_REPOSITORY https://github.com/rkc137/rayplus.git
    GIT_TAG <latest-git-tag> )
FetchContent_MakeAvailable(rayplus)
target_link_libraries(${PROJECT_NAME} PRIVATE rayplus)
```
or via CPM.cmake
```cmake
CPMAddPackage("gh:rkc137/rayplus@<latest-git-tag>")
```
### Why you need this?
I just don't really like other variants for several reasons (espicaly [raylib-cpp](https://github.com/RobLoach/raylib-cpp)), so I ask myself, why not create one that works the way I like?
For example, in the main version of raylib you can’t create more than one window. But in raylib-cpp, a window is still represented as an independent object, which feels misleading:
```C++
#include "raylib-cpp.hpp"
int main() {
    raylib::Window window(800, 600, "raylib");
    // what will happen if i make another window or move this one?
    // will it casuse double call of InitWindow and CloseWindow?
}
```
In **rayplus**, the window is not a class but a namespace that works with the single available window, like providing a `Closer` object for RAII-style cleanup.
Also, like in [SFML](https://www.sfml-dev.org), a position isn’t represented by two unrelated variables `x` and `y`, but by a `Vector2D` containing `{x, y}`:
```C++
#include <rayplus>
int main() {
    auto win_closer = rayplus::window::init(
        {800, 600}, "rayplus", 10
    );
}
```
Another example: `BeginDraw` and `EndDraw`.  
It seems obvious that the situation here is similar to windows: in C we have to manually manage them, but now we are in C++, right? Sooo, in raylib-cpp for some reason you still have to call the two raylib functions directly (they aren’t even wrapped):
```C++
BeginDrawing();
	window.ClearBackground(RAYWHITE);
	DrawText("Text", 190, 200, 20, LIGHTGRAY);
EndDrawing();
```
**Rayplus** on other way provides two alternatives.  
The first one looks more like what we do with windows: we create a `Drawler` object, which calls `BeginDrawing` in its constructor and `EndDrawing` in its destructor, wich pretty useful in special function for drawing:
```C++
void draw() {
	rayplus::Drawler drawler;
	auto &ctx = rayplus::Drawler::ctx; // drawler.ctx works as well
	ctx.clear();
	ctx.draw_text("Text", 190, 200, 20, rayplus::lightgray);
}
```
The second way is the `rayplus::draw` function, which I personally prefer because it creates a new scope for drawing, though some of you might find it uglier:
```C++
rayplus::draw([&](rayplus::DrawContext &ctx){
	ctx.clear();
	ctx.draw_text("Text", 190, 200, 20, rayplus::lightgray);
});
```
And the main reason: **raylib-cpp doesn’t hide** `raylib.h`, which clutters your scope with all that C stuff.  
I love when everything is in namespaces, private sections, etc., so I can freely use names like `draw` or `Texture` without colliding with global identifiers. In rayplus, everything lives inside the `rayplus::` namespace.