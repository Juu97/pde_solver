#pragma once

#include <cstddef>
#include "include/Coordinates2D.hpp"

class IGrid2D{
public:
    virtual Coordinates2D getCoordinates(std::size_t i, std::size_t j) const = 0;
    virtual ~IGrid2D() = default;
};