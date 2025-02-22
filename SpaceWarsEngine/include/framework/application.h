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
        void run();

        template<typename world_type>
        weak<world_type> load_world();

    private:
        void tick_internal(float delta_time);
        virtual void tick(float delta_time);
        // Template function
        void render_internal();
        virtual void render();
        
        sf::RenderWindow m_window;
        float m_target_framerate;
        sf::Clock m_tick_clock;

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