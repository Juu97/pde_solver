#include "observers/ObserverCsvOutput.hpp"
#include <iostream>

ObserverCsvOutput::ObserverCsvOutput(const std::string& filename) {
    file_.open(filename);
    if (!file_.is_open()) {
        throw std::runtime_error("Could not open CSV file for writing: " + filename);
    }
}

ObserverCsvOutput::~ObserverCsvOutput() {
    file_.close();
}

void ObserverCsvOutput::update(const UnknownField2D& u, const IGrid2D& grid,
                               std::size_t timestep, double time)
{
    if (!headerWritten_) {
        file_ << "timestep,time,i,j,x,y,u\n";
        headerWritten_ = true;
    }

    const std::size_t nx = u.getNx();
    const std::size_t ny = u.getNy();

    for (std::size_t i = 0; i < nx; ++i) {
        for (std::size_t j = 0; j < ny; ++j) {
            auto coord = grid.getCoordinates(i, j);
            file_ << timestep << "," << time << ","
                  << i << "," << j << ","
                  << coord.x << "," << coord.y << ","
                  << u(i, j, timestep) << "\n";
        }
    }
}