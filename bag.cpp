#include "bag.h"

std::vector<std::shared_ptr<baseItem>> & Bag::getItems(){
    return m_itemStorage;
}

void Bag::addItem(baseItem::items item){
    if(m_itemStorage.size() < 3){
        if(item == baseItem::items::healthIncrease){
            m_itemStorage.push_back(std::make_unique<healthIncreaseItem>());
        }else if (item == baseItem::items::damageIncrease){

        }
    }
}


