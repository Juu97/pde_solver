// include/timeIntegrator2D/ITimeIntegrator2D.hpp

#pragma once
#include "fields/UnknownField2D.hpp"

class ITimeIntegrator2D {

public:
    virtual ~ITimeIntegrator2D() = default;

    virtual void step(UnknownField2D& u,
                      const UnknownField2D& rhs,
                      double dt,
                      size_t tIdx) const = 0;

};