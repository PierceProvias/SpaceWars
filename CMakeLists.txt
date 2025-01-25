cmake_minimum_required(VERSION 3.28.3)

project(SpaceWars
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

include(FetchContent)
set(SMFL_LIB_NAME SFML)

FetchContent_Declare(
    ${SMFL_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.6.2
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SMFL_LIB_NAME})

set(SPACE_WARS_GAME_TARGET_NAME SpaceWarsGame)
add_subdirectory(SpaceWars)
