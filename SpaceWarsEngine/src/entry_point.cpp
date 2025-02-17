#include "entry_point.h"
#include "framework/application.h"

int main()
{
     sw::Application* app = GetApplication();
     app->Run();
     delete app;    
}