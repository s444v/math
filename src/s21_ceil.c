#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if (s21_is_nan(x))
    res = s21_nan;
  else if (x == s21_negative_inf)
    res = s21_negative_inf;
  else if (x == s21_positive_inf)
    res = s21_positive_inf;
  else {
    if (x / (int)x == 1) {
      res = x;
    } else {
      if (x > 0) {
        res = (int)x + 1;
      } else if (x < 0) {
        res = (int)x;
      }
    }
  }
  return res;
}