#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

// Global variables for the web state
const int screenWidth = 800;
const int screenHeight = 450;

// Function to update and draw one frame
void UpdateDrawFrame(void) {
    // 1. Update
    // ---------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT)) /* Move something */;
    
    // 2. Draw
    // ---------------------------------------------------------
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! Raylib is running in your browser.", 190, 200, 20, LIGHTGRAY);
        DrawFPS(10, 10);
    EndDrawing();
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "raylib [core] - web test");

#if defined(PLATFORM_WEB)
    // 0 = browser decides frame rate (usually 60fps), true = simulate infinite loop
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();
    return 0;
}