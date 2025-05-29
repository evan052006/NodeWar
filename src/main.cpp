#include "Vector2.hpp"
#include "raylib.h"
#include <cmath>
#include <cstdlib>
#include <enet/enet.h>
#include <raylib-cpp.hpp>
#include <custom/Animators.hpp>


int main() {
    // Initialization
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Node War");
    Animators::PizzaCircle* circles[100];
    raylib::Color color[5] = {WHITE, BLUE, RED, GREEN, YELLOW};
    for (int i = 0 ; i < 100; i++) {
        circles[i] = new Animators::PizzaCircle(raylib::Vector2(rand() % 800, rand() % 600), std::rand() % 200, color[std::rand() % 5], std::rand() % 360);
    }
    
    SetTargetFPS(60);
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update
        // TODO: Update your variables here
        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < 100; i++) {
          circles[i]->animate((std::rand() % 100) / 10000.0);
          if (circles[i]->getProgress() >= 0.99) {
           circles[i]->setReverse(true);
          }
          if (circles[i]->getProgress() <= 0.01) {
           circles[i]->setReverse(false);
          }
        }
        textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}


