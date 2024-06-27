#include "shapes.h"
#include "globals.h"
#include <fstream>
#include <algorithm>

int step = 0;
int stepNext = 2;

Piece::Piece(const string& t, const float& size, const float& x, const float& y) {
    type = t;
    xPos = x;
    yPos = y;
    std::ifstream file(filename);
    json j;
    file >> j;

    currentShape = j[type]["shape"];
    colorName = j[type]["color"];

    for (size_t i = 0; i < currentShape.size(); i++)
    {
        for (size_t j = 0; j < currentShape[i].size(); j++)
        {
            if (currentShape[i][j] == 1) {
                Rectangle currentTile = { x + i * size, y + j * size, size, size };
                shape.push_back(currentTile);
            }
        }
    }
    
    color = {0, 0, 0, 255};

    if (colorName == "YELLOW") color = YELLOW;
    else if (colorName == "BLUE") color = BLUE;
    else if (colorName == "RED") color = RED;
    else if (colorName == "GREEN") color = GREEN;
    else if (colorName == "ORANGE") color = ORANGE;
    else if (colorName == "DARKBLUE") color = DARKBLUE;
    else if (colorName == "PURPLE") color = PURPLE;
}

string Piece::restrainBounds(const vector<Rectangle>& blocks) {
    vector<float> blockX;
    for (const Rectangle& i : blocks) {
        blockX.push_back(i.x);
    }

    auto max_it = max_element(blockX.begin(), blockX.end());
    auto min_it = min_element(blockX.begin(), blockX.end());

    if (*max_it >= seperation + tileSize * 9) return "right";
    else if (*min_it <= seperation + 1) return "left";
    else if (*min_it >= seperation + 1 && *max_it <= seperation + tileSize * 9) return "none";
    return "b";
}

void Piece::Movement(vector<Rectangle>& blocks) {
    string bounds = restrainBounds(blocks);

    step+=1;
    if (step >= stepNext) {
        if (IsKeyDown(KEY_LEFT) && bounds != "left") {
            for (Rectangle& i : blocks) {
                i.x -= tileSize;
            }
            step = 0;
        } else if (IsKeyDown(KEY_RIGHT) && bounds != "right") {
            for (Rectangle& i : blocks) {
                i.x += tileSize;
            }
            step = 0;
        }
    }
}