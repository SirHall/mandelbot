
#include "RendererMandelbrot.hpp"

RendererMandelbrot::RendererMandelbrot(RenderSettings settings)
    : Renderer(settings)
{
}

RendererMandelbrot::RendererMandelbrot(const RendererMandelbrot &other)
    : Renderer(other)
{
}

RendererMandelbrot &
    RendererMandelbrot::operator=(const RendererMandelbrot &other)
{
    return *this;
}

RendererMandelbrot::RendererMandelbrot(RendererMandelbrot &&other)
    : Renderer(std::move(other))
{
}

RendererMandelbrot &RendererMandelbrot::operator=(RendererMandelbrot &&other)
{
    return *this;
}

RendererMandelbrot::~RendererMandelbrot() {}

Image &&RendererMandelbrot::Draw()
{
    Image img = Image(this->GetSettings().renderWidth,
                      this->GetSettings().renderHeight);
}