#include <iostream>

#include "framework/application.h"

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
                Tick(TargetDeltaTime);
                Render();
            }
        }
    }

    void Application::Tick(float DeltaTime)
    {
        std::cout << "Tick rate: " << 1.f/DeltaTime << std::endl;
    }
    
    void Application::Render()
    {

    }
} 
