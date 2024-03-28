#include "image_format/bmp.h"
#include <filters/registry.h>
#include <stdexcept>
#include "args/args.h"

int main(int argc, const char** argv) {
    try {
        image_processor::args::Args args(argc, argv);
        image_processor::image_format::BMP bmp;
        auto image = bmp.Load(args.InputFile());
        for (const auto& filter_params : args.Filters()) {
            try {
                auto factory = image_processor::filters::Registry::Instance().Get(filter_params.Name());
                auto filter = factory(filter_params.Parameters());
                image = filter->Apply(image);
            } catch (const std::runtime_error& error) {
                std::cerr << "Error with filter arguments: " << error.what() << std::endl;
                return 0;
            }
        }
        bmp.Save(image, args.OutputFile());
    } catch (const std::runtime_error& error) {
        std::cerr << "Filter Error: " << error.what() << std::endl;
        return 0;
    }
    return 0;
}
