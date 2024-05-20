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

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating
        ball.Update();

        // Drawing
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        ball.Draw();
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
