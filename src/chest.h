#ifndef chest_h
#define chest_h

#include <SFML/Graphics.hpp>
#include "baseItem.h"
#include "enviormentBlocks.h"
#include "healthIncreaseItem.h"
#include "damageIncreaseItem.h"
#include "healthDecreaseItem.h"
#include <memory>

class chest : public enviormentBlocks {

    public:
        /*
          NAME:
            chest

          SYNOPSIS:
            chest::chest(int a_x, int a_y);
            a_x -> sets the x position of the envriorment block
            a_y sets the y position of the enviorment block

         DESCRIPTION:
           initlizes a chest block to loaded into the correpsonding room.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        chest(int a_x, int a_y);

        /*
          NAME:
           GetItemStored

          SYNOPSIS:
            std::shared_ptr<baseItem> GetItemStored();

          DESCRIPTION:
            Returns the item that is within the object.
            Item is randomly chosen on initlization.

          RETURNS:
            std::shared_ptr<baseItem>

          AUTHOR:
            Josh Long
        */
        std::shared_ptr<baseItem> & GetItemStored();

        /*
          NAME:
            IsOpened

          SYNOPSIS:
            bool IsOpened();

          DESCRIPTION:
            Checks if the chest has been already opened.

          RETURNS:
            bool m_opened

         AUTHOR:
           Josh Long
        */
        bool IsOpened() { return opened; }

        /*
          NAME:
            SetOpened

          SYNOPSIS:
            void SetOpened();

          DESCRIPTION:
            Flags the m_opened boolean to true so the chest cannot be collected from again.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void SetOpened() { opened = true; }

    private:

        bool opened = false;
        std::shared_ptr<baseItem> m_item = nullptr;
};




#endif
