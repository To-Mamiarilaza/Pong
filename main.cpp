#include <iostream>
#include <raylib.h>

using namespace std;

class Ball {
    public:
    float x, y;
    int speedX, speedY;
    int radius;

    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update() {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y <= 0) speedY *= -1;
        if (x + radius >= GetScreenWidth() || x <= 0) speedX *= -1;
        
    }
};

class Paddle {
    public:
    float x, y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update() {
        if (IsKeyDown(KEY_UP)) y += -speed;
        if (IsKeyDown(KEY_DOWN)) y += speed;

        if (y <= 0) y = 0;
        if (y + height >= GetScreenHeight()) y = GetScreenHeight() - height;
    }
};

int main()
{
    cout << "Starting the game" << endl;

    const int screenWidth = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Game !");
    SetTargetFPS(60);

    // Init the ball
    Ball ball;
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    // Init the player
    Paddle player;
    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating
        ball.Update();
        player.Update();

        // Drawing
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

        ball.Draw();
        player.Draw();
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
