#include "s21_math.h"

long double s21_sqrt(double x) {
  long double root = x / 2;
  if (s21_is_nan(x) || x == s21_negative_inf || x < 0)
    root = s21_nan;
  else if (x == s21_positive_inf || x == 0)
    root = x;
  else {
    while (s21_fabs(root * root - x) >= s21_eps) {
      root = 0.5 * (root + x / root); /*Формула Ньютона*/
    }
  }
  return root;
}
