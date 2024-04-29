#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void Open();
    void Close();

private:
    std::string m_title;
    int m_width;
    int m_height;
    bool m_isOpen;
    SDL_Window* m_window;
};

#endif // WINDOW_H
