#include "framework/application.h"
#include <stdio.h>
#include "framework/core.h"

namespace sw
{
    Application::Application()
        : m_Window{sf::VideoMode(1080, 1920), "Space Wars"},
        m_TargetFrameRate{60.f},
        m_TickClock{}
    {

    }

    void Application::Run()
    {
        m_TickClock.restart();
        float AccumulatedTime = 0.f;
        float TargetDeltaTime = 1.f / m_TargetFrameRate;
        while(m_Window.isOpen())
        {
            sf::Event windowEvent;
            while(m_Window.pollEvent(windowEvent))
            {
                if(windowEvent.type == sf::Event::EventType::Closed)
                {
                    m_Window.close();
                }
            }

            AccumulatedTime += m_TickClock.restart().asSeconds();
            while(AccumulatedTime)
            {
                AccumulatedTime -= TargetDeltaTime;
                TickInternal(TargetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::TickInternal(float DeltaTime)
    {
        Tick(DeltaTime);
    }
    
    void Application::Tick(float DeltaTime)
    {
        LOG("Tick rate: %f", 1.f/DeltaTime);
        //printf("Tick rate: %f\n", 1.f/DeltaTime);
    }
    
    void Application::RenderInternal()
    {
        m_Window.clear();
        Render();
        m_Window.display();
    }

    void Application::Render()
    {
        sf::RectangleShape rect(sf::Vector2f(1000,1000));
        sf::CircleShape circle{sf::CircleShape{100}};
        rect.setFillColor(sf::Color::Cyan);
        rect.setOrigin(m_Window.getSize().x/2, m_Window.getSize().y/2);
        rect.setPosition(sf::Vector2f(m_Window.getSize().x/2, m_Window.getSize().y/2));
        m_Window.draw(rect);
        m_Window.draw(circle);
    }
} 
