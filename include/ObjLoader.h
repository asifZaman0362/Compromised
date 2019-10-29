#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class ObjLoader
{
public:
    ObjLoader() = default;
    ~ObjLoader();

    /// Load an obj model from a file.
    static bool LoadModel(std::string, GLfloat*, GLfloat*, GLfloat*);
};