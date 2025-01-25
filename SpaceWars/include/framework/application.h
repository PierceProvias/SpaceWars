#pragma once

#include <SFML/Graphics.hpp> //external pre processor directives

namespace sw
{
    class Application
    {
    public:
        Application();
        void Run();
    private:
        sf::RenderWindow m_Window;

    };
}