#include <iostream>
#include "../include/Window.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

Window::Window(const std::string& title, int width, int height)
    : m_title(title), m_width(width), m_height(height), m_isOpen(false), m_window(nullptr) {}

Window::~Window() {
    Close();
}

void Window::Open() {
    if (!m_isOpen) {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            spdlog::error("SDL initialization failed: {}", SDL_GetError());
            return;
        }

        // Create window
        m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
        if (m_window == nullptr) {
            spdlog::error("Failed to create window: {}", SDL_GetError());
            SDL_Quit();
            return;
        }

        spdlog::info("Window '{}' created successfully.", m_title);
        m_isOpen = true;
    } else {
        spdlog::warn("Window is already open.");
    }
}

void Window::Close() {
    if (m_isOpen) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        spdlog::info("Window '{}' closed.", m_title);
        m_isOpen = false;
    } else {
        spdlog::warn("Window is already closed.");
    }
}
