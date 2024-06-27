#ifndef PUBLIC_H
#define PUBLIC_H

#include <raylib.h>
#include <vector>

using std::vector;

class Areas {
    private:
        Rectangle mainArea;
        Rectangle holdArea;
        Rectangle nextPieces;
    public:
        vector<Rectangle> areas;
        Areas();
};

#endif // PUBLIC_H