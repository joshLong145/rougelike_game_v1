#ifndef groundBlock_h
#define groundBlock_h

#include "enviormentBlocks.h"

class groundBlock : public enviormentBlocks{
    public:
        /**
          NAME:
            groundBlock

          SYNOPSIS:
            groundBlock::groundBlock(int a_x, int a_y);
            a_x -> Sets the x position of the envriorment block.
            a_y -> Sets the y position of the enviorment block.

          DESCRIPTION:
            Initlizes a ground block a desired x and y position to loaded into a desired room.

          RETURNS:
            None

         AUTHOR:
           Josh Long
        */
        groundBlock(int a_x, int a_y);
};




#endif /* groundBlock_hpp */
