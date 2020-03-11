#pragma once
#ifndef PIXEL_HPP
#define PIXEL_HPP

struct Pixel
{
public:
    Pixel(float red, float green, float blue);
    float const r, g, b;

    Pixel operator+(const Pixel &v);
    Pixel operator-(const Pixel &v);
    Pixel operator*(const Pixel &v);
    Pixel operator/(const Pixel &v);

    Pixel operator+(const float &v);
    Pixel operator-(const float &v);
    Pixel operator*(const float &v);
    Pixel operator/(const float &v);
};

#endif
