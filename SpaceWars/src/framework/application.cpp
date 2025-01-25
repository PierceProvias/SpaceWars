#include "framework/application.h"

namespace sw
{
    Application::Application()
        : m_Window{sf::VideoMode(1080, 1920), "Space Wars"}
    {

    }

    void Application::Run()
    {
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
        }
    }
} 
