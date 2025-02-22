#include "entry_point.h"
#include "framework/application.h"

int main()
{
     sw::Application* app = get_application();
     app->run();
     delete app;    
}