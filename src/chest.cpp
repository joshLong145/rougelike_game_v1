#include "chest.h"
#include <stdlib.h>

chest::chest(int a_x, int a_y) : enviormentBlocks(a_x,a_y){
    SetImage("./resources/chestTile.png");

    int randItem = (rand() % 4) + 1;
    if(randItem == 1){
        m_item = std::make_unique<healthIncreaseItem>();
    }else if(randItem == 2){
        m_item = std::make_unique<damageIncreaseItem>();
    }else if(randItem == 3){
      m_item = std::make_unique<healthDecreaseItem>();
    }else if(randItem == 4){
      m_item = std::make_unique<multiFireItem>();
    }

}

std::shared_ptr<baseItem> & chest::GetItemStored(){
    return m_item;
}
