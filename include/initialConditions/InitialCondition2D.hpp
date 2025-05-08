// include/initialConditions/InitialCondition2D
#pragma once

#include <functional>
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"

class InitialCondition2D {
private:
    std::function<double(double, double)> func_;

public:
    explicit InitialCondition2D(std::function<double(double,double)> f):
        func_(std::move(f)) {}

    void apply(UnknownField2D& u, const IGrid2D& grid) const;
};