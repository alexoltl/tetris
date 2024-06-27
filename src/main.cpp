#include <iostream>
#include <raylib.h>
#include <string>
#include "globals.h"
#include "areas.h"
#include "shapes.h"
#include "storage.h"

using namespace std;

const int screenWidth = 600;
const int screenHeight = 530;
const float tileSize = 24.0f;
const float previewSize = tileSize / 2;
const float seperation = 25.0f;
const string filename = "C:/Users/Alex/Documents/coding/cpp/tetris2/src/shapes.json";


int main () {
    InitWindow(screenWidth, screenHeight, "tetra");
    SetTargetFPS(60);
    Areas playArea;
    Storage localStorage;
    Piece current(localStorage.currentType, tileSize, 25 + tileSize * 5 + 1, 25);

    while (WindowShouldClose() == false){
        Piece::Movement(current.shape);
        vector<Piece> currentPieces = localStorage.updateStorage();
        current = Storage::updateCurrent();
        currentPieces.push_back(current);

        BeginDrawing();
            ClearBackground(BLACK);
            for (Rectangle i : playArea.areas)
            {
                DrawRectangleLinesEx(i, 1, WHITE);
            }
            for (Piece i : currentPieces)
            {
                for (Rectangle j : i.shape)
                {
                    DrawRectanglePro(j, {0,0}, 0, i.color);
                }
            }
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}