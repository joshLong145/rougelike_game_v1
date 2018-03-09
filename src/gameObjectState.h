
#ifndef gameObjectState_h
#define gameObjectState_h

#include <SFML/Graphics.hpp>

class gameObjectState{
 public:
  gameObjectState() = default;
  virtual ~gameObjectState() = default;
  virtual void update() = 0;
  virtual bool nextPanel() = 0;
  bool init() { return isInitilized = true; }
  bool isInit() { return isInitilized; }
  void setNext(bool nextState) { next = nextState; }
 protected:
  bool next = false;
  sf::Time delta;
  bool isInitilized = false;
};

#endif
