#include "Image.hpp"
#include <cassert>

Image::Image(std::uint64_t width, std::uint64_t height)
    : imgData(0.0f, width * height * 3), w(width), h(height)
{
}

Image::Image(const Image &other)
    : w(other.w), h(other.h), imgData(other.imgData)
{
}

Image &Image::operator=(const Image &other)
{
    this->w       = other.w;
    this->h       = other.h;
    this->imgData = other.imgData;
    return *this;
}

Image::Image(Image &&other)
    : w(std::move(other.w)), h(std::move(other.h)),
      imgData(std::move(other.imgData))
{
}

Image &Image::operator=(Image &&other)
{
    this->w       = std::move(other.w);
    this->h       = std::move(other.h);
    this->imgData = std::move(other.imgData);
    return *this;
}

Image::~Image() {}

Pixel Image::GetPixel(std::uint64_t x, std::uint64_t y)
{
    assert(x < this->w);
    assert(y < this->h);
    std::uint64_t i = ((x * w) + y) * 3;
    return Pixel(i, i + 1, i + 2);
}
void Image::SetPixel(std::uint64_t x, std::uint64_t y, Pixel p)
{
    assert(x < this->w);
    assert(y < this->h);
    std::uint64_t i      = ((x * w) + y) * 3;
    this->imgData[i]     = p.r;
    this->imgData[i + 1] = p.g;
    this->imgData[i + 2] = p.b;
}