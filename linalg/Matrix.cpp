module;
#include <cstddef>
#include <cstdio>
export module Matrix;
import Numeric;
export template<Numeric T, std::size_t Rows, size_t Columns> struct Matrix {
    std::size_t rows = Rows;
    std::size_t columns = Columns;
    T* elements;
    Matrix() {
      this->elements = new T[Rows * Columns];
    }

    void print() {
      for (size_t n = 0; Rows > n; n++) {
        for (size_t m = 0; Columns > m; m++) {
          std::printf("%g, ", this->elements[Columns * n + m]);
        }
        std::printf("\n");
      }
    }

    template<std::size_t N, std::size_t M, std::size_t K>
    static Matrix<T, N, K> multiply(Matrix<T, N, M> a, Matrix<T, M, K> b) {
      Matrix<T, N, K> result = Matrix<T, N, K>();
      for (size_t n = 0; N > n; n++) {
        for (size_t k = 0; K > k; k++) {
          for (size_t m = 0; M > m; m++) {
            result.elements[K * n + k] += a.elements[M * n + m] * b.elements[K * m + k];
          }
        }
      }
      return result;
    }
    static void test() {
      const std::size_t n = 2;
      const std::size_t m = 3;
      const std::size_t k = 4;
      Matrix<double, n, m> a = Matrix<double, n, m>();
      Matrix<double, m, k> b = Matrix<double, m, k>();
      for (std::size_t element = 0; n * m > element; element++) {
        a.elements[element] = element;
      }
      for (std::size_t element = 0; m * k > element; element++) {
        b.elements[element] = element;
      }
      a.print();
      printf("-----\n");
      b.print();
      printf("-----\n");
      Matrix<double, n, k> c = multiply(a, b);
      c.print();
    }
}; // struct Matrix
