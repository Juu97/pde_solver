#include <memory>
#include <cmath>
#include "Logger.hpp"
#include "grids/Grid2DFactory.hpp"
#include "initialConditions/InitialCondition2D.hpp"
#include "boundaries/BoundaryHandler2DDirichlet.hpp"
#include "equations/HeatEquationSystem.hpp"
#include "timeIntegrator2D/ForwardEuler2D.hpp"
#include "SolverEngine2D.hpp"

int main() {
    Logger::info("Executing program");

    // Grid
    std::unique_ptr<IGrid2D> grid = Grid2DFactory::create(Grid2DType::DefaultUniform);

    // Initial Conditions
    auto g_x = [](double x, double y){
        return std::sin(M_PI * x) * std::sin(M_PI * y);
    };
    std::unique_ptr<InitialCondition2D> initial_condition = std::make_unique<InitialCondition2D>(g_x);

    // Boundary Conditions
    double dirichlet_constant = 1.0;
    std::unique_ptr<IBoundaryHandler2D> boundary = std::make_unique<BoundaryHandler2DDirichlet>(dirichlet_constant);

    // Define PDE
    double heat_alpha = 0.5;
    std::unique_ptr<IEquationSystem> equation = std::make_unique<HeatEquationSystem>(heat_alpha);

    // Time integrator
    std::unique_ptr<ITimeIntegrator2D> integrator = std::make_unique<ForwardEuler2D>();

    // Simulation parameters
    double dt = 0.01;
    double total_time = 1.0;

    // Solver engine
    SolverEngine2D solver(*grid, *equation, *boundary, *integrator, *initial_condition, dt, total_time);

    // Run simulation
    solver.run();

    // Access result
    const UnknownField2D& result = solver.getSolution();

    Logger::info("Simulation completed successfully.");
    Logger::info("Final value at u(0,0) = " + std::to_string(result(0, 0, result.getNt() - 1)));

    return 0;
}
