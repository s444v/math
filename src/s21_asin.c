#include "s21_math.h"

long double s21_asin(double x) {
  long double sum = 0;
  if (x != x || x == 1.0 / 0.0 || x == -1.0 / 0.0)
    sum = 0.0 / 0.0;
  else {
    if (x > 1 || x < -1) sum = -(0.0 / 0.0);
    if (x < -1) sum = 0.0 / 0.0;
    if (x == 1) sum = 1.570796;
    if (x == -1) sum = -1.570796;
    if (x < 1 && x > -1) sum = s21_atan(x / s21_sqrt(1 - (x * x)));
  }

  return (sum);
}