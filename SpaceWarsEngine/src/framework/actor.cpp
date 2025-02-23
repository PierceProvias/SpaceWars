#include "framework/actor.h"
#include "framework/core.h"

namespace sw
{
    Actor::Actor(World* owning_world)
        : m_owning_world{owning_world},
          m_begin_play{false}
    {

    }
}

void sw::Actor::begin_play_internal()
{
    if(!m_begin_play)
    {
        m_begin_play = true;
        begin_play();
    }
}

void sw::Actor::begin_play()
{
    LOG("Actor begin play");
}

void sw::Actor::tick(float delta_time)
{
    LOG("Actor tick");
}
