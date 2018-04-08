#include "rockBlock.h"

rockBlock::rockBlock(int a_xPos, int a_yPos) : enviormentBlocks(a_xPos,a_yPos){
    SetImage("./resources/Blue_rock.png");
    m_groundBlockTexture.loadFromFile("./resources/dirt.png");
}
