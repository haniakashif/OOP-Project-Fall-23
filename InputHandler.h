#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"

class InputHandler
{
public:
    static InputHandler *Instance()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    bool keyDown(SDL_Scancode scanCode);
    void update();

    void clean() {}

private:
    InputHandler()
    {
    }
    ~InputHandler() {}
    static InputHandler *s_pInstance;

    const Uint8 *mKeyBoardStates;
};
typedef InputHandler TheInputHandler;
#endif