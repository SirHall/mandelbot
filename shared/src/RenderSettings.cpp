#include "RenderSettings.hpp"

template <>
void volt::net::serialize::write_into(struct RenderSettings const &v,
                                      message_ptr &                data)
{
    volt::net::serialize::write_into(v.renderWidth, data);
    volt::net::serialize::write_into(v.renderHeight, data);
    volt::net::serialize::write_into(v.milliSecondsPerFrame, data);
    volt::net::serialize::write_into(v.downsizedWidth, data);
    volt::net::serialize::write_into(v.downsizedHeight, data);
    volt::net::serialize::write_into(v.algorithmID, data);
    volt::net::serialize::write_into(v.totalFrames, data);
    volt::net::serialize::write_into(v.done, data);
}

template <>
void volt::net::deserialize::read_into(message_iter &         iterator,
                                       struct RenderSettings &instance)
{
    volt::net::deserialize::read_into(iterator, instance.renderWidth);
    volt::net::deserialize::read_into(iterator, instance.renderHeight);
    volt::net::deserialize::read_into(iterator, instance.milliSecondsPerFrame);
    volt::net::deserialize::read_into(iterator, instance.downsizedWidth);
    volt::net::deserialize::read_into(iterator, instance.downsizedHeight);
    volt::net::deserialize::read_into(iterator, instance.algorithmID);
    volt::net::deserialize::read_into(iterator, instance.totalFrames);
    volt::net::deserialize::read_into(iterator, instance.done);
}