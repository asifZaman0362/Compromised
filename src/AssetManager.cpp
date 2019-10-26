#include "AssetManager.h"

std::map<std::string, sf::Texture*> AssetManager::textures;
std::map<std::string, sf::Font*> AssetManager::fonts;
std::map<std::string, sf::SoundBuffer*> AssetManager::sounds;
std::map<std::string, float*> AssetManager::models;

std::vector<std::string> AssetManager::texture_names;
std::vector<std::string> AssetManager::font_names;
std::vector<std::string> AssetManager::sound_names;
std::vector<std::string> AssetManager::model_names;

sf::Texture* AssetManager::LoadTexture(std::string name)
{
    if (textures[name]!=nullptr) return textures[name];
    else
    {
        sf::Texture* temp = new sf::Texture();
        temp->setSrgb(true);
        if (temp->loadFromFile(TEXTURE_PATH + name + ".jpg"))
        {
            textures[name] = std::move(temp);
            texture_names.push_back(name);
            return textures[name];
        } else 
        {
            delete temp;
            std::cerr << "Failed to load texture!" << std::endl;
            return nullptr;
        }
    }
}

sf::Font* AssetManager::LoadFont(std::string name)
{
    if (fonts[name]!=nullptr) return fonts[name];
    else
    {
        sf::Font* temp = new sf::Font();
        if (temp->loadFromFile(FONT_PATH + name))
        {
            fonts[name] = std::move(temp);
            font_names.push_back(name);
            return fonts[name];
        } else
        {
            delete temp;
            std::cerr << "Failed to load font!" << std::endl;
            return nullptr;
        }
    }
}

sf::SoundBuffer* AssetManager::LoadAudio(std::string name)
{
    if (sounds[name]!=nullptr) return sounds[name];
    else
    {
        sf::SoundBuffer* temp = new sf::SoundBuffer();
        if (temp->loadFromFile(AUDIO_PATH + name))
        {
            sounds[name] = std::move(temp);
            sound_names.push_back(name);
            return sounds[name];
        } else
        {
            std::cerr << "Failed to load audio clip!" << std::endl;
            return nullptr;
        }
    }
}

float* AssetManager::LoadModel(std::string name)
{
    if (models[name]!=nullptr) return models[name];
    else
    {
        // sf::Texture* temp = new sf::Texture();
        // temp->loadFromFile(TEXTURE_PATH"/name");
        // models[name] = std::move(temp);
        // return models[name];
    }
    return nullptr;
}

bool AssetManager::UnloadTexture(std::string name)
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

bool AssetManager::UnloadFont(std::string name)
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

bool AssetManager::UnloadAudio(std::string name)
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

bool AssetManager::UnloadModel(std::string name)
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
    for (int i = 0; i < size; i++) { delete textures[texture_names[i]]; std::cout << "Deleted " << texture_names[i] << std::endl; }
    texture_names.clear();
    size = fonts.size();
    for (int i = 0; i < size; i++) delete fonts[font_names[i]];
    font_names.clear();
    size = sounds.size();
    for (int i = 0; i < size; i++) delete sounds[sound_names[i]];
    sound_names.clear();
    size = models.size();
    for (int i = 0; i < size; i++) delete models[model_names[i]];
    model_names.clear();

    textures.clear();
    fonts.clear();
    sounds.clear();
    models.clear();
}