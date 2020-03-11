#include <iostream>
#include <string>
#include <volt/net.hpp>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: server [ipv4 port] [ipv6 port]" << std::endl;
        std::exit(0);
    }
    std::uint16_t ipv4_port = 0;
    std::uint16_t ipv6_port = 0;
    try
    {
        ipv4_port = std::stoi(argv[1]);
        ipv6_port = std::stoi(argv[2]);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error occurred while parsing ports\n\t" << e.what()
                  << std::endl;
        std::exit(1);
    }

    auto network = volt::net::network::create(8, false);

    {
        auto lck = network->get_guard();
        network->start_listening(ipv4_port, ipv6_port, lck);
    }

    return 0;
}
