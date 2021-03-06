#pragma once
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "Pixel.hpp"

class Image
{
private:
    std::vector<std::uint8_t> imgData;
    std::uint64_t             w, h;

public:
    Image(std::uint64_t width, std::uint64_t height);
    Image(const Image &other);
    Image &operator=(const Image &other);
    Image(Image &&other);
    Image &operator=(Image &&other);
    ~Image();

    inline std::vector<std::uint8_t> const &GetImgData()
    {
        return this->imgData;
    }

    Pixel GetPixel(std::uint64_t x, std::uint64_t y);
    void  SetPixel(std::uint64_t x, std::uint64_t y, Pixel p);

    bool SaveAs(std::string const &fName);
};

#endif
