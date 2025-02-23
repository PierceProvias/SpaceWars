#include "game_framework/game_application.h"
#include "framework/world.h"
#include "framework/actor.h"

sw::Application* get_application()
{
    return new sw::GameApplication{};
}

namespace sw
{
    GameApplication::GameApplication()
    {
        weak<World> NewWorld = load_world<World>();
        NewWorld.lock()->SpawnActor<Actor>();
    }
}