#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  int neg_flag = 0;
  if (x < 0) {
    neg_flag = 1;
  }
  x = s21_fabs(x);
  y = s21_fabs(y);
  while (x > y) {
    x -= y;
  }
  if (x == y) {
    res = 0;
  } else if (neg_flag) {
    res = -x;
  } else {
    res = x;
  }
  return res;
}