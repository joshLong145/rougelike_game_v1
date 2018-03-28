
#ifndef rockBlocks_h
#define rockBlocks_h

#include "enviormentBlocks.h"

class rockBlock : public enviormentBlocks{
public:
    /*
      NAME:
        rockBlock

      SYNOPSIS:
        rockBlock::rockBlock(int xpos, int ypos);
        xpos -> x position of the envriomentBlock
        ypos -> y position of the envriormentBlock

      DESCRIPTION:
        Initlizes a rock to be loaded into a room.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    rockBlock(int xpos, int ypos);
};

#endif
