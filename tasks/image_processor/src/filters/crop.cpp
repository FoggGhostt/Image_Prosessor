#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "image/color.h"
#include "image/image.h"

#include <filters/filter.h>
#include <filters/registry.h>

namespace image_processor::filters {

namespace {

size_t Cast(std::string_view s) {
    std::stringstream sstream(s.data());
    size_t result = 0;
    sstream >> result;
    return result;
}

}  // namespace

class Crop : public Filter {
public:
    class Factory : public Filter::Factory {
    public:
        std::unique_ptr<Filter> Construct(const std::vector<std::string>& parameters) override {
            if (parameters.size() != 2) {
                throw std::invalid_argument("");
            }

            const size_t width = Cast(parameters[0]);
            const size_t height = Cast(parameters[1]);
            return std::make_unique<Crop>(width, height);
        }
    };

public:
    Crop(size_t width, size_t height)
        : width_(width)
        , height_(height) {
    }

    image::Image Apply(const image::Image& image) override {
        height_ = std::min(image.GetHeight(), height_);
        width_ = std::min(image.GetWidth(), width_);
        if (width_ < 0 || height_ < 0) {
            throw std::runtime_error("USAGE: -crop width>0 height>0");
        }
        image::Image new_image{width_, height_};
        for (size_t row = image.GetHeight() - height_; row < image.GetHeight(); ++row) {
            for (size_t col = 0; col < width_; ++col) {
                new_image(row - (image.GetHeight() - height_), col) = image(row, col);
            }
        }
        return new_image;
    }

    ~Crop() override = default;

private:
    [[maybe_unused]] size_t width_;
    [[maybe_unused]] size_t height_;
};

REGISTER_FILTER("crop", Crop::Factory)

}  // namespace image_processor::filters
