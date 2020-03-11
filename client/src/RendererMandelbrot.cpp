#include "RendererMandelbrot.hpp"

#include <boost/multiprecision/mpfr.hpp>

#include <iostream>

RendererMandelbrot::RendererMandelbrot(RenderSettings settings)
    : Renderer(settings)
{
}

RendererMandelbrot::RendererMandelbrot(const RendererMandelbrot &other)
    : Renderer(other)
{
}

RendererMandelbrot &
    RendererMandelbrot::operator=(const RendererMandelbrot &other)
{
    return *this;
}

RendererMandelbrot::RendererMandelbrot(RendererMandelbrot &&other)
    : Renderer(std::move(other))
{
}

RendererMandelbrot &RendererMandelbrot::operator=(RendererMandelbrot &&other)
{
    return *this;
}

RendererMandelbrot::~RendererMandelbrot() {}

namespace mp = boost::multiprecision;

typedef mp::number<mp::mpfr_float_backend<1028>> lrg_float;

// typedef double lrg_float;

Image RendererMandelbrot::Draw(std::uint64_t frameNumber)
{
    std::uint64_t maxIter = 1000000;
    lrg_float     escape  = lrg_float(2.0);
    // Square 'escape' as it compared against the squared distance below
    escape               = escape * escape;
    auto const &settings = this->GetSettings();

    Image img = Image(settings.renderWidth, settings.renderHeight);

    lrg_float aspectRatio =
        lrg_float(settings.renderWidth) / lrg_float(settings.renderHeight);

    // The center position of the camera (The zoom location)
    lrg_float x = lrg_float(
        "-1."
        "7469915583743520304988126486073673090976861804291275739678233744356389"
        "6470217359269625626403405485757236884928468222021776911123254945595434"
        "8171545870547318896714798824681578974458135030506893206027271662628341"
        "6413648051480702895045574675802222343251307021112476608158134242591207"
        "4342581240141683465981826909179125292135468176255267667916271898955953"
        "5394267473793705059090612687636199901088915773540861076002148550465745"
        "1452875032271483666132859628303202534037862999303962165827790239255740"
        "3736636583568901440098245384105739927220212166562963071870155709807322"
        "9298709443505574179686498133868966835401156639999499261722782841286409"
        "1757715606372657278968644252599579421273488308666715833440551868900744"
        "6506191393282536235957305026501313029045466038623460460599453301340302"
        "2015514746044493505156566694117710567686023586233437905675942455976010"
        "1357864338547652699321237432042151722842994175270475459797626964102165"
        "8550176941601179029074992865891446241502216712264547000466409989625354"
        "8950804209145990428058078157154741441063846801474596268235966869946907"
        "6646");
    lrg_float y = lrg_float(
        "0."
        "0030790093784324752552715513146916761836905463273344483804743250001066"
        "5306781846618614950842608605937050051637943385315539371313298922266717"
        "2274099455644773376379988706057198797714063372387722788685310184063907"
        "9005413219423560318716570539651834156126676102867283510600184625729532"
        "9888164750811490980796380925690097434667902142398219521612902064006921"
        "6945080170111541158480916048752584253765250222378769545605180372966124"
        "8724876138159962019867259354290949290437637769988033003979540969294016"
        "0895363663451731068561855023215475852351945873425999647692069288937501"
        "1298052531992895585203355528064549310635575647278485427081802074008272"
        "6138112011638913296550802902199495638119315036184488928493191566100658"
        "8162905065854577967270741376475452908227435454968858380280577724853349"
        "8113276316000979281292530828780043837581845687382157699571562601694467"
        "7203049516584530387107980388822422916245896587932853157012716899623690"
        "3558443781684392583090178050388580488885763376905637555314801726890808"
        "4271930420672439479521176542873578286233416301016997680150431725051887"
        "3585");

    lrg_float currentTime =
        (lrg_float(settings.milliSecondsPerFrame) / lrg_float(1000.0)) *
        lrg_float(frameNumber);
    lrg_float zoom = mp::pow(currentTime, currentTime / lrg_float(10.0));
    zoom           = lrg_float("4.1638510343219917") *
           mp::pow(lrg_float(10), lrg_float(1028));
    std::cout << "Current time: " << currentTime << "\nZoom: " << zoom
              << std::endl;
    for (std::uint64_t xPix = 0; xPix < settings.renderWidth; xPix++)
    {
        std::cout << '\t' << std::setprecision(4)
                  << (float)xPix / (float)settings.renderWidth * 100.0f
                  << "%          \r" << std::flush;
        for (std::uint64_t yPix = 0; yPix < settings.renderHeight; yPix++)
        {
            lrg_float uvX = (lrg_float(xPix) / lrg_float(settings.renderWidth) -
                             lrg_float(0.5)) *
                            lrg_float(2.0);
            lrg_float uvY =
                (lrg_float(yPix) / lrg_float(settings.renderHeight) -
                 lrg_float(0.5)) *
                lrg_float(2.0);
            // Z
            lrg_float zX = 0.0, zY = 0.0;
            lrg_float cX = ((uvX * aspectRatio) / zoom) + x;
            lrg_float cY = (uvY / zoom) + y;

            std::uint64_t i = 0;

            for (i = 0; i < maxIter; i++)
            {
                lrg_float zXNew = (zX * zX - zY * zY) + cX;
                lrg_float zYNew = (zY * zX + zX * zY) + cY;

                if ((zXNew * zXNew + zYNew * zYNew) > escape)
                    break;
                zX = zXNew;
                zY = zYNew;
            }
            // Now we know if this is part of the set or not. Now to color
            // the pixel
            img.SetPixel(xPix, yPix, Pixel(i / maxIter));
        }
    }
    std::cout << "Fully completed" << std::endl;
    return std::move(img);
}