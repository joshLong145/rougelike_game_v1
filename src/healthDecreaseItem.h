#ifndef healthDecreaseItem_h
#define healthDecreaseItem_h

#include "baseItem.h"

class healthDecreaseItem : public baseItem{
 public:

  /*

   */
  healthDecreaseItem();

  /*

   */
  ~healthDecreaseItem() = default;

  /*

   */
  int getStatModifier();

  /*

   */
  std::string getItemName();

  /*

   */
  items itemType();

 private:
  int m_stateModifier = 2;

};
#endif
