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
        void TickInternal(float DeltaTime);
        virtual void Tick(float DeltaTime);
        // Template function
        void RenderInternal();
        virtual void Render();
        sf::RenderWindow m_Window;
        float m_TargetFrameRate;
        sf::Clock m_TickClock;
    };
}