module;
export module adder;
import subtracter;
export struct adder {
    static int add(int a, int b) {
      return a + subtracter::subtract(a, b);
    }
}; // struct adder
