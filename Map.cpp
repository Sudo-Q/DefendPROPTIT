//
// Created by duonglh on 23/10/2020.
//

#include "Map.h"

Map::Map () {
      this->width=20;
      this->height=16;
}


void Map::setMap (vector<Texture>mapTexture) {
    this->mapTexture=mapTexture;
}

void Map::draw (RenderWindow &window) {
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            map.setTexture(mapTexture[matrixMap[j][i]]);
            map.setScale(2.f,2.f);
            map.setPosition(Vector2f(i,j)*64.f);
            window.draw(map);
        }
    }
}

