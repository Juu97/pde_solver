# ⚙️ PDE Solver Library in Modern C++

A modular, high-performance C++ library for solving time-dependent partial differential equations (PDEs) of the form:

```
∂u(x, y, t)/∂t = L[u(x, y, t)]
```

with `u: ℝ² × ℝ → ℝ`, where `L` is a spatial differential operator (e.g., Laplacian for heat diffusion).

## 🧠 Project Goals

- **High Performance**: Cache-aware design and move semantics to minimize memory overhead.
- **Modular Architecture**: Each component is decoupled and interchangeable.
- **OOP Design Patterns**: Designed using SOLID principles and modern C++ features.
- **Research-Oriented**: Aimed at prototyping numerical schemes and PDE systems efficiently.

## 🧱 Architecture Overview

```
+--------------------+
|    PDE Solver API  |   <-- Facade Pattern
+--------------------+
           |
           v
+------------------------+
| Configuration Builder  |  <-- Builder Pattern (TBD)
+------------------------+
           |
           v
+----------------------+
|     Solver Engine     |         <-- Strategy Pattern
+----------------------+
| - TimeIntegrator      |
| - SpatialDiscretizer  |
| - EquationSystem      |
| - Observers           |
+----------------------+
   |            |
   v            v
+---------+  +----------------+
| Grid    |  | BoundaryHandler|  <-- Decorator Pattern
+---------+  +----------------+
   |
   v
+----------------------+
| Mesh/Grid Factory     |  <-- Factory Method Pattern
+----------------------+

           |
           v
+--------------------------+
|     UnknownField u(x,y,t) |  <-- Template-Based, Cache-Aware
+--------------------------+

+------------------------+
|     Output Manager     |  <-- Observer Pattern (TBD)
+------------------------+
           ^
           |
+------------------------+
| SimulationController   |  <-- Singleton Pattern (TBD)
+------------------------+
```

## ✅ Features

- Solves **2D time-dependent PDEs** on uniform grids.
- Discretization using **finite difference methods (FDM)**.
- Supports **Euler forward** time integration (more to come).
- Explicit handling of **boundary conditions** via decorators.
- **Simulation logging and output** via an observer-based manager.

## 📂 Directory Structure

```
pde_solver/
├── include/               # Header files grouped by responsibility
├── src/                   # Implementation files
├── data/                  # Configuration and results
├── main.cpp               # Simulation entry point
├── CMakeLists.txt         # CMake project setup
```

## 🛠️ How to Build

```bash
mkdir build && cd build
cmake ..
make
./pde_solver
```

## 🚧 Current Status

I have successfully tested the solver against the 2D heat equation with diffusion coefficient `α = 1`.
The initial condition used was:

```cpp
auto g_x = [](double x, double y){
    return std::sin(M_PI * x) * std::sin(M_PI * y);
};
```

The numerical solution matches the exact analytical solution.

✅ Current features implemented:
- Explicit Euler time integration
- Finite difference spatial discretization
- 2D uniform Cartesian grid
- Modular PDE logic

🛠️ I am currently working on:
- Implementing additional time integration schemes (e.g., Runge-Kutta, Crank-Nicolson)
- Integrating a more dynamic approach for defining PDE equations to make them more customizable
- Adding observer mechanisms to the solver:
  - CSV result exporters
  - Output manager interfaces
  - Real-time logging and diagnostics


## 📜 License

This project is open-source and licensed under the MIT License.

---

> Developed with ❤️ by me