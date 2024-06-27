#ifndef STORAGE_H
#define STORAGE_H

#include "shapes.h"
#include <string>
#include <vector>
#include <raylib.h>

using std::string;
using std::vector;
using json = nlohmann::json;

class Storage {
    private:
        void shuffle();
        static void checkHold();
        static vector<string> pieceList;
        static vector<string> pieceStream;
    public:
        int score;
        static bool holdAvailable;
        static string hold;
        static string currentType;
        void increaseScore(const string args);
        static vector<Piece> updateStorage();
        static Piece updateCurrent();
        Storage();
};

#endif // STORAGE_H