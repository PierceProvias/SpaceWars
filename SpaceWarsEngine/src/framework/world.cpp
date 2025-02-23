#include "framework/world.h"
#include "framework/actor.h"

namespace sw
{
    World::World(Application* owning_app) 
        : m_owning_app{owning_app},
        m_begin_play{false},
        m_PendingActors{},
        m_Actors{}
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
        for(const shared<Actor>& Actor : m_PendingActors)
        {
            m_Actors.push_back(Actor);
            Actor->begin_play_internal();
        }
        
        m_PendingActors.clear();

        for(const shared<Actor>& Actor : m_Actors)
        {
            Actor->tick(delta_time);
        }

        tick(delta_time);
    }

    void World::begin_play()
    {

    }

    void World::tick(float delta_time)
    {

    }
}