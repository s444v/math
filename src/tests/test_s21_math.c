#include "tests.h"

START_TEST(s21_sin_test) {
  ck_assert_double_nan(s21_sin(NAN));
  ck_assert_double_nan(sin(NAN));
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(sin(INFINITY));
  ck_assert_double_nan(s21_sin(-INFINITY));
  ck_assert_double_nan(sin(-INFINITY));
  long double arr1[] = {2,  3,  10,  20.1421,  40,       21414,
                        -2, -3, -10, -20.1242, -40.12421};
  long double x = -1;
  while (x <= 1) {
    ck_assert_double_eq_tol(s21_sin(x), sin(x), 0.000001);
    x += 0.1;
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq_tol(s21_sin(arr1[i]), sin(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_cos_test) {
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(cos(NAN));
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(cos(INFINITY));
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(cos(-INFINITY));
  long double arr1[] = {2,   3,    10,       20.1421,   40,    21414, -2,
                        -3,  -10,  -20.1242, -40.12421, 0,     1,     -1,
                        0.1, -0.1, 0.5,      -0.5,      0.998, -0.998};
  for (int i = 0; i < 19; i++) {
    ck_assert_double_eq_tol(s21_cos(arr1[i]), cos(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(tan(NAN));
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(tan(INFINITY));
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_nan(tan(-INFINITY));
  long double arr1[] = {2,   3,    10,       20.1421,   40,    21414, -2,
                        -3,  -10,  -20.1242, -40.12421, 0,     1,     -1,
                        0.1, -0.1, 0.5,      -0.5,      0.998, -0.998};
  for (int i = 0; i < 19; i++) {
    ck_assert_double_eq_tol(s21_tan(arr1[i]), tan(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_double_eq_tol(s21_atan(INFINITY), atanl(INFINITY), 0.000001);
  ck_assert_double_eq_tol(s21_atan(-INFINITY), atanl(-INFINITY), 0.000001);
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
  long double arr1[] = {2,   3,    10,       20.1421,   40,    21414, -2,
                        -3,  -10,  -20.1242, -40.12421, 0,     1,     -1,
                        0.1, -0.1, 0.5,      -0.5,      0.998, -0.998};
  long double x = -1;
  while (x <= 1) {
    ck_assert_double_eq_tol(s21_sin(x), sin(x), 0.000001);
    x += 0.1;
  }
  for (int i = 0; i < 19; i++) {
    ck_assert_double_eq_tol(s21_atan(arr1[i]), atan(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asinl(NAN));
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asinl(INFINITY));
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asinl(-INFINITY));
  long double arr1[] = {0, 1, -1, 0.1, -0.1, 0.5, -0.5, 0.998, -0.998};
  long double x = -1;
  while (x <= 1) {
    ck_assert_double_eq_tol(s21_asin(x), asin(x), 0.000001);
    x += 0.1;
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(s21_asin(arr1[i]), asinl(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(acosl(NAN));
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(acosl(INFINITY));
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_nan(acosl(-INFINITY));
  long double arr1[] = {0, 1, -1, 0.1, -0.1, 0.5, -0.5, 0.998, -0.998};
  long double x = -1;
  while (x <= 1) {
    ck_assert_double_eq_tol(s21_acos(x), acos(x), 0.000001);
    x += 0.1;
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(s21_acos(arr1[i]), acos(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(7), abs(7));
  ck_assert_int_eq(s21_abs(-7), abs(-7));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
}
END_TEST

START_TEST(s21_ceil_test) {
  ck_assert_double_eq_tol(s21_ceil(21.2), ceil(21.2), 0.000001);
  ck_assert_double_eq_tol(s21_ceil(-21.2), ceil(-21.2), 0.000001);
  ck_assert_double_eq_tol(s21_ceil(25), ceil(25), 0.000001);
  ck_assert_double_eq_tol(s21_ceil(-212), ceil(-212), 0.000001);
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_double_eq_tol(s21_floor(21.2), floor(21.2), 0.000001);
  ck_assert_double_eq_tol(s21_floor(-21.2), floor(-21.2), 0.000001);
  ck_assert_double_eq_tol(s21_floor(25), floor(25), 0.000001);
  ck_assert_double_eq_tol(s21_floor(-212), floor(-212), 0.000001);
  ck_assert_double_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_double_eq(s21_floor(-INFINITY), floor(-INFINITY));
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_nan(floor(NAN));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_double_eq_tol(s21_fabs(21.2), fabs(21.2), 0.000001);
  ck_assert_double_eq_tol(s21_fabs(-21.2), fabs(-21.2), 0.000001);
  ck_assert_double_eq_tol(s21_fabs(25.0), fabs(25.0), 0.000001);
  ck_assert_double_eq_tol(s21_fabs(-212.0), fabs(-212.0), 0.000001);
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(sqrt(-1));
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     0.0001,
                       21345678, 4,         0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
  long double arr1[] = {-1.9, -3.2, -4.3, -0.5, -2,  -2.5, -6,
                        -8.4, -6.6, 4.5,  3,    2,   1.1,  -0.6,
                        6.6,  2.7,  6.5,  3.3,  2.2, 1.1};
  for (int i = 0; i < 20; i++) {
    ck_assert_double_eq_tol(s21_exp(arr1[i]), exp(arr1[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_nan(log(-INFINITY));
  ck_assert_double_eq(s21_log(0), log(0));
  long double arr[] = {
      5898.467, 8427.928, 5698.0035, 1289.244, 7025.7,    12.1357,  4745.5,
      8187.391, 1015.89,  3155.844,  3954.143, 2862.1,    2782.954, 5097.545,
      2630.4,   1075.747, 1889.786,  1782,     0.0001,    21345678, 4,
      0.3245,   12345,    13456,     0.03213,  324.42342, 50,       0.24};
  for (int i = 0; i < 28; i++) {
    ck_assert_double_eq_tol(s21_log(arr[i]), log(arr[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_fmod_test) {
  long double f_value[] = {4234, 20,      234,    -756,   435,    24.342, 345,
                           645,  2.24234, 53.534, 6456,   1,      0,      -1,
                           34,   64,      9786,   534.53, 756.56, 754};
  long double s_value[] = {8898.07,  6881.63, 1537.52, 5783.31, 2675.7,
                           5560.06,  1240.69, 9348.66, 103.02,  4153.9,
                           250,      29.3,    96.456,  86,      29.5,
                           302.0234, 1,       1947.38, 953,     42};
  for (int i = 0; i < 20; i++) {
    ck_assert_double_eq_tol(s21_fmod(f_value[i], s_value[i]),
                            fmod(f_value[i], s_value[i]), 0.000001);
  }
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_double_eq_tol(s21_pow(203, 6), pow(203, 6), 0.000001);
  ck_assert_double_eq_tol(s21_pow(8, 6.1), pow(8, 6.1), 0.000001);
  ck_assert_double_eq_tol(s21_pow(3.1, 6), pow(3.1, 6), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.1, 3.3), pow(2.1, 3.3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-2, -6), pow(-2, -6), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-3.1, 5), pow(-3.1, 5), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-5, 2), pow(-5, 2), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-8.8, 0), pow(-8.8, 0), 0.000001);
  ck_assert_double_nan(s21_pow(-8.8, -1.1));
  ck_assert_double_nan(pow(-8.8, -1.1));
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
}
END_TEST

Suite *test_s21_math() {
  TCase *tc1_1 = tcase_create("s21_math");

  tcase_add_test(tc1_1, s21_abs_test);    // 1
  tcase_add_test(tc1_1, s21_ceil_test);   // 2
  tcase_add_test(tc1_1, s21_exp_test);    // 3
  tcase_add_test(tc1_1, s21_fabs_test);   // 4
  tcase_add_test(tc1_1, s21_floor_test);  // 5
  tcase_add_test(tc1_1, s21_fmod_test);   // 6
  tcase_add_test(tc1_1, s21_log_test);    // 7
  tcase_add_test(tc1_1, s21_pow_test);    // 8
  tcase_add_test(tc1_1, s21_sqrt_test);   // 9
  tcase_add_test(tc1_1, s21_sin_test);    // 10
  tcase_add_test(tc1_1, s21_cos_test);    // 11
  tcase_add_test(tc1_1, s21_tan_test);    // 12
  tcase_add_test(tc1_1, s21_atan_test);   // 13
  tcase_add_test(tc1_1, s21_asin_test);   // 14
  tcase_add_test(tc1_1, s21_acos_test);   // 15

  Suite *s1 = suite_create("s21_math");
  suite_add_tcase(s1, tc1_1);

  return s1;
}

int main(void) {
  int failed_tests = 0;  // счётчик проваленных тестов
  Suite *test_s21_math_func[] = {test_s21_math(), NULL};

  for (int i = 0; test_s21_math_func[i] != NULL; i++) {
    SRunner *srun = srunner_create(test_s21_math_func[i]);

    srunner_set_fork_status(srun, CK_NOFORK);
    srunner_run_all(srun, CK_NORMAL);

    failed_tests += srunner_ntests_failed(srun);
    srunner_free(srun);
  }
  printf("========= FAILED: %d =========\n", failed_tests);

  return failed_tests == 0 ? 0 : 1;
}