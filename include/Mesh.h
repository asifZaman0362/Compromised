#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Mesh {
public:
    Mesh(GLfloat*, GLfloat*, GLfloat*, int);
    ~Mesh();

    void Translate(sf::Vector3f);
    void Rotate(sf::Vector3f);
    void Scale(sf::Vector3f);
    void SetPostion(sf::Vector3f);
    void SetScale(sf::Vector3f);
    void SetRotation(sf::Vector3f);
    sf::Vector3f GetPosition();
    sf::Vector3f GetScale();
    sf::Vector3f GetRotation();
    int GetVertexCount();

//private:
    sf::Vector3f position;
    sf::Vector3f rotation;
    sf::Vector3f scale;
    GLfloat* verts;
    GLfloat* normals;
    GLfloat* texcoords;
    int vertexCount;
};