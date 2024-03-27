#include <cstddef>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
#include <algorithm>
#include "image/color.h"
#include "image/image.h"
#include "utils/matrix.h"

#include <filters/filter.h>
#include <filters/registry.h>


namespace image_processor::filters {

namespace {

const float FILTER_MATRIX_POS_11 = 0.0f;
const float FILTER_MATRIX_POS_12 = -1.0f;
const float FILTER_MATRIX_POS_13 = 0.0f;
const float FILTER_MATRIX_POS_21 = -1.0f;
const float FILTER_MATRIX_POS_22 = 5.0f;
const float FILTER_MATRIX_POS_23 = -1.0f;
const float FILTER_MATRIX_POS_31 = 0.0f;
const float FILTER_MATRIX_POS_32 = -1.0f;
const float FILTER_MATRIX_POS_33 = 0.0f;
const std::vector<float> FILTER_VECTOR{FILTER_MATRIX_POS_11, FILTER_MATRIX_POS_12, FILTER_MATRIX_POS_13,
                                FILTER_MATRIX_POS_21, FILTER_MATRIX_POS_22, FILTER_MATRIX_POS_23,
                                FILTER_MATRIX_POS_31, FILTER_MATRIX_POS_32, FILTER_MATRIX_POS_33};
const utils::Matrix<float> FILTER_MATRIX{3, 3, FILTER_VECTOR};

}  // namespace

class Sharpening : public Filter {
public:
    class Factory : public Filter::Factory {
    public:
        std::unique_ptr<Filter> Construct(const std::vector<std::string>& parameters) override {
            return std::make_unique<Sharpening>();
        }
    };

public:
    Sharpening() {
    }

    image::Image Apply(const image::Image& image) override {
        utils::Matrix<image::Color> answer_image = image;
        for (size_t row = 0; row < answer_image.GetHeight(); ++row) {
            for (size_t col = 0; col < answer_image.GetWidth(); ++col) {
                const int64_t lower_row = 0;
                const int64_t upper_row = static_cast<int64_t>(image.GetHeight() - 1);
                const int64_t lower_col = 0;
                const int64_t upper_col = static_cast<int64_t>(image.GetWidth() - 1);
                answer_image(row, col) = answer_image(row, col) - answer_image(row, col);
                for (int64_t i = 0; i < 3; ++i) {
                    for (int64_t j = 0; j < 3; ++j) {
                        const size_t modified_row_cord = static_cast<size_t>(std::clamp(static_cast<int64_t>(row) + 1 - i, lower_row, upper_row));
                        const size_t modified_col_cord = static_cast<size_t>(std::clamp(static_cast<int64_t>(col) + 1 - j, lower_col, upper_col));
                        answer_image(row, col) = answer_image(row, col) +
                                                 image(modified_row_cord, modified_col_cord) *
                                                     (FILTER_MATRIX(i, j));
                    }
                }
                answer_image(row, col).r = std::fmin(1.0f, std::fmax(0.0f, answer_image(row, col).r));
                answer_image(row, col).g = std::fmin(1.0f, std::fmax(0.0f, answer_image(row, col).g));
                answer_image(row, col).b = std::fmin(1.0f, std::fmax(0.0f, answer_image(row, col).b));
            }
        }
        return answer_image;
    }

    ~Sharpening() override = default;
};

REGISTER_FILTER("sharp", Sharpening::Factory)

}  // namespace image_processor::filters
