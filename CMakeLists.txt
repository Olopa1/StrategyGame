cmake_minimum_required(VERSION 3.28)
project(StrategyGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(game_lib
    lib/utils/scenesComponents/Component.cpp
)

target_include_directories(game_lib PUBLIC
    src
    lib/scenesComponents
)

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(game_lib PUBLIC SFML::Graphics)
target_link_libraries(game_lib PUBLIC SFML::Audio)
target_link_libraries(game_lib PUBLIC SFML::Network)
target_link_libraries(main PRIVATE game_lib)
