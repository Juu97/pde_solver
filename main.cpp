#include <memory>
#include <cmath>
#include "Logger.hpp"
#include "grids/Grid2DFactory.hpp"
#include "initialConditions/InitialCondition2D.hpp"
#include "boundaries/BoundaryHandler2DDirichlet.hpp"
#include "equations/HeatEquationSystem.hpp"
#include "timeIntegrator2D/ForwardEuler2D.hpp"
#include "SolverEngine2D.hpp"
#include "observers/ObserverExactSolution.hpp"

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
    double dirichlet_constant = 0.0;
    std::unique_ptr<IBoundaryHandler2D> boundary = std::make_unique<BoundaryHandler2DDirichlet>(dirichlet_constant);

    // Define PDE
    double heat_alpha = 1;
    std::unique_ptr<IEquationSystem> equation = std::make_unique<HeatEquationSystem>(heat_alpha);

    // Time integrator
    std::unique_ptr<ITimeIntegrator2D> integrator = std::make_unique<ForwardEuler2D>();

    // Simulation parameters
    double dt = 0.0005;
    double total_time = 1;

    // Solver engine
    SolverEngine2D solver(
        std::move(grid),
        std::move(boundary),
        std::move(equation),
        std::move(initial_condition),
        std::move(integrator),
        dt,
        total_time
    );

    //Add observer - Exact solution
    auto exact_solution = [](double x, double y, double t){
        return std::sin(M_PI * x) * std::sin(M_PI * y) * std::exp(-2.0 * M_PI * M_PI * t);
    };
    std::unique_ptr<ISolverObserver> exac_solution_observer = std::make_unique<ObserverExactSolution>(std::move(exact_solution));

    solver.addObserver(std::move(exac_solution_observer));

    // Run simulation
    solver.run();

    // Access result
    const UnknownField2D& result = solver.getSolution();

    Logger::info("Simulation completed successfully.");
    Logger::info("Final value at u(0,0) = " + std::to_string(result(0, 0, result.getNt() - 1)));

    return 0;
}
