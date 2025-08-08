module;
#include <concepts>
export module Numeric;
export template<class T> concept Numeric = std::is_arithmetic_v<T>;
