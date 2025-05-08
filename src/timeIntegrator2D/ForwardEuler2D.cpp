// src/timeIntegrator2D/ForwardEuler2D.cpp
#include "timeIntegrator2D/ForwardEuler2D.hpp"

void ForwardEuler2D::step(UnknownField2D &u, const UnknownField2D &rhs, double dt, size_t tIdx) const
{
    const size_t nx = u.getNx();
    const size_t ny = u.getNy();

    assert(rhs.getNx() == nx && rhs.getNy() == ny);
    assert(u.getNt() > tIdx + 1); // dobbiamo scrivere in tIdx + 1

    for (size_t i = 0; i < nx; ++i){
        for (size_t j = 0; j < ny; ++j){
            u(i,j, tIdx + 1) = u(i,j,tIdx) + dt * rhs(i,j,tIdx);
        }
    }
}