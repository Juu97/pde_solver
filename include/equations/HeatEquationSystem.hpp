// include/equations/HeatEquationSystem.hpp
#pragma once
#include "EquationSystem.hpp"


class HeatEquationSystem : public EquationSystem {
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