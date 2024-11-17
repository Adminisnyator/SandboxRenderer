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
