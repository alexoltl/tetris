#include "areas.h"
#include "globals.h"

Areas::Areas() {
    // main area is 10*20 tilesizes
    mainArea = { seperation, seperation, tileSize * 10 + 2, tileSize * 20 + 2 };
    
    // hold area is 4*4 tilesizes placed next to the mainarea
    holdArea = { mainArea.x + mainArea.width + seperation, seperation, tileSize * 4, tileSize * 4 };
    
    // nextpieces is under holdarea filling rest.
    nextPieces = { holdArea.x, holdArea.y + holdArea.height + seperation, tileSize * 4, tileSize * 20 + 2 - (seperation * 3 + tileSize * 2) };
    
    // width: tilesize * 14 + seperation * 3 = 411 best width
    // height: tilesize * 20 + seperation * 2 = 530 best width
    // only changed width

    areas.push_back(mainArea);
    areas.push_back(holdArea);
    areas.push_back(nextPieces);
}
