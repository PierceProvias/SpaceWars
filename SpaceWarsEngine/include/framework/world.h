#pragma once

namespace sw
{
    class Application;
    
    class World
    {
    public:
        World(Application* owning_app);
        virtual ~World();

        void begin_play_internal();
        void tick_internal(float delta_time);

        
    private:
        void begin_play();
        void tick(float delta_time);    
        Application* m_owning_app;
        bool m_begin_play;
    };
}