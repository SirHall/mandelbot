
#include "Pixel.hpp"

Pixel::Pixel(float red, float green, float blue) : r(red), g(green), b(blue) {}

Pixel Pixel::operator+(const Pixel &v)
{
    return Pixel(r + v.r, g + v.g, b + v.b);
}
Pixel Pixel::operator-(const Pixel &v)
{
    return Pixel(r - v.r, g - v.g, b - v.b);
}
Pixel Pixel::operator*(const Pixel &v)
{
    return Pixel(r * v.r, g * v.g, b * v.b);
}
Pixel Pixel::operator/(const Pixel &v)
{
    return Pixel(r / v.r, g / v.g, b / v.b);
}

Pixel Pixel::operator+(const float &v) { return Pixel(r + v, g + v, b + v); }
Pixel Pixel::operator-(const float &v) { return Pixel(r - v, g - v, b - v); }
Pixel Pixel::operator*(const float &v) { return Pixel(r * v, g * v, b * v); }
Pixel Pixel::operator/(const float &v) { return Pixel(r / v, g / v, b / v); }