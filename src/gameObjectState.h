
#ifndef gameObjectState_h
#define gameObjectState_h

#include <SFML/Graphics.hpp>

class gameObjectState{
 public:
  /**
     NAME:
       gameObjectState

     SYNOPSIS:
       gameObjectState() = default;

     DESCRIPTION:
       Default constructor for all objects of the class.

     RETURNS:
       None

     AUTHOR:
       Josh Long
  */
  gameObjectState() = default;

  /**
     NAME:
       gameObjectState

     SYNOPSIS:
       virtual ~gameObjectState() = default;

     DESCRIPTION:
       Default destructor for all gameObjectState objects.

     RETURNS:
       None

     AUTHOR:
       Josh Long
  */
  virtual ~gameObjectState() = default;

  /**
     NAME:
       UpdateStates

     SYNOPSIS:
       virtual void UpdateStates();

     DESCRIPTION:
       Virtual function for updating assets within the scope of the class.
       changes from state to state depending on its needs.

     RETURNS:
       void

     AUTHOR:
       Josh Long
  */
  virtual void UpdateState() = 0;

  /**
     NAME:
       NextPanel

     SYNOPSIS:
       virtual bool NextPanel();

     DESCRIPTION:
       Checks if it is time to move to the next panel.

     RETURNS:
       bool -> true if it is time to move to next panel in queue, false if not.

     AUTHOR:
       Josh Long
  */
  virtual bool NextPanel() = 0;

  /**
     NAME:
       Init

     SYNOPSIS:
       bool Init();

     DESCRIPTION:
       Sets the isInitilized member variable to true.

     RETURNS:
       bool

     AUTHOR:
       Josh Long
  */
  bool Init() { return m_isInitilized = true; }

  /**
     NAME:
       IsInit

     SYNOPSIS:
       bool IsInit();

     DESCRIPTION:
       Checks if state needs to be initlized.

     RETURNS:
       bool

     AUTHOR:
       Josh Long
  */
  bool IsInit() { return m_isInitilized; }

  /**
     NAME:
      SetNext

     SYNOPSIS
       void SetNext(bool a_nextState);
                    bool a_nextState -> new value for m_next;
     DESCRIPTION:
       Sets the m_next variable to move to the next state.

     RETURNS:
       void

     AUTHOR:
       Josh Long
  */
  void SetNext(const bool a_nextState) { m_next = a_nextState; }

 protected:
  bool m_next = false;
  sf::Time m_delta;
  bool m_isInitilized = false;
};

#endif
