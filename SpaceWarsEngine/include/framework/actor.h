#pragma once

namespace sw 
{
    class World;
    class Actor
    {
    public:
        Actor(World* owning_world);
        virtual ~Actor();
        void begin_play_internal();
        virtual void begin_play();
        virtual void tick(float delta_time);

    private:
        World* m_owning_world;
        bool m_begin_play;
    };
    
}