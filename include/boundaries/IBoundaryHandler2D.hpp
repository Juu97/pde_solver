// include/boundaries/IBoundaryHandler2D.hpp

#pragma once
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"

class IBoundaryHandler2D {
public:
    virtual void apply(UnknownField2D& u,
                       const IGrid2D& grid,
                       double time,
                       std::size_t tIdx) = 0;

    virtual ~IBoundaryHandler2D() = default;
};