#ifndef quadTree_h
#define quadTree_h

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class quadTree final{
 public:

  quadTree(int a_plevel, const sf::FloatRect &a_pBounds){
    m_level = a_plevel;
    m_bounds = a_pBounds;
  }
 
  /**
     NAME:
       Clear

     SYNOPSIS:
       void clear();

     DESCRIPTION:

     RETURNS:
       void

     AUTHOR:
       Josh Long

  */
  void Clear();

  void Insert(sf::FloatRect a_pRect);

  std::vector<sf::FloatRect> Retrieve(std::vector<sf::FloatRect> &a_returnObjects, sf::FloatRect a_pRect);
 private:

  void Split();


  int GetIndex(sf::FloatRect &pRect);

  // MEMBER VARIABLES
  int m_max_objects = 10;
  int m_max_levels = 5;
  int m_level;
  sf::FloatRect m_bounds;
  std::shared_ptr<quadTree> m_nodes[4];
  std::vector<sf::FloatRect> m_objects;

};

#endif
