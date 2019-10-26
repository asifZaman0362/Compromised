#pragma once
#include <string>

struct Settings
{
    std::string     title;
    unsigned short  width;
    unsigned short  height;
    unsigned short  fps_limit;
    unsigned short  depth_bits;
    unsigned short  window_style;
    bool            vsync;
    bool            srgb;

    Settings();
    
};