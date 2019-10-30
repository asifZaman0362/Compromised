#include "AssetManager.h"
#include "StringUtils.h"

using namespace std;

map<string, sf::Texture*> AssetManager::textures;
map<string, sf::Font*> AssetManager::fonts;
map<string, sf::SoundBuffer*> AssetManager::sounds;
map<string, Mesh*> AssetManager::models;

vector<string> AssetManager::texture_names;
vector<string> AssetManager::font_names;
vector<string> AssetManager::sound_names;
vector<string> AssetManager::model_names;

sf::Texture* AssetManager::LoadTexture(string name)
{
    if (textures[name]!=nullptr) return textures[name];
    else
    {
        sf::Texture* temp = new sf::Texture();
        temp->setSrgb(true);
        if (temp->loadFromFile(TEXTURE_PATH + name + ".jpg"))
        {
            textures[name] = move(temp);
            texture_names.push_back(name);
            return textures[name];
        } else 
        {
            delete temp;
            cerr << "Failed to load texture!" << endl;
            return nullptr;
        }
    }
}

sf::Font* AssetManager::LoadFont(string name)
{
    if (fonts[name]!=nullptr) return fonts[name];
    else
    {
        sf::Font* temp = new sf::Font();
        if (temp->loadFromFile(FONT_PATH + name))
        {
            fonts[name] = move(temp);
            font_names.push_back(name);
            return fonts[name];
        } else
        {
            delete temp;
            cerr << "Failed to load font!" << endl;
            return nullptr;
        }
    }
}

sf::SoundBuffer* AssetManager::LoadAudio(string name)
{
    if (sounds[name]!=nullptr) return sounds[name];
    else
    {
        sf::SoundBuffer* temp = new sf::SoundBuffer();
        if (temp->loadFromFile(AUDIO_PATH + name))
        {
            sounds[name] = move(temp);
            sound_names.push_back(name);
            return sounds[name];
        } else
        {
            cerr << "Failed to load audio clip!" << endl;
            return nullptr;
        }
    }
}

Mesh* AssetManager::LoadModel(string name)
{
    if (models[name]!=nullptr) return models[name];
    
    else
    {
        vector<sf::Vector3f> temp_verts;
        vector<sf::Vector3f> temp_normals;
        vector<sf::Vector2f> temp_uvs;
        vector<int> vert_indices;
        vector<int> uv_indices;
        vector<int> normal_indices;

        ifstream objFile(MODEL_PATH + name + ".obj");
        if (!objFile)
        {
            cerr << "Failed to open file : " << name << ".obj!" << endl;
            return nullptr;
        }
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
                    cout << indices[0] << ";";
                    vert_indices.push_back(stoi(indices[0]));
                    uv_indices.push_back(stoi(indices[1]));
                    normal_indices.push_back(stoi(indices[2]));
                }
            }
        }
        
        const int vert_array_size = vert_indices.size() * 3;
        const int uv_array_size = uv_indices.size() * 2;
        const int normal_array_size = normal_indices.size() * 3;

        GLfloat* verts = new GLfloat[vert_array_size];
        GLfloat* uvs = new GLfloat[uv_array_size];
        GLfloat* normals = new GLfloat[normal_array_size];

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

        Mesh* mesh = new Mesh(verts, normals, uvs, vert_array_size);

        temp_normals.clear();
        temp_verts.clear();
        temp_uvs.clear();
        uv_indices.clear();
        normal_indices.clear();
        vert_indices.clear();

        models[name] = mesh;
        model_names.push_back(name);
        return mesh;
    }
}

bool AssetManager::UnloadTexture(string name)
{
    if (textures[name] != nullptr)
    {
        delete textures[name];
        textures.erase(name);
        for (int i = 0; i < texture_names.size(); i++)
        { if (name == texture_names[i]) texture_names.erase(texture_names.begin() + i); }
        return true;
    } else return false;
}

bool AssetManager::UnloadFont(string name)
{
    if (fonts[name] != nullptr)
    {
        delete fonts[name];
        fonts.erase(name);
        for (int i = 0; i < font_names.size(); i++)
        { if (name == font_names[i]) font_names.erase(font_names.begin() + i); }
        return true;
    } else return false;
}

bool AssetManager::UnloadAudio(string name)
{
    if (sounds[name] != nullptr)
    {
        delete sounds[name];
        sounds.erase(name);
        for (int i = 0; i < sound_names.size(); i++)
        { if (name == sound_names[i]) sound_names.erase(sound_names.begin() + i); }
        return true;
    } else return false;
}

bool AssetManager::UnloadModel(string name)
{
    if (models[name] != nullptr)
    {
        delete models[name];
        models.erase(name);
        for (int i = 0; i < model_names.size(); i++)
        { if (name == model_names[i]) model_names.erase(model_names.begin() + i); }
        return true;
    } else return false;
}

void AssetManager::ClearAll()
{
    int size = textures.size();
    for (int i = 0; i < size; i++) 
    { 
        delete textures[texture_names[i]]; 
        cout << "Deleted " << texture_names[i] << endl; 
    }
    texture_names.clear();
    
    size = fonts.size();
    for (int i = 0; i < size; i++) delete fonts[font_names[i]];
    font_names.clear();

    size = sounds.size();
    for (int i = 0; i < size; i++) delete sounds[sound_names[i]];
    sound_names.clear();

    size = models.size();
    for (int i = 0; i < size; i++) 
    { 
        delete models[model_names[i]]; 
        cout << "Deleted " << model_names[i] << endl; 
    }
    model_names.clear();

    textures.clear();
    fonts.clear();
    sounds.clear();
    models.clear();
}