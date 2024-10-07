#include "s21_math.h"

long double s21_floor(double x) {
  long double res = 0;
  if (s21_is_nan(x) || s21_is_inf(x))
    res = x;
  else {
    if (x / (int)x == 1) {
      res = x;
    } else {
      if (x > 0) {
        res = (int)x;
      } else if (x < 0) {
        res = (int)x - 1;
      }
    }
  }
  return res;
}