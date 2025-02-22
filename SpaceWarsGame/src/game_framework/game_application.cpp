#include "game_framework/game_application.h"
#include "framework/world.h"

sw::Application* get_application()
{
    return new sw::GameApplication{};
}

namespace sw
{
    GameApplication::GameApplication()
    {
        load_world<World>();
    }
}