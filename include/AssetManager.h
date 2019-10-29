#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include "Mesh.h"
#include <string>
#include <vector>
#include <map>

#define TEXTURE_PATH "Assets/Textures/"
#define AUDIO_PATH "Assets/Sounds/"
#define FONT_PATH "Assets/Fonts/"
#define MODEL_PATH "Assets/Models/"
#define SHADER_PATH "Assets/Shaders/"


enum AssetType { TEXTURE, FONT, AUDIO, MODEL };


class AssetManager
{
public:
    AssetManager() = default;
    ~AssetManager() = default;

    static sf::Texture* LoadTexture(std::string);
    static sf::Font* LoadFont(std::string);
    static sf::SoundBuffer* LoadAudio(std::string);
    static Mesh* LoadModel(std::string);
    static bool UnloadTexture(std::string);
    static bool UnloadFont(std::string);
    static bool UnloadAudio(std::string);
    static bool UnloadModel(std::string);
    static void ClearAll();

private:
    static std::map<std::string, sf::Texture*> textures;
    static std::map<std::string, sf::Font*> fonts;
    static std::map<std::string, sf::SoundBuffer*> sounds;
    static std::map<std::string, Mesh*> models;

    static std::vector<std::string> texture_names;
    static std::vector<std::string> font_names;
    static std::vector<std::string> sound_names;
    static std::vector<std::string> model_names;
};
