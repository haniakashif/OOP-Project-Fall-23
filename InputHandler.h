#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"

class InputHandler
{
public:
    static InputHandler *Instance();

    bool keyDown(SDL_Scancode scanCode);
    void update();

    void clean() {}
    bool keyUp(SDL_Scancode scanCode);

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