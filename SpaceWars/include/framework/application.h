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

        void Tick(float DeltaTime);
        void Render();
        sf::RenderWindow m_Window;
        float m_TargetFrameRate;
        sf::Clock m_TickClock;
    };
}