// UnknownField2D.hpp
#pragma once

#include <vector>
#include <cassert>
#include <utility>

template < typename T >
class UnknownField2D {
private:
    std::size_t nx_, ny_, nt_;
    std::vector<std::vector<T>> data_; // data[n][i+j*nx]

public:
    UnknownField2D(size_t nx, size_t ny, size_t nt)
        : nx_(nx), ny_(ny), nt_(nt), data_(nt, std::vector<T>(nx * ny)) {}

    UnknownField2D(UnknownField2D&& other) noexcept;

    T& operator()(size_t x, size_t y, size_t t) override;
    const T& operator()(size_t x, size_t y, size_t t) const override;

    // Getter
    void getNx() const {return nx_};
    void getNy() const {return ny_};
    void getNt() const {return nt_};

    // Time Slice
    std::vector<T>& timeSlice(size_t n);
    const std::vector<T>& timeSlice(size_t n) const;
};