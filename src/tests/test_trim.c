#include <check.h>

#include "../s21_string.h"

START_TEST(test_trim) {
  char str1[128];
  char answ[128];
  char *tok1;
  char *tok2;

  strcpy(str1, "- - - Test- - - ");
  strcpy(answ, "Test");
  tok1 = s21_trim(str1, "- ");
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);

  strcpy(str1, "- - - Test- - - ");
  strcpy(answ, "- - - Test- - -");
  tok1 = s21_trim(str1, "");
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);

  tok1 = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_eq(tok1, S21_NULL);

  tok1 = s21_trim(S21_NULL, "");
  ck_assert_ptr_eq(tok1, S21_NULL);
}
END_TEST
