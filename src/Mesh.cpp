#include "Mesh.h"

Mesh::Mesh(GLfloat* verts, GLfloat* normals, GLfloat* texcoords) : 
        verts(verts), normals(normals), texcoords(texcoords)
{
    this->position = sf::Vector3f(0, 0, 0);
    this->scale = sf::Vector3f(0, 0, 0);
    this->rotation = sf::Vector3f(0, 0, 0);
}

Mesh::~Mesh()
{
    delete[] verts;
    delete[] normals;
    delete[] texcoords;
}

void Mesh::Translate(sf::Vector3f delta)
{
    // do translation math
    this->position = position + delta;
}

void Mesh::Rotate(sf::Vector3f rotation)
{
    // do rotation math
    this->rotation = rotation; // Its not supposed to be like this, I know.
}

void Mesh::Scale(sf::Vector3f scale)
{
    // do scaling math
    this->scale.x *= scale.x;
    this->scale.y *= scale.y;
    this->scale.z *= scale.z;
}

void Mesh::SetPostion(sf::Vector3f newPosition)
{
    this->position = newPosition;
}

void Mesh::SetScale(sf::Vector3f newScale)
{
    this->scale = newScale;
}
void Mesh::SetRotation(sf::Vector3f newRotation)
{
    this->rotation = newRotation;
}

sf::Vector3f Mesh::GetPosition()
{
    return this->position;
}

sf::Vector3f Mesh::GetScale()
{
    return this->scale;
}

sf::Vector3f Mesh::GetRotation()
{
    return this->rotation;
}