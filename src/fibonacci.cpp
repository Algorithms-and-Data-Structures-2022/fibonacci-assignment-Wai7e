#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {

      return n;
    }
    double itog = pow(1 + sqrt(5), n) - pow((1 - sqrt(5)), n);
    itog = itog / pow(2, n) * sqrt(5);
    return static_cast<int64_t>(round(itog));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    int64_t fib_temp = 0;
    for (int i = 0; i < n - 1; i++) {
      fib_temp = fib_curr;
      fib_curr = fib_prev + fib_curr;
      fib_prev = fib_temp;
    }
    return fib_curr;
  }

  int64_t fib_recursive(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    } else {
      return fib_binet(n - 1) + fib_binet(n - 2);
    }

    // Напишите здесь свой код ...
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      cache[0] = 0;
      cache[1] = 1;
      return cache[n];
    }
    cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
    return cache[n];
  }
  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    return matrix_power(FibMatrix, n)[0][1];

  }  // namespace assignment
}