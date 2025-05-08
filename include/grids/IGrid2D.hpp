// include/grids/IGrid2D.hpp

#pragma once

#include <cstddef>
#include "Coordinates2D.hpp"

class IGrid2D{
protected:
    double dy_, dx_;
    std::size_t ny_, nx_;

public:
    virtual Coordinates2D getCoordinates(std::size_t i, std::size_t j) const = 0;
    virtual ~IGrid2D() = default;

    double getDy() const {return dy_;}
    double getDx() const {return dx_;}

    std::size_t getNy() const {return ny_;}
    std::size_t getNx() const {return nx_;}


};