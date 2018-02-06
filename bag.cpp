#include "bag.h"

std::vector<std::shared_ptr<baseItem>> & Bag::getItems(){
    return m_itemStorage;
}
//TODO: change from enum to unique_ptr
void Bag::addItem(std::shared_ptr<baseItem> item){
    if(m_itemStorage.size() < 3){
        m_itemStorage.push_back(item);
    }
}


