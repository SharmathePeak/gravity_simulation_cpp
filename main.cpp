#include<iostream>
#include <raylib.h>
#include "Objects.h"
using namespace std;

int main() {
    InitWindow(600, 600, "Sphere");
    SetTargetFPS(60);

    Object ball1(50, 0, 0, 100, 20, RED);
    Object ball2(-50, 0, 0, 100, 20, BLUE);

    Camera3D camera = { 0 };
    camera.position = Vector3{ 0, 0, 200 };
    camera.target = Vector3{ ball1.x+ball2.x/2, ball1.y + ball2.y / 2, ball1.z + ball2.z / 2 };
    camera.up = Vector3{ 0, 1, 0 };
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_W)) {
            camera.position.z -= 10;
        }
        if (IsKeyDown(KEY_S)) {
            camera.position.z += 10;
        }
        if (IsKeyDown(KEY_A)) {
            camera.position.x += 10;
        }
        if (IsKeyDown(KEY_D)) {
            camera.position.x -= 10;
        }
        if (IsKeyDown(KEY_SPACE)) {
            camera.position.y += 10;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT)) {
            camera.position.y -= 10;
        }
        cout << ball1.distance << endl << "BALL1 : " << ball1.vel_x << "," << ball1.y << "," << ball1.z << endl << "BALL2 : " << ball2.vel_x << "," << ball2.y << "," << ball2.z << endl;

        ball1.movement(ball2);
        ball2.movement(ball1);


        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        ball1.DrawObject();
        ball2.DrawObject();
        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
}