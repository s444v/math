#include "s21_math.h"

long double s21_cos(double x) {
  long double sum = 0;

  if (x != x || x == 1.0 / 0.0 || x == -1.0 / 0.0)
    sum = 0.0 / 0.0;
  else {
    if (x == 0)
      sum = 1;
    else {
      if (x < 0) x = x * -1;

      long double y = x;

      while (x > 2 * s21_PI) x -= 2 * s21_PI;

      for (int n = 0; y > 0.0000001; n++) {
        y = (s21_pow_int(-1, n) * s21_pow_int(x, 2 * n)) / s21_factorial(2 * n);
        sum += y;
        if (y < 0) y *= -1;
      }
    }
  }

  return (sum);
}
