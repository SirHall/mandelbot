#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Image.hpp"
#include "RenderSettings.hpp"

class Renderer
{
private:
    RenderSettings s;

public:
    Renderer(RenderSettings settings);
    Renderer(const Renderer &other);
    Renderer &operator=(const Renderer &other);
    Renderer(Renderer &&other);
    Renderer &operator=(Renderer &&other);
    ~Renderer();

    inline RenderSettings const &GetSettings() { return s; }

    Image Draw(std::uint64_t frameNumber);
};

#endif
