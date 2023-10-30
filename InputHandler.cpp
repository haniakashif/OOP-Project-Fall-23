#include "InputHandler.h"
InputHandler *InputHandler::s_pInstance = nullptr;
bool InputHandler::keyDown(SDL_Scancode scanCode)
{
    return mKeyBoardStates[scanCode];
}

void InputHandler::update()
{
    mKeyBoardStates = SDL_GetKeyboardState(NULL);
}
