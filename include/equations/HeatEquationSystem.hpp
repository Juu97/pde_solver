// include/equations/HeatEquationSystem.hpp
#pragma once
#include "IEquationSystem.hpp"


class HeatEquationSystem : public IEquationSystem {
private:
    double alpha_;

public:
    explicit HeatEquationSystem(double alpha) : alpha_(alpha) {}

    void computeSpatialOperator(
        const UnknownField2D& u,
        UnknownField2D& result,
        const IGrid2D& grid,
        std::size_t tIdx
    ) const override;

};