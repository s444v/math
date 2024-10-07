#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (x == s21_positive_inf)
    result = s21_positive_inf;
  else if (x == 0)
    result = s21_negative_inf;
  else if (x < 0)
    result = s21_nan;
  else {
    long double compare = 0;
    int e_repeat = 0;
    for (; x >= s21_EXP; e_repeat++) x /= s21_EXP;
    for (int i = 0; i < 20; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    result += e_repeat;
  }
  return result;
}

/*Формула НЬЮТОНА
    // int e_repeat=0;
    // for (; x >= s21_EXP; e_repeat++) x /= s21_EXP;
    // long double s = x*65536;
    // long double result =(s21_PI/(2*avarage(1.0,4.0/s))-(16*s21_ln_2));
    // return result+e_repeat;
*/
/*

long double s21_avarage(long double a,long double b){ Среднее
арифметико-геометрическое int k =0; long double tmpa=a,tmpb=b; while (k<16){
        a=(tmpa+tmpb)/2;
        b=s21_sqrt(tmpa*tmpb);
        tmpa=a;
        tmpb=b;
        k+=1;
    }
    return a;
}
*/