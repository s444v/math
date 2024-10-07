#include "s21_math.h"

long double s21_atan(double x) {
  long double sum = 0;
  long double y = x;

  if (x == 1.0 / 0.0)
    sum = 1.57079675;
  else if (x == -1.0 / 0.0)
    sum = -1.57079675;
  else {
    if (x < 1 && x > -1) {
      for (int i = 0; i < 2000; i++)
        sum += ((s21_pow_int(-1, i) * s21_pow_int(x, 1 + (2 * i))) /
                (1 + (2 * i)));
    } else {
      for (int j = 0; j < 7000; j++) {
        y = s21_pow_int(-1, j) * s21_pow_int(x, -1 - (2 * j)) / (1 + (2 * j));
        sum += y;
        if (y < 0) y *= -1;
      }
      sum = s21_PI * s21_sqrt(x * x) / (2 * x) - sum;
    }

    if (x == 1 || x == -1) sum = (x == 1) ? 0.785398 : -0.785398;
  }
  return (sum);
}
