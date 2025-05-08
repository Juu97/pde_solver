// include/timeIntegrator2D/ForwardEuler2D.hpp
#pragma once

#include "ITimeIntegrator2D.hpp"

class ForwardEuler2D: public ITimeIntegrator2D {
public:
    void step(  UnknownField2D& u,
                const UnknownField2D& rhs,
                double dt,
                size_t tIdx
                ) const override;

};