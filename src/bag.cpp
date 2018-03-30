#include "bag.h"

std::vector<std::shared_ptr<baseItem>> & Bag::GetItems(){
    return m_itemStorage;
}
//TODO: change from enum to unique_ptr
void Bag::AddItem(std::shared_ptr<baseItem> item){
    if(m_itemStorage.size() < 3){
        m_itemStorage.push_back(item);
    }
}


