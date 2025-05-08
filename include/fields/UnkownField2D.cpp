// UnknownField2D.cpp
#include "fields/UnkownField2D.hpp"
#include "UnkownField2D.hpp"

template < typename T >
UnknownField2D<T>::UnknownField2D(UnknownField2D<T>&& other) noexcept {
    nx_ = other.nx_;
    nt_ = other.nt_;
    ny_ = other.ny_;
    data_ = std::move(other.data_);
}

template <typename T>
// Deve ritornare una referenza? non basta T?
T& UnknownField2D<T>::operator()(size_t i, size_t j, size_t n)
{
    assert(i < nx_ and j < ny_ and n < nt_);
    return data_[n][i + j * nx_];
}

template <typename T>
const T& UnknownField2D<T>::operator()(size_t i, size_t j, size_t n) const
{
    assert(i < nx_ and j < ny_ and n < nt_);
    return data_[n][i + j * nx_];
}

template <typename T>
std::vector<T>& UnknownField2D<T>::timeSlice(size_t n)
{
    assert(n < nt_);
    return data_[n];
}

template <typename T>
const std::vector<T>& UnknownField2D<T>::timeSlice(size_t n) const
{
    assert(n < nt_);
    return data_[n];
}