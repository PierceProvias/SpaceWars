cmake_minimum_required(VERSION 3.28.3)

project(SpaceWars
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

set(SPACE_WARS_GAME_TARGET_NAME SpaceWarsGame)
add_subdirectory(SpaceWars)