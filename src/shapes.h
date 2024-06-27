#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <raylib.h>

using std::string;
using std::vector;
using json = nlohmann::json;

class Piece {
    private:
        vector<vector<int>> currentShape;
        string colorName;
        static string restrainBounds(const vector<Rectangle>& blocks);
    public:
        string type;
        vector<Rectangle> shape;
        Color color;
        float xPos;
        float yPos;

        Piece(const string& t, const float& size, const float& x, const float& y);
        static void Movement(vector<Rectangle>& blocks);
};

#endif // SHAPES_H