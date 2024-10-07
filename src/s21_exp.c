#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  int k = 1;
  if (x == s21_negative_inf)
    result = 0;
  else {
    while (k < 128) { /*Ряд Тейлора*/
      result += (s21_pow_int(x, k) / s21_factorial(k));
      k++;
    }
  }
  return result;
}

long double s21_pow_int(double base, long long int exp) {
  long double result = 1;
  int sign = 0;
  if (exp > 0) {
    sign = 1;
  } else {
    exp *= -1;
    base = 1.0 / base;
  }
  while (exp > 0) {
    if (exp % 2 == 0) {
      exp /= 2;
      if (sign) {
        base *= base;
      } else {
        base *= base;
      }
    } else {
      exp--;
      result *= base;
    }
  }
  return result;
}

long double s21_factorial(long long int n) {
  long double f = 1;
  for (long long int i = 2; i <= n; i++) f *= i;
  return f;
}