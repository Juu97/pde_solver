// src/fields/UnknownField2D.cpp
#include "fields/UnknownField2D.hpp"

UnknownField2D::UnknownField2D(UnknownField2D&& other) noexcept {
    nx_ = other.nx_;
    nt_ = other.nt_;
    ny_ = other.ny_;
    data_ = std::move(other.data_);
}

UnknownField2D& UnknownField2D::operator=(UnknownField2D&& other) noexcept {
    if (this != &other) {
        nx_ = other.nx_;
        ny_ = other.ny_;
        nt_ = other.nt_;
        data_ = std::move(other.data_);
    }
    return *this;
}

// Deve ritornare una referenza? non basta T?
// => permette di fare field(i,j,n) = 4. ed è più efficiente (no copie)
double& UnknownField2D::operator()(size_t i, size_t j, size_t n)
{
    assert(i < nx_ and j < ny_ and n < nt_);
    return data_[n][i + j * nx_];
}

const double& UnknownField2D::operator()(size_t i, size_t j, size_t n) const
{
    assert(i < nx_ and j < ny_ and n < nt_);
    return data_[n][i + j * nx_];
}


std::vector<double>& UnknownField2D::timeSlice(size_t n)
{
    assert(n < nt_);
    return data_[n];
}

const std::vector<double>& UnknownField2D::timeSlice(size_t n) const
{
    assert(n < nt_);
    return data_[n];
}