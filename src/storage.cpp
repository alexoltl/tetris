#include "storage.h"
#include "shapes.h"
#include "globals.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

vector<string> Storage::pieceList;
vector<string> Storage::pieceStream;
bool Storage::holdAvailable = false;
string Storage::hold = "";

Storage::Storage() {
    score = 0;
    holdAvailable = true;

    std::ifstream file(filename);
    json j;
    file >> j;

    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        pieceList.push_back(it.key());
    }
    shuffle();
}

void Storage::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(pieceList.begin(), pieceList.end(), g);

    for (string k : pieceList) {
        pieceStream.push_back(k);
    }
}

void Storage::checkHold() {
    string type = current.type;
    if (IsKeyPressed(KEY_C)) {
        if (hold.empty()) {
            hold = type;
        } else {
            if (holdAvailable) std::swap(hold, type);
        }
    }
}

vector<Piece> Storage::updateStorage() {
    checkHold();
    vector<Piece> newPieces;
    currentType = pieceStream[0];
    current.type = currentType;
    for (int i = 0; i < 3; i++)
    {
        Piece preview(pieceStream[1 + i], previewSize, seperation * 2 + tileSize * 12 - previewSize * 2, seperation * 2 + tileSize * 6 + seperation * i * 5 - previewSize);
        newPieces.push_back(preview);
    }
    if (!hold.empty()) {
        Piece holdPiece(hold, previewSize, seperation * 2 + tileSize * 12 - previewSize * 2, seperation + tileSize * 2 - previewSize);
        newPieces.push_back(holdPiece);
    }
    return newPieces;
}

Piece Storage::updateCurrent() {
    Piece nextPiece(currentType, tileSize, current.xPos, current.yPos);
    return nextPiece;
}