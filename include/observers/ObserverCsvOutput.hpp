#pragma once

#include "ISolverObserver.hpp"
#include "grids/IGrid2D.hpp"
#include "fields/UnknownField2D.hpp"
#include <fstream>
#include <string>

class ObserverCsvOutput : public ISolverObserver {
private:
    std::ofstream file_;
    bool headerWritten_ = false;

public:
    explicit ObserverCsvOutput(const std::string& filename);
    ~ObserverCsvOutput();

    void update(const UnknownField2D& u, const IGrid2D& grid,
                std::size_t timestep, double time) override;
};