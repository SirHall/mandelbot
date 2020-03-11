#pragma once
#ifndef RENDERSETTINGS_HPP
#define RENDERSETTINGS_HPP

#include <cstdint>
#include <volt/net.hpp>

struct RenderSettings
{
    std::uint64_t renderWidth;
    std::uint64_t renderHeight;
    std::uint64_t milliSecondsPerFrame;
    std::uint64_t downsizedWidth;
    std::uint64_t downsizedHeight;
    std::uint16_t algorithmID;
    std::uint64_t totalFrames;
    bool          done = false;
};

template <>
void volt::net::serialize::write_into(struct RenderSettings const &v,
                                      message_ptr &                data);
template <>
void volt::net::deserialize::read_into(message_iter &         iterator,
                                       struct RenderSettings &instance);
#endif
