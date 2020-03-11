#pragma once
#ifndef RENDERERMANDELBROT_HPP
#define RENDERERMANDELBROT_HPP

#include "Renderer.hpp"

class RendererMandelbrot : public Renderer
{
private:
public:
    RendererMandelbrot(RenderSettings settings);
    RendererMandelbrot(const RendererMandelbrot &other);
    RendererMandelbrot &operator=(const RendererMandelbrot &other);
    RendererMandelbrot(RendererMandelbrot &&other);
    RendererMandelbrot &operator=(RendererMandelbrot &&other);
    ~RendererMandelbrot();

    Image Draw(std::uint64_t frameNumber);
};

#endif
