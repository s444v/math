#ifndef S21_MATH_H
#define S21_MATH_H

#include <limits.h>

#define s21_nan 0.0 / 0.0
#define s21_positive_inf +1.0 / 0.0
#define s21_negative_inf -1.0 / 0.0
#define s21_is_nan(x) (x != x)
#define s21_is_inf(x) (x == s21_positive_inf || x == s21_negative_inf)

/*Константные значения*/
#define s21_EXP 2.71828182845904523536028747
#define s21_PI 3.14159265358979323846
#define s21_ln_2 0.693147180559945309417232
#define s21_eps 0.000001

/*Функции проекта*/
int s21_abs(int x);              //модуль для инта
long double s21_ceil(double x);  // округление в +
long double s21_exp(double x);  // возведение ехр в степень
long double s21_fabs(double x);            // модуль для флоута
long double s21_floor(double x);           // округление в -
long double s21_fmod(double x, double y);  // мод для флоута
long double s21_log(double x);  // натуральный логарифм от х
long double s21_pow(double base,
                    double exp);  // возведение в рациональную стпень
long double s21_sqrt(double x);  // корень от х
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_atan(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

/*Дополнительные функции*/
long double s21_avarage(long double a,
                        long double b);  // Среднее арифметико-геометрическое
long double s21_pow_int(double base,
                        long long int exp);  // возведение в натуральную степень
long double s21_factorial(long long int n);  // факториал числа

#endif