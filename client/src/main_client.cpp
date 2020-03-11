#include <boost/multiprecision/mpfr.hpp>
#include <iostream>
#include <volt/net.hpp>

#include "RendererMandelbrot.hpp"

int main(int argc, char *argv[])
{
    // if (argc < 3)
    // {
    //     std::cout << "Usage: client [host] [port]" << std::endl;
    //     std::exit(0);
    // }

    // auto network = volt::net::network::create(2, true);

    // network->server_connect(argv[1], argv[2]);

    auto settings                 = RenderSettings();
    settings.algorithmID          = 0;
    settings.done                 = false;
    settings.renderWidth          = 4096;
    settings.renderHeight         = 2160;
    settings.milliSecondsPerFrame = 17;
    settings.totalFrames          = 10000;

    auto mandelRenderer = RendererMandelbrot(settings);

    auto image = mandelRenderer.Draw(500);
    image.SaveAs("10.png");

    return 0;
}