#include "Image.hpp"

#include "stb_image.h"
#include "stb_image_write.h"

#include <algorithm>
#include <cassert>
#include <iostream>

Image::Image(std::uint64_t width, std::uint64_t height) : w(width), h(height)
{
    this->imgData.resize(width * height * 3);
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

std::uint64_t XYToI(std::uint64_t x, std::uint64_t y, std::uint64_t w,
                    std::uint64_t h, std::uint8_t channel)
{
    return ((x + w * y) * 3) + channel;
}

Pixel Image::GetPixel(std::uint64_t x, std::uint64_t y)
{
    assert(x < this->w);
    assert(y < this->h);
    return Pixel((float)this->imgData[XYToI(x, y, w, h, 0)] / 255.0f,
                 (float)this->imgData[XYToI(x, y, w, h, 1)] / 255.0f,
                 (float)this->imgData[XYToI(x, y, w, h, 2)] / 255.0f);
}

void Image::SetPixel(std::uint64_t x, std::uint64_t y, Pixel p)
{
    assert(x < this->w);
    assert(y < this->h);
    this->imgData[XYToI(x, y, w, h, 0)] =
        std::uint8_t(std::clamp(p.r * 255.0f, 0.0f, 255.0f));
    this->imgData[XYToI(x, y, w, h, 1)] =
        std::uint8_t(std::clamp(p.g * 255.0f, 0.0f, 255.0f));
    this->imgData[XYToI(x, y, w, h, 2)] =
        std::uint8_t(std::clamp(p.b * 255.0f, 0.0f, 255.0f));
}

bool Image::SaveAs(std::string const &fName)
{
    return stbi_write_png(fName.c_str(), this->w, this->h, STBI_rgb,
                          this->imgData.data(), this->w * 3) == 1;
}