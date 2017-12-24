
#ifndef gameObjectState_h
#define gameObjectState_h

class gameObjectState{
    public:
        gameObjectState() = default;
        virtual ~gameObjectState() = default;
        virtual void update() = 0;
        virtual bool nextPanel() = 0;
    protected:
        bool next = false;
};

#endif
