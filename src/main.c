#include "raylib.h"
#include "resource_dir.h"
#include "game.h"

bool repeatLoop = true;
int optionController = 0;
int selectorPositionY = 380;

void drawMainMenu(Sound sound)
{
    Texture2D selectorTexture = LoadTexture("resources/MenuAssets/selector.png");

    if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && selectorPositionY >= 380 && selectorPositionY < 580)
    {
        selectorPositionY += 50;
    }
    else if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && selectorPositionY > 380 && selectorPositionY <= 580)
    {
        selectorPositionY -= 50;
    }

    if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 380))
    {
        PlaySound(sound);
        UnloadTexture(selectorTexture);
        optionController = 1; // NEW GAME
        selectorPositionY = 380;
    }
    else if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 430))
    {
        PlaySound(sound);
        UnloadTexture(selectorTexture);
        optionController = 2; // LEADERBOARD
        selectorPositionY = 430;
    }
    else if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 480))
    {
        PlaySound(sound);
        UnloadTexture(selectorTexture);
        optionController = 3; // KEYBOARD LAYOUT
        selectorPositionY = 480;
    }
    else if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 530))
    {
        PlaySound(sound);
        UnloadTexture(selectorTexture);
        optionController = 4; // CREDITS
        selectorPositionY = 530;
    }
    else if (IsKeyPressed(KEY_ENTER) && (selectorPositionY == 580))
    {
        PlaySound(sound);
        CloseWindow();
        repeatLoop = false; // EXIT GAME
        UnloadTexture(selectorTexture);
    }
    if (selectorPositionY == 380)
    {
        DrawText("NEW GAME", 140, 375, 35, GOLD);
        DrawText("LEADERBOARD", 140, 425, 35, WHITE);
        DrawText("KEYBOARD LAYOUT", 140, 475, 35, WHITE);
        DrawText("CREDITS", 140, 525, 35, WHITE);
        DrawText("EXIT GAME", 140, 575, 35, WHITE);
    }
    else if (selectorPositionY == 430)
    {
        DrawText("NEW GAME", 140, 375, 35, WHITE);
        DrawText("LEADERBOARD", 140, 425, 35, GOLD);
        DrawText("KEYBOARD LAYOUT", 140, 475, 35, WHITE);
        DrawText("CREDITS", 140, 525, 35, WHITE);
        DrawText("EXIT GAME", 140, 575, 35, WHITE);
    }
    else if (selectorPositionY == 480)
    {
        DrawText("NEW GAME", 140, 375, 35, WHITE);
        DrawText("LEADERBOARD", 140, 425, 35, WHITE);
        DrawText("KEYBOARD LAYOUT", 140, 475, 35, GOLD);
        DrawText("CREDITS", 140, 525, 35, WHITE);
        DrawText("EXIT GAME", 140, 575, 35, WHITE);
    }
    else if (selectorPositionY == 530)
    {
        DrawText("NEW GAME", 140, 375, 35, WHITE);
        DrawText("LEADERBOARD", 140, 425, 35, WHITE);
        DrawText("KEYBOARD LAYOUT", 140, 475, 35, WHITE);
        DrawText("CREDITS", 140, 525, 35, GOLD);
        DrawText("EXIT GAME", 140, 575, 35, WHITE);
    }
    else if (selectorPositionY == 580)
    {
        DrawText("NEW GAME", 140, 375, 35, WHITE);
        DrawText("LEADERBOARD", 140, 425, 35, WHITE);
        DrawText("KEYBOARD LAYOUT", 140, 475, 35, WHITE);
        DrawText("CREDITS", 140, 525, 35, WHITE);
        DrawText("EXIT GAME", 140, 575, 35, GOLD);
    }

    DrawTexture(selectorTexture, 100, selectorPositionY, WHITE);
    ClearBackground(BLACK);
}

void drawNewGame()
{
    if (IsKeyPressed(KEY_ESCAPE))

    {
        optionController = 0;
    }

    DrawText("NEW GAME", GetScreenWidth() / 2 - 120, 350, 45, WHITE);
    ClearBackground(BLACK);
}

void drawLeaderboard()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        optionController = 0;
    }

    DrawText("LEADERBOARD", GetScreenWidth() / 2 - 170, 350, 45, WHITE);
    ClearBackground(BLACK);
}

void drawKeyboardLayout()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        optionController = 0;
    }

    DrawText("KEYBOARD LAYOYT", GetScreenWidth() / 2 - 215, 350, 45, WHITE);
    ClearBackground(BLACK);
}

void drawCredits()
{
    if (IsKeyPressed(KEY_ESCAPE))

    {
        optionController = 0;
    }
    DrawText("CREDITS", GetScreenWidth() / 2 - 145, 45, 65, WHITE);
    DrawText("This game was developed by Computer Science students from the\nUniversidade do Estado do Rio Grande do Norte (UERN)\n\n Arthur Oliveira: [https://github.com/By-Arthur-Oliveira]\n\n Pedro Ricardo: [https://github.com]\n\n Francisco Genyson: [https://github.com/Extremois]\n\n\nWe hope you have fun and make the most of the experience!", 50, GetScreenHeight() / 2 - 200, 40, GOLD);
    ClearBackground(BLACK);
}

int main()
{ // Configuração da janela
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "HEROES OF THE STARS");
    InitAudioDevice();
    SetExitKey(KEY_NULL);
    DisableCursor();

    Texture2D mainMenuBackgroundImage = LoadTexture("resources/MenuAssets/background.jpg");

    Music backgroundMusic = LoadMusicStream("resources/MenuAssets/musictheme.mp3");
    PlayMusicStream(backgroundMusic);
    Sound selectSoundEffect = LoadSound("resources/MenuAssets/startgamesound.mp3");

    while (repeatLoop)
    {
        UpdateMusicStream(backgroundMusic);

        if (IsKeyPressed(KEY_M))
        {
            PauseMusicStream(backgroundMusic);
        }
        else if (IsKeyPressed(KEY_P))
        {
            ResumeMusicStream(backgroundMusic);
        }

        BeginDrawing();
        DrawTexture(mainMenuBackgroundImage, 0, 0, WHITE);

        switch (optionController)
        {
        case 0:
            drawMainMenu(selectSoundEffect);
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
            drawingGame();
            break;
        }

        DrawFPS(25, 25);
        EndDrawing();
    }

    UnloadTexture(mainMenuBackgroundImage);
    UnloadMusicStream(backgroundMusic);
    UnloadSound(selectSoundEffect);
    CloseWindow();
    return 0;
}