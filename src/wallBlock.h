#ifndef wallBlock_h
#define wallBlock_h

#include "enviormentBlocks.h"
class wallBlock : public enviormentBlocks{
public:

    /**
      NAME:
        wallBlock

      SYNOPSIS:
        wallBlock::wallBlock(int a_xPos, int a_yPos);
        a_xPos -> position on the x axis for the enviorment block
        a_yPos -> position on the y axis for the enviorment block.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    wallBlock(int xpos, int ypos);
 };

#endif /* wallBlock_hpp */
