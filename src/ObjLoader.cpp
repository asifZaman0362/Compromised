#include <stdlib.h>
#include "ObjLoader.h"
#include "StringUtils.h"

using namespace std;

bool ObjLoader::LoadModel(string filename, GLfloat* verts, GLfloat* normals, GLfloat* uvs)
{
    vector<sf::Vector3f> temp_verts;
    vector<sf::Vector3f> temp_normals;
    vector<sf::Vector2f> temp_uvs;
    vector<int> vert_indices;
    vector<int> uv_indices;
    vector<int> normal_indices;

    ifstream objFile(filename);
    if (!objFile) return false;
    char* line = new char[180];
    while (!objFile.eof())
    {
        objFile.getline(line, 180);
        vector<string> tokens = StringUtils::SplitString(line, ' ');
        
        if (tokens[0] == "v")
            temp_verts.push_back(sf::Vector3f(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
        else if (tokens[0] == "vt")
            temp_uvs.push_back(sf::Vector2f(stof(tokens[1]), stof(tokens[2])));
        else if (tokens[0] == "vn")
            temp_normals.push_back(sf::Vector3f(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
        else if (tokens[0] == "f")
        {
            for (int i = 1; i <= 3; i++)
            {
                vector<string> indices = StringUtils::SplitString(tokens[i].c_str(), '/');
                vert_indices.push_back(stoi(indices[0]));
                uv_indices.push_back(stoi(indices[1]));
                normal_indices.push_back(stoi(indices[2]));
            }
        }
    }
    
    const int vert_array_size = vert_indices.size() * 3;
    const int uv_array_size = uv_indices.size() * 2;
    const int normal_array_size = normal_indices.size() * 3;

    verts = new GLfloat[vert_array_size];
    uvs = new GLfloat[uv_array_size];
    normals = new GLfloat[normal_array_size];

    int iter = 0;
    for (int i : vert_indices)
    {
        verts[iter++] = temp_verts[i-1].x;
        verts[iter++] = temp_verts[i-1].y;
        verts[iter++] = temp_verts[i-1].z;
    }
    iter = 0;
    for (int i : uv_indices)
    {
        uvs[iter++] = temp_uvs[i-1].x;
        uvs[iter++] = temp_uvs[i-1].y;
    }
    iter = 0;
    for (int i : normal_indices)
    {
        normals[iter++] = temp_normals[i-1].x;
        normals[iter++] = temp_normals[i-1].y;
        normals[iter++] = temp_normals[i-1].z;
    }

    temp_normals.clear();
    temp_verts.clear();
    temp_uvs.clear();
    uv_indices.clear();
    normal_indices.clear();
    vert_indices.clear();

    return true;
}