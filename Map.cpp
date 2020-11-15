//
// Created by duonglh on 23/10/2020.
//

#include "Map.h"

Map::Map () {
      this->width=20;
      this->height=16;
}

void Map::setMap (vector<Texture>&_mapTexture) {
    this->mapTexture=_mapTexture;
}

void Map::draw (RenderWindow &window) {
    for(short i=0;i<width;i++){
        for(short j=0;j<height;j++){
            map.setTexture(mapTexture[matrixMap[j][i]]);
            map.setScale(2.f,2.f);
            map.setPosition(Vector2f(i*64.f+30,j*64.f+30));
            window.draw(map);
        }
    }
}

int Map::getNumberMap (short i, short j) {
    return matrixMap[i][j];
}

