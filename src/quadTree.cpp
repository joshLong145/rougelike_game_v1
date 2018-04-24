#include "quadTree.h"

void quadTree::Clear(){
  m_objects.clear();

  for(int i  = 0; i < 4; i++){
      m_nodes[1] = nullptr;
  }
}

void quadTree::Split(){
  int subWidth = (int)(m_bounds.width / 2);
  int subHeight  = (int)(m_bounds.width / 2);
  int y = (int)m_bounds.top;
  int x = (int)m_bounds.top;
  m_nodes[0] = std::make_unique<quadTree>(m_level + 1, sf::FloatRect(x + subWidth,y,subWidth,subHeight));
  m_nodes[1] = std::make_unique<quadTree>(m_level + 1, sf::FloatRect(x,y,subWidth,subHeight));
  m_nodes[2] = std::make_unique<quadTree>(m_level + 1, sf::FloatRect(x,y + subHeight,subWidth,subHeight));
  m_nodes[3] = std::make_unique<quadTree>(m_level + 1, sf::FloatRect(x + subWidth,y + subHeight,subWidth,subHeight)); 
}


int quadTree::GetIndex(sf::FloatRect &a_pRect){
    int index = -1;
    float vericalMidPoint = m_bounds.left + (m_bounds.width /2);
    float horizontalMidPoint = m_bounds.top + (m_bounds.width /2);

    bool topQuad = (a_pRect.top < horizontalMidPoint && a_pRect.top + a_pRect.height < horizontalMidPoint);
    bool bottomQuad = (a_pRect.top > horizontalMidPoint);
    if(a_pRect.left < vericalMidPoint && a_pRect.left + a_pRect.width < vericalMidPoint){
      if(topQuad){
        index = 1;
      } else if (bottomQuad){
        index = 2;
      }
    }else if(a_pRect.left > vericalMidPoint){
      if(topQuad)
        index = 0;
      else if(bottomQuad)
        index = 3;
    }

    return index;
}

void quadTree::Insert(sf::FloatRect a_pRect){
  if(m_nodes[0] != nullptr){
    int index = GetIndex(a_pRect);

    if(index != -1){
      m_nodes[index]->Insert(a_pRect);

      return;
    }
  }

  m_objects.push_back(a_pRect);

  if(m_objects.size() > m_max_objects && m_level < m_max_levels){
    if(m_nodes[0] == nullptr)
      Split();
  }

  int i = 0;

  while(i < m_objects.size()){
    int index = GetIndex(m_objects[i]);

    if(index != -1){
      auto obj = m_objects.begin() + i;
      m_objects.erase(obj);
      m_nodes[index]->Insert((*obj));
    }else{
      i ++;
    }
  }
}

std::vector<sf::FloatRect> quadTree::Retrieve(std::vector<sf::FloatRect> &a_returnObjects,
                                                             sf::FloatRect a_pRect){
  int index = GetIndex(a_pRect);

  if(index != -1 && m_nodes[0] != nullptr){
    m_nodes[index]->Retrieve(a_returnObjects, a_pRect);
  }

  a_returnObjects = {m_objects};

  return a_returnObjects;
}


