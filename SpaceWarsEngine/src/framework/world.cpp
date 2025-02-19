#include "framework/world.h"

namespace sw
{
    World::World(Application* owning_app) 
        : m_owning_app{owning_app},
        m_begin_play{false}
    {

    }

    World::~World()
    {
    }

    void World::begin_play_internal()
    {
        if(!m_begin_play)
        {
            m_begin_play = true;
            begin_play();
        }
    }

    void World::tick_internal(float delta_time)
    {
        tick(delta_time);
    }

    void World::begin_play()
    {

    }

    void World::tick(float delta_time)
    {

    }
}