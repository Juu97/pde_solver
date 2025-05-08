#include "initialConditions/InitialCondition2D.hpp"

void InitialCondition2D::apply(UnknownField2D &u, const IGrid2D &grid) const
{
    const size_t nx = u.getNx();
    const size_t ny = u.getNy();

    for (size_t i = 0; i < nx; i++){
        for(size_t j = 0; j < ny; j++){
            Coordinates2D coords = grid.getCoordinates(i,j);
            u(i,j,0) = func_(coords.x, coords.y);
        }
    }
}