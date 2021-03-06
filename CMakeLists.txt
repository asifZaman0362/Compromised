cmake_minimum_required(VERSION 3.10)

project(Compromised)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS window graphics audio system REQUIRED)

include_directories(include)
set(HEADER_FILES include/Game.hpp include/Settings.hpp include/Scene.hpp include/SceneManager.hpp 
    include/SplashScreen.hpp include/AssetManager.hpp include/StringUtils.hpp include/Mesh.hpp 
    include/UiUtils.hpp include/ApplicationStats.hpp)
set(SOURCES src/Main.cpp src/Game.cpp src/Settings.cpp src/SceneManager.cpp src/Scene.cpp 
    src/SplashScreen.cpp src/StringUtils.cpp src/AssetManager.cpp src/Mesh.cpp src/ApplicationStats.cpp)

add_executable(Compromised ${SOURCES} ${HEADER_FILES})

target_link_libraries(Compromised sfml-graphics sfml-audio sfml-window sfml-system GL)
