cmake_minimum_required(VERSION 3.13)

project(Compromised)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS window graphics audio system REQUIRED)

set(HEADER_FILES include/Game.h include/Settings.h include/Scene.h include/SceneManager.h 
    include/SplashScreen.h include/AssetManager.h)
set(SOURCES src/Main.cpp src/Game.cpp src/Settings.cpp src/SceneManager.cpp src/Scene.cpp 
    src/SplashScreen.cpp src/AssetManager.cpp)
include_directories(include)

add_executable(Compromised ${SOURCES} ${HEADER_FILES})

target_link_libraries(Compromised sfml-graphics sfml-audio sfml-window sfml-system GL)
