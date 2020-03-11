
#include "FrameData.hpp"

FrameData::FrameData(std::uint64_t f) : frameNumber(f) {}

template <>
void volt::net::serialize::write_into(struct FrameData const &v,
                                      message_ptr &           data)
{
    volt::net::serialize::write_into(v.frameNumber, data);
}

template <>
void volt::net::deserialize::read_into(message_iter &    iterator,
                                       struct FrameData &instance)
{
    volt::net::deserialize::read_into(iterator, instance.frameNumber);
}