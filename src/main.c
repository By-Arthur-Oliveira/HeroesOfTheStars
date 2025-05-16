#include "raylib.h"
#include "resource_dir.h"

int optionController = 0;
int selectorPositionY = 380;

void drawMainMenu()
{
    Sound selectSoundEffect = LoadSound("resources/MenuAssets/startgamesound.mp3");
    Texture2D selectorTexture = LoadTexture("resources/MenuAssets/selector.png");

    if (IsKeyPressed(KEY_DOWN) && selectorPositionY >= 380 && selectorPositionY < 530)
    {
        selectorPositionY += 50;
    }

    if (IsKeyPressed(KEY_UP) && selectorPositionY > 380 && selectorPositionY <= 530)
    {
        selectorPositionY -= 50;
    }

    if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 380))
    {
        UnloadTexture(selectorTexture);
        PlaySound(selectSoundEffect);
        optionController = 1;
        selectorPositionY = 380;
    }

    if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 430))
    {
        UnloadTexture(selectorTexture);
        PlaySound(selectSoundEffect);
        optionController = 2;
        selectorPositionY = 430;
    }

    if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 480))
    {
        UnloadTexture(selectorTexture);
        PlaySound(selectSoundEffect);
        optionController = 3;
        selectorPositionY = 480;
    }

    if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 530))
    {
        UnloadTexture(selectorTexture);
        PlaySound(selectSoundEffect);
        optionController = 0;
        CloseWindow();
    }

    DrawTexture(selectorTexture, 100, selectorPositionY, WHITE);
    DrawText("HEROES OF THE STARS", GetScreenWidth() / 2 - 479, 30, 75, WHITE);
    DrawText("NEW GAME", 140, 375, 35, WHITE);
    DrawText("LEADERBOARD", 140, 425, 35, WHITE);
    DrawText("KEYBOARD LAYOUT", 140, 475, 35, WHITE);
    DrawText("EXIT GAME", 140, 525, 35, WHITE);
    ClearBackground(BLACK);
}

void drawNewGame()
{
    if (IsKeyPressed(KEY_ESCAPE))

    {
        optionController = 0;
    }

    DrawText("HEROES OF THE STARS", GetScreenWidth() / 2 - 479, 30, 75, WHITE);
    DrawText("NEW GAME", GetScreenWidth() / 2 - 120, 350, 45, WHITE);
    ClearBackground(BLACK);
}

void drawLeaderboard()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        optionController = 0;
    }

    DrawText("HEROES OF THE STARS", GetScreenWidth() / 2 - 479, 30, 75, WHITE);
    DrawText("LEADERBOARD", GetScreenWidth() / 2 - 170, 350, 45, WHITE);
    ClearBackground(BLACK);
}

void drawKeyboardLayout()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        optionController = 0;
    }
    
    DrawText("HEROES OF THE STARS", GetScreenWidth() / 2 - 479, 30, 75, WHITE);
    DrawText("KEYBOARD LAYOYT", GetScreenWidth() / 2 - 215, 350, 45, WHITE);
    ClearBackground(BLACK);
}

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
        }

        DrawFPS(25, 25);
        EndDrawing();
    }

    UnloadTexture(mainMenuBackgroundImage);
    UnloadMusicStream(backgroundMusic);

    CloseWindow();
    return 0;
}
