#include <memory>
#include "IGrid2D.hpp"

enum class Grid2DType{
    Uniform,
    DefaultUniform,
    NonUniform
};

class Grid2DFactory {
public:
    static std::unique_ptr<IGrid2D> create(Grid2DType type);
};