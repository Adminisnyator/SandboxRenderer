
/* MIT License

Copyright (c) 2024 Adminisnyator

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include <raylib.h>
#include <rlgl.h>
#include <stdint.h>
#include <time.h>

#define MAX_COLUMNS 20

int read_map(void) { return 1; }

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "GameTest");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
  Shader owoshader = LoadShader(NULL, "./shaders/quake.frag");
  float screen_ratio = (float)GetScreenHeight() / (float)GetScreenWidth();
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    // TODO: Figure out if we need to reset it every time.
    ClearBackground(RAYWHITE);

    Texture defTexture = {.id = rlGetTextureIdDefault(),
                          .width = 1,
                          .height = 1,
                          .mipmaps = 1,
                          .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8};

    BeginShaderMode(owoshader);
    DrawTexturePro(defTexture, (Rectangle){0, 0, 1, screen_ratio},
                   (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()},
                   (Vector2){0}, 0, WHITE);
    EndShaderMode();
    DrawRectangle(0, 0, 300, 300, BLUE);
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
