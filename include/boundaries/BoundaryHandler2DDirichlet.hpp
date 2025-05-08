// include/boundaries/BoundaryHandler2DDirichlet.hpp

#pragma once
#include "IBoundaryHandler2D.hpp"

class BoundaryHandler2DDirichlet: public IBoundaryHandler2D {
private:
    double dirichletConstant_;

public:
    explicit BoundaryHandler2DDirichlet(double constant): dirichletConstant_(constant) {}

    void apply(UnknownField2D& u,
                       const IGrid2D& grid,
                       double time,
                       std::size_t tIdx) override;

};