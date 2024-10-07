#include "s21_math.h"

long double s21_acos(double x) {
  long double sum = 0;
  if (x != x || x == 1.0 / 0.0 || x == -1.0 / 0.0)
    sum = 0.0 / 0.0;
  else {
    if (x > 0 && x < 1 && x != 0) sum = s21_atan(s21_sqrt(1 - (x * x)) / x);
    if (x == 0) sum = 1.570796;
    if (x > -1 && x < 0) sum = s21_PI + s21_atan(s21_sqrt(1 - (x * x)) / x);
    if (x > 1 || x < -1) sum = 0.0 / 0.0;
    if (x == -1) sum = 3.141593;
  }

  return (sum);
}