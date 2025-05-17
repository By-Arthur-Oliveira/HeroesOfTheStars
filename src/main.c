#include "raylib.h"
#include "resource_dir.h"
#include "menu.h"
#include "game.h"

int main()
{ // Configuração da janela
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "HEROES OF THE STARS");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    DisableCursor();

    Texture2D mainMenuBackgroundImage = LoadTexture("resources/MenuAssets/background.jpg");

    Music backgroundMusic = LoadMusicStream("resources/MenuAssets/musictheme.mp3");
    PlayMusicStream(backgroundMusic);

    // Loop principal do jogo
    while (!WindowShouldClose())
    {
        UpdateMusicStream(backgroundMusic);
        BeginDrawing();

        DrawTexture(mainMenuBackgroundImage, 0, 0, WHITE);

        switch (optionController)
        {
        case 0:
            drawMainMenu();
            break;
        case 1:
            drawNewGame();
            break;
        case 2:
            drawLeaderboard();
            break;
        case 3:
            drawKeyboardLayout();
            break;
        case 4:
            drawCredits();
            break;
        case 5:
            drawGame();
            break;
        }

        DrawFPS(25, 25);
        EndDrawing();
    }

    UnloadTexture(mainMenuBackgroundImage);
    UnloadMusicStream(backgroundMusic);

    CloseWindow();
    return 0;
}
