// src/boundaries/BoundaryHandler2DDirichlet.cpp

#include "boundaries/BoundaryHandler2DDirichlet.hpp"

void BoundaryHandler2DDirichlet::apply(UnknownField2D &field,
    const IGrid2D &grid,
    double time,
    std::size_t tIdx)
{
    const size_t nx = field.getNx();
    const size_t ny = field.getNy();

    for (size_t i = 0; i < nx; i++){
        field(i, 0, tIdx) = dirichletConstant_;
        field(i, ny-1, tIdx) = dirichletConstant_;
    }

    for (size_t j = 0; j < ny; j++){
        field(0, j, tIdx) = dirichletConstant_;
        field(nx - 1, j, tIdx) = dirichletConstant_;
    }

}