#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (base == s21_negative_inf && exp == s21_negative_inf)
    result = 0;
  else if (base == s21_negative_inf && exp == s21_positive_inf)
    result = s21_positive_inf;
  else if (base < 0 && exp != (long long int)exp)
    result = s21_nan;
  else if (exp == 0)
    result = 1;
  else {
    if (exp / (long long int)exp == 1) {
      result = s21_pow_int(base, exp);
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}