module;
#include <cstddef>
export module linalg;
import Numeric;
import Matrix;
export struct linalg {
    static constexpr char TAG[] = "espcord::model";
    struct placeholder { };
    template<Numeric T, std::size_t N = 0, std::size_t M = 0>
    using Matrix = Matrix<T, N, M>;
}; // struct linalg
