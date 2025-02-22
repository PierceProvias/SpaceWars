#include "framework/application.h"
#include <stdio.h>
#include "framework/core.h"
#include "framework/world.h"

namespace sw
{
    Application::Application()
        : m_window{sf::VideoMode(1080, 1920), "Space Wars"},
        m_target_framerate{60.f},
        m_tick_clock{},
        m_current_world{nullptr}
    {

    }

    void Application::run()
    {
        m_tick_clock.restart();
        float AccumulatedTime = 0.f;
        float Targetdelta_time = 1.f / m_target_framerate;
        while(m_window.isOpen())
        {
            sf::Event windowEvent;
            while(m_window.pollEvent(windowEvent))
            {
                if(windowEvent.type == sf::Event::EventType::Closed)
                {
                    m_window.close();
                }
            }

            AccumulatedTime += m_tick_clock.restart().asSeconds();
            while(AccumulatedTime)
            {
                AccumulatedTime -= Targetdelta_time;
                tick_internal(Targetdelta_time);
                render_internal();
            }
        }
    }

    void Application::tick_internal(float delta_time)
    {
        tick(delta_time);

        if(m_current_world)
        {
            m_current_world->begin_play_internal();
            m_current_world->tick_internal(delta_time);
        }
    }
    
    void Application::tick(float delta_time)
    {
        LOG("tick rate: %f", 1.f/delta_time);
    }
    
    void Application::render_internal()
    {
        m_window.clear();
        render();
        m_window.display();
    }

    void Application::render()
    {
        sf::RectangleShape rect(sf::Vector2f(1000,1000));
        sf::CircleShape circle{sf::CircleShape{100}};
        rect.setFillColor(sf::Color::Cyan);
        rect.setOrigin(m_window.getSize().x/2, m_window.getSize().y/2);
        rect.setPosition(sf::Vector2f(m_window.getSize().x/2, m_window.getSize().y/2));
        m_window.draw(rect);
        m_window.draw(circle);
    }
} 
