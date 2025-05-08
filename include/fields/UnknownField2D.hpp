// include/fields/UnknownField2D.hpp
#pragma once

#include <vector>
#include <cassert>
#include <utility>


class UnknownField2D {
private:
    std::size_t nx_, ny_, nt_;
    std::vector<std::vector<double>> data_; // data[n][i+j*nx]

public:
    UnknownField2D(size_t nx, size_t ny, size_t nt)
        : nx_(nx), ny_(ny), nt_(nt), data_(nt, std::vector<double>(nx * ny)) {}

    UnknownField2D(UnknownField2D&& other) noexcept;

    double& operator()(size_t x, size_t y, size_t t);
    const double& operator()(size_t x, size_t y, size_t t) const;

    // Getter
    size_t getNx() const {return nx_;};
    size_t getNy() const {return ny_;};
    size_t getNt() const {return nt_;};

    // Time Slice
    std::vector<double>& timeSlice(size_t n);
    const std::vector<double>& timeSlice(size_t n) const;
};