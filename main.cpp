module;
#include <cstdio>
export module main;
import arithmetic;
import linalg;
import Image;
int main() {
  // std::printf("hello world, %f\n", linalg::Matrix<double>::add(3, 4));
  std::printf("hello world, %d\n", 5);
  linalg::Matrix<double>::test();
  const Image image = Image("");
}
