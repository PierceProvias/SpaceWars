#pragma once
#include "framework/core.h"

namespace sw
{
    class Application;
    class Actor;
    
    class World
    {
    public:
        World(Application* owning_app);
        virtual ~World();

        void begin_play_internal();
        void tick_internal(float delta_time);

        template<typename ActorType>
        weak<ActorType> SpawnActor();
        
    private:
        void begin_play();
        void tick(float delta_time);    
        Application* m_owning_app;
        bool m_begin_play;

        list<shared<Actor>> m_Actors;
        list<shared<Actor>> m_PendingActors;   // Add new actor to this list and at the end of the tick add them to m_actors list
    };

    template <typename ActorType>
    inline weak<ActorType> World::SpawnActor()
    {
        shared<ActorType> NewActor{new ActorType{this}};
        m_PendingActors.push_back(NewActor);
        return NewActor;
    }
}