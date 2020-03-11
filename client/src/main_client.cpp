#include <boost/multiprecision/mpfr.hpp>
#include <iostream>
#include <volt/net.hpp>

namespace mp = boost::multiprecision;

typedef mp::number<mp::mpfr_float_backend<1000>> lrg_float;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: client [host] [port]" << std::endl;
        std::exit(0);
    }

    auto network = volt::net::network::create(2, true);

    network->server_connect(argv[1], argv[2]);

    return 0;
}