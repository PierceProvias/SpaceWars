#pragma once

#include <SFML/Graphics.hpp> //external pre processor directives
#include "framework/core.h"

namespace sw
{
    class World;
    class Application
    {
    public:
        Application();
        void Run();

        template<typename world_type>
        weak<world_type> load_world();

    private:
        void TickInternal(float DeltaTime);
        virtual void Tick(float DeltaTime);
        // Template function
        void RenderInternal();
        virtual void Render();
        
        sf::RenderWindow m_Window;
        float m_TargetFrameRate;
        sf::Clock m_TickClock;

        shared<World> m_current_world;
    };

    template<typename world_type>
    weak<world_type> Application::load_world()
    {
        shared<world_type> new_world{new world_type{this}};
        m_current_world = new_world;
        return new_world;
    }
}