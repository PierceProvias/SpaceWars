#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/application.h"

int main()
{
    std::unique_ptr<sw::Application> app = std::make_unique<sw::Application>(); 
    app->Run();
   
}