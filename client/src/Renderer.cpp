
#include "Renderer.hpp"

Renderer::Renderer(RenderSettings settings) : s(settings) {}

Renderer::Renderer(const Renderer &other) : s(other.s) {}

Renderer &Renderer::operator=(const Renderer &other)
{
    this->s = other.s;
    return *this;
}

Renderer::Renderer(Renderer &&other) : s(std::move(other.s)) {}

Renderer &Renderer::operator=(Renderer &&other)
{
    this->s = std::move(other.s);
    return *this;
}

Renderer::~Renderer() {}

Image &&Renderer::Draw() {}
