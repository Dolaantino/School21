#include <check.h>

#include "calc.h"

START_TEST(s21_check_input) {
  int err = 0;
  char string[] = "1+2+3-log(6)*sqrt(10)+ln(10)";
  err = check_input(string);
  ck_assert_int_eq(0, err);

  char string_1[] = "1+2+3*ln()";
  err = check_input(string_1);
  ck_assert_int_eq(2, err);

  char string_2[] = "1.123123+2mod4+(3*7)+sqrt(7)";
  err = check_input(string_2);
  ck_assert_int_eq(0, err);

  char string_3[] = "1+2mod4+3*(7+1)+acos(1/2)+5^2";
  err = check_input(string_3);
  ck_assert_int_eq(0, err);

  char string_4[] = "1+2mod4+3*(7+1d)+asin(1/2)";
  err = check_input(string_4);
  ck_assert_int_eq(1, err);

  char string_5[] = "^1+2mod4+3*(7+1)+atan(1/2)";
  err = check_input(string_5);
  ck_assert_int_eq(1, err);

  char string_6[] = "cos(1/2)+2mod4+3*(7+1)+sin(0)";
  err = check_input(string_6);
  ck_assert_int_eq(0, err);

  char string_7[] = "tan(1/2)+2mod4+3*(7+1)+asin(0)+atan(0)";
  err = check_input(string_7);
  ck_assert_int_eq(0, err);

  char string_8[] = "123456789+";
  err = check_input(string_8);
  ck_assert_int_eq(1, err);

  char string_9[] = "1/2+aco(3)-lo(6)+l(8)-asi(5)+at(3)+tcos(213)^";
  err = check_input(string_9);
  ck_assert_int_eq(1, err);

  char string_10[] = "";
  err = check_input(string_10);
  ck_assert_int_eq(4, err);

  char string_11[] = "!1+4-f+d/";
  err = check_input(string_11);
  ck_assert_int_eq(1, err);

  char string_12[] = "1+4/";
  err = check_input(string_12);
  ck_assert_int_eq(1, err);

  char string_13[] = "1+4*";
  err = check_input(string_13);
  ck_assert_int_eq(1, err);

  char string_14[] = "1+5-4*)";
  err = check_input(string_14);
  ck_assert_int_eq(1, err);

  char string_15[] = "1+((5-4)/410";
  err = check_input(string_15);
  ck_assert_int_eq(3, err);

  char string_16[] = "4mid2+(5-4)";
  err = check_input(string_16);
  ck_assert_int_eq(1, err);

  char string_17[] = "00+(5-4)";
  err = check_input(string_17);
  ck_assert_int_eq(1, err);

  char string_18[] = "*0+(5-4)";
  err = check_input(string_18);
  ck_assert_int_eq(1, err);

  char string_19[] = "1/0 + 2";
  err = check_input(string_19);
  ck_assert_int_eq(5, err);

  char string_20[] = "1+";
  err = check_input(string_20);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(calculator) {
  Node *number_list = NULL;
  double res_21 = 0.0;
  double res_original = 0.0;

  char input[] = "-cos(1)+3";
  number_list = parsing(input);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = -cos(1) + 3;
  ck_assert_double_eq(res_original, res_21);

  char input_1[] = "-0.1+0.2";
  number_list = parsing(input_1);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = -0.1 + 0.2;
  ck_assert_double_eq(res_original, res_21);

  char input_3[] = "2^(2.1+1)-11mod2";
  number_list = parsing(input_3);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = pow(2, (2.1 + 1)) - fmod(11, 2);
  ck_assert_double_eq(res_original, res_21);

  char input_5[] = "sqrt(4.123456789)+3-1.12";
  number_list = parsing(input_5);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = sqrt(4.123456789) + 3 - 1.12;
  ck_assert_double_eq(res_original, res_21);

  char input_6[] = "log(+10.2)-ln(10.2)";
  number_list = parsing(input_6);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = log10(10.2) - log(10.2);
  ck_assert_double_eq(res_original, res_21);

  char input_7[] = "11+(-2)^5";
  number_list = parsing(input_7);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = 11 + pow(-2, 5);
  ck_assert_double_eq(res_original, res_21);

  char input_8[] = "log(10.2)+ln(10.2)";
  number_list = parsing(input_8);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = log10(10.2) + log(10.2);
  ck_assert_double_eq(res_original, res_21);

  char input_9[] = "sqrt(+4+1)+(-3+1)";
  number_list = parsing(input_9);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = sqrt(4 + 1) + (-3 + 1);
  ck_assert_double_eq(res_original, res_21);

  char input_10[] = "sqrt(3+1)-(-3+1)";
  number_list = parsing(input_10);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = sqrt(3 + 1) - (-3 + 1);
  ck_assert_double_eq(res_original, res_21);

  char input_11[] = "+1.1122-(-1)";
  number_list = parsing(input_11);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = +1.1122 - (-1);
  ck_assert_double_eq(res_original, res_21);

  char input_12[] = "sin(x)";
  number_list = parsing(input_12);
  number_list = polish_notation(number_list, 1.1);
  res_21 = calculation(number_list);
  res_original = sin(1.1);

  ck_assert_double_eq(res_original, res_21);

  char input_13[] = "cos(x)";
  number_list = parsing(input_13);
  number_list = polish_notation(number_list, 0);
  res_21 = calculation(number_list);
  res_original = cos(0);
  ck_assert_double_eq(res_original, res_21);

  char input_15[] = "tan(x)";
  number_list = parsing(input_15);
  number_list = polish_notation(number_list, 7);
  res_21 = calculation(number_list);
  res_original = tan(7);
  ck_assert_double_eq(res_original, res_21);

  char input_16[] = "asin(x)";
  number_list = parsing(input_16);
  number_list = polish_notation(number_list, 1);
  res_21 = calculation(number_list);
  res_original = asin(1);
  ck_assert_double_eq(res_original, res_21);

  char input_17[] = "acos(x)";
  number_list = parsing(input_17);
  number_list = polish_notation(number_list, 1);
  res_21 = calculation(number_list);
  res_original = acos(1);
  ck_assert_double_eq(res_original, res_21);

  char input_18[] = "atan(x)";
  number_list = parsing(input_18);
  number_list = polish_notation(number_list, 1);
  res_21 = calculation(number_list);
  res_original = atan(1);
  ck_assert_double_eq(res_original, res_21);

  char input_22[] = "2^(2.1+1)-11mid2";
  int err = check_input(input_22);
  if (err == 0) {
    Node *number_list = parsing(input_22);
    number_list = polish_notation(number_list, 0);
    res_21 = calculation(number_list);
  }
  ck_assert_int_eq(1, err);

  char input_23[] = "2^(2.1+1)+(";
  err = check_input(input_23);
  if (err == 0) {
    Node *number_list = parsing(input_22);
    number_list = polish_notation(number_list, 0);
    res_21 = calculation(number_list);
  }
  ck_assert_int_eq(3, err);

  char input_24[] = "2^(2.1+1)+()";
  err = check_input(input_24);
  if (err == 0) {
    Node *number_list = parsing(input_22);
    number_list = polish_notation(number_list, 0);
    res_21 = calculation(number_list);
  }
  ck_assert_int_eq(2, err);

  char input_25[] = "2^(2.1+1)+2-(3+1)";
  err = check_input(input_25);
  if (err == 0) {
    Node *number_list = parsing(input_22);
    number_list = polish_notation(number_list, 0);
    res_21 = calculation(number_list);
  }
  ck_assert_int_eq(0, err);

  char input_26[] = "cos(x)";
  err = check_input(input_26);
  if (err == 0) {
    Node *number_list = parsing(input_22);
    number_list = polish_notation(number_list, 0);
    res_21 = calculation(number_list);
  }
  ck_assert_int_eq(0, err);
}
END_TEST

Suite *s21_SmartCalc_tests_create() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_SmartCalc");
  tc_core = tcase_create("tests");
  tcase_add_test(tc_core, s21_check_input);
  tcase_add_test(tc_core, calculator);
  suite_add_tcase(s, tc_core);
  return s;
}
int main() {
  Suite *s = s21_SmartCalc_tests_create();
  SRunner *s21_SmartCalc_runner = srunner_create(s);
  int number_failed;
  srunner_run_all(s21_SmartCalc_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_SmartCalc_runner);
  srunner_free(s21_SmartCalc_runner);

  return number_failed == 0 ? 0 : 1;
}