#include <check.h>
#include <string.h>
#include <stdlib.h>
#include "s21_string.h"
#include "data_test.h"
#include <limits.h>

START_TEST(memchr_test) {
  char src1[15] = "1234567890";
  char src2[3] = {'\0', '\0', '\0'};
  char src3[0];
  void *res1, *res2;

  res1 = s21_memchr(src1, '4', 10);
  res2 = memchr(src1, '4', 10);
  ck_assert_ptr_eq(res1, res2);
  res1 = s21_memchr(src2, '\0', 2);
  res2 = memchr(src2, '\0', 2);
  ck_assert_ptr_eq(res1, res2);
  res1 = s21_memchr(src3, 'w', 10);
  res2 = memchr(src3, 'w', 10);
  ck_assert_ptr_eq(res1, res2);
  ck_assert_ptr_eq(s21_memchr(test1, 123, 2), memchr(test1, 123, 2));
  ck_assert_ptr_eq(s21_memchr(test2, 12, 2), memchr(test2, 12, 2));
  ck_assert_ptr_eq(s21_memchr(test3, 123, 2), memchr(test3, 123, 2));
  ck_assert_ptr_eq(s21_memchr(test4, 4, 2), memchr(test4, 4, 2));
  ck_assert_ptr_eq(s21_memchr(test5, 4, 2), memchr(test5, 4, 2));
  ck_assert_ptr_eq(s21_memchr(test6, 123, 2), memchr(test6, 123, 2));
  ck_assert_ptr_eq(s21_memchr(test7, 123, 2), memchr(test7, 123, 2));
}
END_TEST

  START_TEST(memcmp_test) {
  char src1[7] = "Abc";
  char dst1[7] = "ABC";
  char src2[3] = "\0";
  char dst2[3] = "\0";
  char src3[6] = "12345";
  char dst3[6] = "12345";

  ck_assert_int_eq(s21_memcmp(src1, dst1, 1), memcmp(src1, dst1, 1));
  ck_assert_int_eq(s21_memcmp(src2, dst2, 1), memcmp(src2, dst2, 1));
  ck_assert_int_eq(s21_memcmp(src3, dst3, 5), memcmp(src3, dst3, 5));
  ck_assert_int_eq(s21_memcmp(src1, test1, 5), -1);
  ck_assert_int_eq(s21_memcmp(src2, test2, 2), -1);
  ck_assert_int_eq(s21_memcmp(src2, test5, 1), -1);
}
END_TEST

START_TEST(memcpy_test) {
  char src1[15] = "qwert";
  char dst1[3] = "123";
  char src2[11];
  char dst2[11] = "1234567890";
  char src3[3];
  char dst3[3] = "123";
  void *res1, *res2;

  res1 = s21_memcpy(src1, dst1, 3);
  res2 = memcpy(src1, dst1, 3);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memcpy(src1, test1, 3), memcpy(src1, test1, 3));
  ck_assert_str_eq(s21_memcpy(dst1, test2, 3), memcpy(dst1, test2, 3));
  res1 = s21_memcpy(src2, dst2, 10);
  res2 = memcpy(src2, dst2, 10);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memcpy(src2, test3, 4), memcpy(src2, test3, 4));
  ck_assert_str_eq(s21_memcpy(dst2, test4, 4), memcpy(dst2, test4, 4));
  res1 = s21_memcpy(src3, dst3, 3);
  res2 = memcpy(src3, dst3, 3);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memcpy(src3, test5, 3), memcpy(src3, test5, 3));
  ck_assert_str_eq(s21_memcpy(src3, test6, 3), memcpy(src3, test6, 3));
  ck_assert_str_eq(s21_memcpy(dst3, test7, 2), memcpy(dst3, test7, 2));
  ck_assert_str_eq(s21_memcpy(test9, test8, 20), memcpy(test9, test8, 20));
  ck_assert_str_eq(s21_memcpy(test8, test7, 1), memcpy(test8, test7, 1));
  ck_assert_str_eq(s21_memcpy(test7, test8, 45), memcpy(test7, test8, 45));
  ck_assert_str_eq(s21_memcpy(test7, test5, 1), memcpy(test7, test5, 1));
  ck_assert_str_eq(s21_memcpy(test5, test7, 1), memcpy(test5, test7, 1));
  ck_assert_str_eq(s21_memcpy(test7, test5, 0), memcpy(test7, test5, 0));
  ck_assert_str_eq(s21_memcpy(test5, test7, 0), memcpy(test5, test7, 0));

    char str1[] = "abcd", str2[] = "efgh", str3[] = "efghi", str4[] = "",
            str5[] = "abcd", str6[] = "efgh", str7[] = "efghi", str8[] = "";

    s21_memcpy(str1, str2, 4);
    memcpy(str5, str6, 4);
    ck_assert_pstr_eq(str1, str5);

    s21_memcpy(str1, str3, 4);
    memcpy(str5, str7, 4);
    ck_assert_pstr_eq(str1, str5);

    s21_memcpy(str3, str1, 1);
    memcpy(str7, str5, 1);
    ck_assert_pstr_eq(str3, str7);

    s21_memcpy(str1, str4, 1);
    memcpy(str5, str8, 1);
    ck_assert_pstr_eq(str1, str5);
}
END_TEST

START_TEST(memmove_test) {
  char src1[15] = "qwert";
  char dst1[3] = "123";
  char src2[11];
  char dst2[11] = "1234567890";
  char src3[3];
  char dst3[3] = "123";
  void *res1, *res2;

  res1 = s21_memmove(src1, dst1, 3);
  res2 = memmove(src1, dst1, 3);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memmove(src1, test1, 3), memmove(src1, test1, 3));
  res1 = s21_memmove(src2, dst2, 10);
  res2 = memmove(src2, dst2, 10);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memmove(src2, test1, 10), memmove(src2, test1, 10));
  res1 = s21_memmove(src3, dst3, 3);
  res2 = memmove(src3, dst3, 3);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memmove(src3, test3, 3), memmove(src3, test3, 3));
}
END_TEST

START_TEST(memset_test) {
  char src1[15] = "1234567890";
  char src2[11] = "123";
  char src3[3];
  void *res1, *res2;

  res1 = s21_memset(src1, '1', 11);
  res2 = memset(src1, '1', 11);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memset(test3, 'q', 3), memset(test3, 'q', 3));
  res1 = s21_memset(src2, '\0', 2);
  res2 = memset(src2, '\0', 2);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memset(test4, 1, 2), memset(test4, 1, 2));
  res1 = s21_memset(src3, 'w', 2);
  res2 = memset(src3, 'w', 2);
  ck_assert_str_eq(res1, res2);
  ck_assert_str_eq(s21_memset(test5, '0', 1), memset(test5, '0', 1));
}
END_TEST

START_TEST(strlen_test) {
  s21_size_t res1, res2;

  res1 = s21_strlen("Lol");
  res2 = strlen("Lol");
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strlen(test1), strlen(test1));
  res1 = s21_strlen("");
  res2 = strlen("");
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strspn_test) {
  s21_size_t res1, res2;

  res1 = s21_strspn("123456789", "312");
  res2 = strspn("123456789", "312");
  ck_assert_int_eq(res1, res2);
  res1 = s21_strspn("", "312");
  res2 = strspn("", "312");
  ck_assert_int_eq(res1, res2);
  res1 = s21_strspn("123456789", "");
  res2 = strspn("123456789", "");
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strspn(test1, test2), strspn(test1, test2));
  ck_assert_int_eq(s21_strspn(test3, test4), strspn(test3, test4));
  ck_assert_int_eq(s21_strspn(test5, test6), strspn(test5, test6));
  ck_assert_int_eq(s21_strspn(test7, test1), strspn(test7, test1));
  ck_assert_int_eq(s21_strspn(test2, test3), strspn(test2, test3));
}
END_TEST

START_TEST(strcspn_test) {
  s21_size_t res1, res2;

  res1 = s21_strcspn("123456789", "9876");
  res2 = strcspn("123456789", "9876");
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strcspn(test7, test1), strcspn(test7, test1));
  res1 = s21_strcspn("", "9876");
  res2 = strcspn("", "9876");
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strcspn(test7, test1), strcspn(test7, test1));
  res1 = s21_strcspn("123456789", "");
  res2 = strcspn("123456789", "");
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strcspn(test7, test1), strcspn(test7, test1));
  ck_assert_int_eq(s21_strcspn(test8, test9), strcspn(test9, test9));
}
END_TEST

START_TEST(strcmp_test) {
  char str2[4] = "Kek";
  int res1, res2;
  res1 = s21_strcmp("Lol", str2);
  res2 = strcmp("Lol", str2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strcmp(test7, test1), strcmp(test7, test1));
  ck_assert_int_eq(s21_strcmp(str2, test3), strcmp(str2, test3));
  ck_assert_int_eq(s21_strcmp("kEk", test2), strcmp("kEk", test2));
  ck_assert_int_eq(s21_strcmp(test8, test9), strcmp(test8, test9));
  ck_assert_int_eq(s21_strcmp(test1, test2), strcmp(test1, test2));
}
END_TEST

START_TEST(strncmp_test) {
  char str1[4] = "Lol";
  char str2[4] = "Kek";
  int res1, res2;
  res1 = s21_strncmp(str1, str2, 2);
  res2 = strncmp(str1, str2, 2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(s21_strncmp(test7, test1, 3), strncmp(test7, test1 , 3));
  ck_assert_int_eq(s21_strncmp(test1, test2, 9), strncmp(test1, test2 , 9));
  ck_assert_int_eq(s21_strncmp(test3, test4, 3), strncmp(test3, test4 , 3));
}
END_TEST

START_TEST(strcpy_test) {
  char str1[4] = "Lol";
  char str2[4] = "Kek";
  char str3[1] = "";
  char str4[1] = "";
  char *result, *result2;

  result = s21_strcpy(str1, str2);
  result2 = strcpy(str1, str2);
  ck_assert_str_eq(result, result2);
  result = s21_strcpy(str3, str4);
  result2 = strcpy(str3, str4);
  ck_assert_str_eq(result, result2);
  ck_assert_str_eq(s21_strcpy(test1, test2), strcpy(test1, test2));
  ck_assert_str_eq(s21_strcpy(test3, test4), strcpy(test3, test4));
  ck_assert_str_eq(s21_strcpy(test5, test6), strcpy(test5, test6));
}
END_TEST

START_TEST(strncpy_test) {
  ck_assert_str_eq(s21_strncpy(test1, test2, 4), strncpy(test1, test2, 4));
  ck_assert_str_eq(s21_strncpy(test3, test4, 3), strncpy(test3, test4, 3));
  ck_assert_str_eq(s21_strncpy(test5, test6, 3), strncpy(test5, test6, 3));

  ck_assert_str_eq(s21_strncpy(test7, test5, 1), strncpy(test7, test5, 1));
  ck_assert_str_eq(s21_strncpy(test5, test7, 1), strncpy(test5, test7, 1));
  ck_assert_str_eq(s21_strncpy(test7, test5, 0), strncpy(test7, test5, 0));
  ck_assert_str_eq(s21_strncpy(test5, test7, 0), strncpy(test5, test7, 0));

    char strn1[100] = "iamgroot";
    char strn2[100] = "ironman";
    char* strn3 = s21_strncpy(strn1, strn2, 1);
    char* strn4 = strncpy(strn1, strn2, 1);
    ck_assert_str_eq(strn3, strn4);

    char str1[] = "kjzxnvkjbsdfjhkbbds", str2[] = "jsdjsdfkjdsfjh", str3[] = "",
            str4[] = "kjzxnvkjbsdfjhkbbds", str5[] = "jsdjsdfkjdsfjh", str6[] = "";

    s21_strncpy(str1, str2, 5);
    strncpy(str4, str5, 5);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str2, 20);
    strncpy(str4, str5, 20);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str2, 15);
    strncpy(str4, str5, 15);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str2, str1, 8);
    strncpy(str5, str4, 8);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str2, str1, 15);
    strncpy(str5, str4, 15);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str3, 8);
    strncpy(str4, str6, 8);
    ck_assert_str_eq(str1, str4);
}
END_TEST

START_TEST(strcat_test) {
  char str1[10] = "Lol";
  char str2[4] = "Kek";
  char str3[4] = "";
  char *result, *result2;

  result = s21_strcat(str1, str2);
  result2 = strcat(str1, str2);
  ck_assert_str_eq(result, result2);
  result = s21_strcat(str1, str3);
  result2 = strcat(str1, str3);
  ck_assert_str_eq(result, result2);
  ck_assert_str_eq(s21_strcat(test1, test2), strcat(test1, test2));
  ck_assert_str_eq(s21_strcat(test3, test4), strcat(test3, test4));
  ck_assert_str_eq(s21_strcat(test5, test6), strcat(test5, test6));
  ck_assert_str_eq(s21_strcat(test1, test7), strcat(test1, test7));
}
END_TEST

START_TEST(strncat_test) {
  char str[8] = "Lol";
  char str2[4] = "Kek";
  char str1[8] = "Lol";
  char *result, *result2;

  result = s21_strncat(str, str2, 2);
  result2 = strncat(str, str2, 2);
  ck_assert_str_eq(result, result2);

  result = s21_strncat(str1, str2, 2);
  result2 = strncat(str1, str2, 2);
  ck_assert_str_eq(result, result2);
  ck_assert_str_eq(s21_strncat(test1, test2, 7), strncat(test1, test2, 7));
  ck_assert_str_eq(s21_strncat(test3, test4, 3), strncat(test3, test4, 3));
  ck_assert_str_eq(s21_strncat(test5, test6, 3), strncat(test5, test6, 3));
  ck_assert_str_eq(s21_strncat(test1, test7, 2), strncat(test1, test7, 2));
}
END_TEST

START_TEST(strchr_test) {
  char str1[7] = "School";
  char *result, *result2;

  result = s21_strchr(str1, 111);
  result2 = strchr(str1, 111);
  ck_assert_ptr_eq(result, result2);
  ck_assert_ptr_eq(s21_strchr(test1, 'e'), strchr(test1, 'e'));
  ck_assert_ptr_eq(s21_strchr(test2, 'w'), strchr(test2, 'w'));
  ck_assert_ptr_eq(s21_strchr(test3, 0), strchr(test3, 0));
  ck_assert_ptr_eq(s21_strchr(test4, ' '), strchr(test4, ' '));
  ck_assert_ptr_eq(s21_strchr(test5, 'y'), strchr(test5, 'y'));
  ck_assert_ptr_eq(s21_strchr(test6, 24), strchr(test6, 24));
  ck_assert_ptr_eq(s21_strchr(test7, 78), strchr(test7, 78));
}
END_TEST

START_TEST(strrchr_test) {
  ck_assert_ptr_eq(s21_strrchr(test1, '\n'), strrchr(test1, '\n'));
  ck_assert_ptr_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
  ck_assert_ptr_eq(s21_strrchr(test3, 5), strrchr(test3, 5));
  ck_assert_str_eq(s21_strrchr(test4, ' '), strrchr(test4, ' '));
  ck_assert_str_eq(s21_strrchr(test5, ' '), strrchr(test5, ' '));
  ck_assert_ptr_eq(s21_strrchr(test6, ' '), strrchr(test6, ' '));
  ck_assert_ptr_eq(s21_strrchr(test7, 78), strrchr(test7, 78));
    char* str = "iamgroot\0";
    ck_assert_str_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
    ck_assert_str_eq(s21_strrchr(str, 111), strrchr(str, 111));

    char str1[] = ";odsagjnpasdun 1242149215", str2[] = "";
    ck_assert_pstr_eq(s21_strrchr(str1, 'a'), strrchr(str1, 'a'));
    ck_assert_pstr_eq(s21_strrchr(str1, 100), strrchr(str1, 100));
    ck_assert_pstr_eq(s21_strrchr(str1, '/'), strrchr(str1, '/'));
    ck_assert_pstr_eq(s21_strrchr(str1, 98), strrchr(str1, 98));
    ck_assert_pstr_eq(s21_strrchr(str2, 'a'), strrchr(str2, 'a'));
    ck_assert_pstr_eq(s21_strrchr(str2, ' '), strrchr(str2, ' '));
    ck_assert_pstr_eq(s21_strrchr(str2, 56), strrchr(str2, 56));
}
END_TEST

START_TEST(strpbrk_test) {
  char str1[7] = "School";
  char str2[4] = "Hole";
  char *result, *result2;

  result = s21_strpbrk(str1, str2);
  result2 = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, result2);
  ck_assert_ptr_eq(s21_strpbrk(test7, str2), strpbrk(test7, str2));
  ck_assert_ptr_eq(s21_strpbrk(test1, str1), strpbrk(test1, str1));
  ck_assert_ptr_eq(s21_strpbrk(test2, str2), strpbrk(test2, str2));
  ck_assert_ptr_eq(s21_strpbrk(test3, test4), strpbrk(test3, test4));
  ck_assert_ptr_eq(s21_strpbrk(test5, test6), strpbrk(test5, test6));
  ck_assert_ptr_eq(s21_strpbrk(str2, str2), strpbrk(str2, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strerror_test) {
  char *src, *src1, *src2, *src3;
  src = s21_strerror(131);
  ck_assert_str_eq(src, strerror(131));

  src1 = s21_strerror(70);
  ck_assert_str_eq(src1, strerror(70));
  src2 = s21_strerror(-1500);
  ck_assert_str_eq(src2, strerror(-1500));
  src3 = s21_strerror(1500);
  ck_assert_str_eq(src3, strerror(1500));
}
END_TEST

START_TEST(strstr_test) {
  char str1[7] = "Lol";
  char str2[4] = "ol";
  char str3[7] = "";
  char str4[4] = "";
  char *result, *result2;

  result = s21_strstr(str1, str2);
  result2 = strstr(str1, str2);
  ck_assert_ptr_eq(result, result2);

  result = s21_strstr(str3, str4);
  result2 = strstr(str3, str4);
  ck_assert_ptr_eq(result, result2);
  ck_assert_ptr_eq(s21_strstr(test7, str2), strstr(test7, str2));
  ck_assert_ptr_eq(s21_strstr(test1, str1), strstr(test1, str1));
  ck_assert_ptr_eq(s21_strstr(test2, str2), strstr(test2, str2));
  ck_assert_ptr_eq(s21_strstr(test3, test4), strstr(test3, test4));
  ck_assert_ptr_eq(s21_strstr(test5, test6), strstr(test5, test6));
  ck_assert_ptr_eq(s21_strstr(str2, str2), strstr(str2, str2));
  ck_assert_ptr_eq(s21_strstr(str2, str1), strstr(str2, str1));
  ck_assert_ptr_eq(s21_strstr(test1, test1), strstr(test1, test1));
}
END_TEST

START_TEST(strtok_test) {
  char str[] = "School-21";
  char *tok1 = s21_strtok(str, "-");
  char *tok2 = strtok(str, "-");
  char *tok3 = s21_strtok(str, "");
  char *tok4 = strtok(str, "");
  char *tok5 = s21_strtok(str, "oo");
  char *tok6 = strtok(str, "oo");
  char *tok7 = s21_strtok(str, "Sc");
  char *tok8 = strtok(str, "Sc");
  char *tok9 = s21_strtok(str, "21");
  char *tok10 = strtok(str, "21");

  ck_assert_str_eq(tok1, tok2);
  ck_assert_str_eq(tok3, tok4);
  ck_assert_str_eq(tok5, tok6);
  ck_assert_str_eq(tok7, tok8);
  ck_assert_str_eq(tok9, tok10);
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, "-"), strtok(test10, "-"));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, "a"), strtok(test10, "a"));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));
  ck_assert_str_eq(s21_strtok(test10, " "), strtok(test10, " "));

    char str0[] = "iamgroot";
    char* str1 = s21_strtok(str0, "");
    char* str2 = strtok(str0, "");
    char* str3 = s21_strtok(str0, "I");
    char* str4 = strtok(str0, "I");
    char* str5 = s21_strtok(str0, "am");
    char* str6 = strtok(str0, "am");
    char* str7 = s21_strtok(str0, "groot");
    char* str8 = strtok(str0, "groot");
    ck_assert_str_eq(str1, str2);
    ck_assert_str_eq(str3, str4);
    ck_assert_str_eq(str5, str6);
    ck_assert_str_eq(str7, str8);

    char arr1[100] = "My name is Root. Hello world!", *parr1 = arr1,
            arr2[100] = "My name is Root. Hello world!", *parr2 = arr2;

    s21_strtok(parr1, " .");
    strtok(parr2, " .");
    ck_assert_pstr_eq(parr1, parr2);

    parr1 = s21_strtok(s21_NULL, " .");
    parr2 = strtok(s21_NULL, " .");
    ck_assert_pstr_eq(parr1, parr2);

    parr1 = s21_strtok(parr1, "x");
    parr2 = strtok(parr2, "x");
    ck_assert_pstr_eq(parr1, parr2);
}
END_TEST

START_TEST(trim_test) {
  char *str1 = "aboba";
  char *str2 = "ao";
  char *str3 = "abo";
  void *result, *result1;

  result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "bob");
  free(result);

  result = s21_trim(str1, str3);
  result1 = "";
  ck_assert_str_eq(result, result1);
  free(result);

  ck_assert_str_eq(s21_trim(test1, "H"), "ello world\0");
  ck_assert_str_eq(s21_trim(test2, "Hello"), " world\n\0");
  ck_assert_str_eq(s21_trim(test3, "a"), "\n\0");
  ck_assert_str_eq(s21_trim(test4, " "), "\n\0");
  ck_assert_str_eq(s21_trim(test5, " "), "");
    char *res = s21_trim("testc", "c");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_trim(" test ", " ");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_trim(" ", " ");
    ck_assert_str_eq(res, "");
    if (res)
        free(res);

    res = s21_trim("*te*st*", "*");
    ck_assert_str_eq(res, "te*st");
    if (res)
        free(res);

    res = s21_trim(" te st001", " ");
    ck_assert_str_eq(res, "te st001");
    if (res)
        free(res);

    res = s21_trim(" /*()", ")(/ *");
    ck_assert_str_eq(res, "");
    if (res)
        free(res);
}
END_TEST

START_TEST(insert_test) {
//  char *str1 = "Aboba";
//  char *str2 = "kek";
//  char *str3 = "";
//  char *result = s21_NULL;
//
//  result = s21_insert(str1, str2, 2);
//  ck_assert_str_eq(result, "Abkekoba");
//  free(result);
//  result = s21_insert(str1, str3, 6);
//  ck_assert_ptr_eq(result, s21_NULL);
//  free(result);
//
//  ck_assert_str_eq(s21_insert(test1, test2, 3), "HelHello world\nlo world\0");
//  ck_assert_str_eq(s21_insert(test2, test3, 1), "Ha\nello world\n\0");
//  ck_assert_str_eq(s21_insert(test3, test4, 2), "a\n \n\0");
//  ck_assert_str_eq(s21_insert(test4, test5, 2), " \n \0");
//  ck_assert_str_eq(s21_insert(test6, test7, 0), "\n\0");
//  ck_assert_str_eq(s21_insert(test7, test1, 0), "Hello world\0");
//  ck_assert_str_eq(s21_insert(test1, test2, 0), "Hello world\nHello world\0");

    char *str1 = "Test";
    char *str2 = "quest";
    char *res = s21_NULL;

    res = s21_insert(str1, str2, 2);
    ck_assert_str_eq(res, "Tequestst");
    if (res)
        free(res);

    str1 = "The test";
    str2 = " perfect";
    res = s21_insert(str1, str2, 3);
    ck_assert_str_eq(res, "The perfect test");
    if (res)
        free(res);

    str1 = "Insert in";
    str2 = " end";
    res = s21_insert(str1, str2, 9);
    ck_assert_str_eq(res, "Insert in end");
    if (res)
        free(res);

    str1 = " with insert";
    str2 = "Start";
    res = s21_insert(str1, str2, 0);
    ck_assert_str_eq(res, "Start with insert");
    if (res)
        free(res);

    str1 = "Newspace";
    str2 = " ";
    res = s21_insert(str1, str2, 3);
    ck_assert_str_eq(res, "New space");
    if (res)
        free(res);

    str1 = "";
    str2 = " ";
    res = s21_insert(str1, str2, 0);
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);
}
END_TEST

START_TEST(toupper_test) {
  char *result = s21_to_upper("lol");
  ck_assert_str_eq(result, "LOL");
  result = s21_to_upper("123_lol_321");
  ck_assert_str_eq(result, "123_LOL_321");
  free(result);

  ck_assert_str_eq(s21_to_upper(test1), "HELLO WORLD\0");
  ck_assert_str_eq(s21_to_upper(test2), "HELLO WORLD\n\0");
  ck_assert_str_eq(s21_to_upper(test3), "A\n\0");
  ck_assert_str_eq(s21_to_upper(test4), " \n\0");
  ck_assert_str_eq(s21_to_upper(test5), " \0");
  ck_assert_str_eq(s21_to_upper(test6), "\n\0");
  ck_assert_str_eq(s21_to_upper(test7), "\0");

    char *res = s21_to_upper("test");
    ck_assert_str_eq(res, "TEST");
    if (res)
        free(res);

    res = s21_to_upper(" t e s t");
    ck_assert_str_eq(res, " T E S T");
    if (res)
        free(res);

    res = s21_to_upper("test001");
    ck_assert_str_eq(res, "TEST001");
    if (res)
        free(res);

    res = s21_to_upper("!test!");
    ck_assert_str_eq(res, "!TEST!");
    if (res)
        free(res);

    res = s21_to_upper(" ");
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);

    res = s21_to_upper("!*_*!");
    ck_assert_str_eq(res, "!*_*!");
    if (res)
        free(res);
}
END_TEST

START_TEST(tolower_test) {
  char *result = s21_to_lower("LOL");
  ck_assert_str_eq(result, "lol");
  result = s21_to_lower("123_LOL_321");
  ck_assert_str_eq(result, "123_lol_321");
  free(result);

  ck_assert_str_eq(s21_to_lower(test1), "hello world\0");
  ck_assert_str_eq(s21_to_lower(test2), "hello world\n\0");
  ck_assert_str_eq(s21_to_lower(test3), "a\n\0");
  ck_assert_str_eq(s21_to_lower(test4), " \n\0");
  ck_assert_str_eq(s21_to_lower(test5), " \0");
  ck_assert_str_eq(s21_to_lower(test6), "\n\0");
  ck_assert_str_eq(s21_to_lower(test7), "\0");

    char *res = s21_to_lower("TEST");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_to_lower(" T E S T");
    ck_assert_str_eq(res, " t e s t");
    if (res)
        free(res);

    res = s21_to_lower("TEST001");
    ck_assert_str_eq(res, "test001");
    if (res)
        free(res);

    res = s21_to_lower("!TEST!");
    ck_assert_str_eq(res, "!test!");
    if (res)
        free(res);

    res = s21_to_lower(" ");
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);

    res = s21_to_lower("!*_*!");
    ck_assert_str_eq(res, "!*_*!");
    if (res)
        free(res);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char sc[1000] = {};
  char or[1000] = {};
  char orig[1000] = {};
  int var1[255] = {1221, 0, -1472};
  long int var2[255] = {456456456, -123123123, 7842378};
  short int var3[255] = {456, 0, -159};

  sprintf(or, "%c", 's');
  s21_sprintf(sc, "%c", 's');
  ck_assert_str_eq(or, sc);
  sprintf(or, "%-7c", '4');
  s21_sprintf(sc, "%-7c", '4');
  ck_assert_str_eq(or, sc);

  ck_assert_int_eq(s21_sprintf(sc, "%c", 's'), sprintf(or, "%c", 's'));
  ck_assert_int_eq(s21_sprintf(sc, "%c", '#'), sprintf(or, "%c", '#'));
  ck_assert_int_eq(s21_sprintf(sc, "%-7c", 'k'), sprintf(or, "%-7c", 'k'));

  for (s21_size_t i = 0; i < 3; i++) {
    sprintf(or, "%d", var1[i]);
    s21_sprintf(sc, "%d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-d", var1[i]);
    s21_sprintf(sc, "%-d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%10d", var1[i]);
    s21_sprintf(sc, "%10d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+d", var1[i]);
    s21_sprintf(sc, "%-+d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- d", var1[i]);
    s21_sprintf(sc, "%- d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+d", var1[i]);
    s21_sprintf(sc, "%+d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%15.3d", var1[i]);
    s21_sprintf(sc, "%15.3d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+14.4d", var1[i]);
    s21_sprintf(sc, "%-+14.4d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+13d", var1[i]);
    s21_sprintf(sc, "%-+13d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-11.7d", var1[i]);
    s21_sprintf(sc, "%-11.7d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- 13.4d", var1[i]);
    s21_sprintf(sc, "%- 13.4d", var1[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+13d", var1[i]);
    s21_sprintf(sc, "%+13d", var1[i]);
    ck_assert_str_eq(or, sc);
    ck_assert_int_eq(s21_sprintf(sc, "%d", var1[i]), sprintf(orig, "%d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-d", var1[i]), sprintf(orig, "%-d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%10d", var1[i]), sprintf(orig, "%10d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+d", var1[i]), sprintf(orig, "%-+d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- d", var1[i]), sprintf(orig, "%- d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+d", var1[i]), sprintf(orig, "%+d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%15.3d", var1[i]), sprintf(orig, "%15.3d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+14.4d", var1[i]), sprintf(orig, "%-+14.4d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+13d", var1[i]), sprintf(orig, "%-+13d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-11.7d", var1[i]), sprintf(orig, "%-11.7d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- 13.4d", var1[i]), sprintf(orig, "%- 13.4d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+13.4d", var1[i]), sprintf(orig, "%+13.4d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+13d", var1[i]), sprintf(orig, "%+13d", var1[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+d", var1[i]), sprintf(orig, "%+d", var1[i]));
  }
  for (s21_size_t i = 0; i < 3; i++) {
    sprintf(or, "%ld", var2[i]);
    s21_sprintf(sc, "%ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-ld", var2[i]);
    s21_sprintf(sc, "%-ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%10ld", var2[i]);
    s21_sprintf(sc, "%10ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+ld", var2[i]);
    s21_sprintf(sc, "%-+ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- ld", var2[i]);
    s21_sprintf(sc, "%- ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+ld", var2[i]);
    s21_sprintf(sc, "%+ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%15.3ld", var2[i]);
    s21_sprintf(sc, "%15.3ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+14.4ld", var2[i]);
    s21_sprintf(sc, "%-+14.4ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+13ld", var2[i]);
    s21_sprintf(sc, "%-+13ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-11.7ld", var2[i]);
    s21_sprintf(sc, "%-11.7ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- 13.4ld", var2[i]);
    s21_sprintf(sc, "%- 13.4ld", var2[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+13ld", var2[i]);
    s21_sprintf(sc, "%+13ld", var2[i]);
    ck_assert_str_eq(or, sc);
    ck_assert_int_eq(s21_sprintf(sc, "%ld", var2[i]), sprintf(orig, "%ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-ld", var2[i]), sprintf(orig, "%-ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%10ld", var2[i]), sprintf(orig, "%10ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+ld", var2[i]), sprintf(orig, "%-+ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- ld", var2[i]), sprintf(orig, "%- ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+ld", var2[i]), sprintf(orig, "%+ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%15.3ld", var2[i]), sprintf(orig, "%15.3ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+14.4ld", var2[i]), sprintf(orig, "%-+14.4ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+13ld", var2[i]), sprintf(orig, "%-+13ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-11.7ld", var2[i]), sprintf(orig, "%-11.7ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- 13.4ld", var2[i]), sprintf(orig, "%- 13.4ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+13ld", var2[i]), sprintf(orig, "%+13ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+11.7ld", var2[i]), sprintf(orig, "%+11.7ld", var2[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+ld", var2[i]), sprintf(orig, "%+ld", var2[i]));
  }
  for (s21_size_t i = 0; i < 3; i++) {
    sprintf(or, "%hd", var3[i]);
    s21_sprintf(sc, "%hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-hd", var3[i]);
    s21_sprintf(sc, "%-hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%10hd", var3[i]);
    s21_sprintf(sc, "%10hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+hd", var3[i]);
    s21_sprintf(sc, "%-+hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- hd", var3[i]);
    s21_sprintf(sc, "%- hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+hd", var3[i]);
    s21_sprintf(sc, "%+hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%15.3hd", var3[i]);
    s21_sprintf(sc, "%15.3hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+14.4hd", var3[i]);
    s21_sprintf(sc, "%-+14.4hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+13hd", var3[i]);
    s21_sprintf(sc, "%-+13hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-11.7hd", var3[i]);
    s21_sprintf(sc, "%-11.7hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- 13.4hd", var3[i]);
    s21_sprintf(sc, "%- 13.4hd", var3[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+13hd", var3[i]);
    s21_sprintf(sc, "%+13hd", var3[i]);
    ck_assert_str_eq(or, sc);
    ck_assert_int_eq(s21_sprintf(sc, "%hd", var3[i]), sprintf(orig, "%hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-hd", var3[i]), sprintf(orig, "%-hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%10hd", var3[i]), sprintf(orig, "%10hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+hd", var3[i]), sprintf(orig, "%-+hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- hd", var3[i]), sprintf(orig, "%- hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+hd", var3[i]), sprintf(orig, "%+hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%15.3hd", var3[i]), sprintf(orig, "%15.3hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+14.4hd", var3[i]), sprintf(orig, "%-+14.4hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+13hd", var3[i]), sprintf(orig, "%-+13hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-11.7hd", var3[i]), sprintf(orig, "%-11.7hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- 13.4hd", var3[i]), sprintf(orig, "%- 13.4hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+13hd", var3[i]), sprintf(orig, "%+13hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+11.7hd", var3[i]), sprintf(orig, "%+11.7hd", var3[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+hd", var3[i]), sprintf(orig, "%+hd", var3[i]));
  }

  int wall[10] = {2383, 0x4517, 0x5A3};
  for (size_t i = 0; i < 3; i++) {
    sprintf(or, "%i", wall[i]);
    s21_sprintf(sc, "%i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-i", wall[i]);
    s21_sprintf(sc, "%-i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%10i", wall[i]);
    s21_sprintf(sc, "%10i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+i", wall[i]);
    s21_sprintf(sc, "%-+i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- i", wall[i]);
    s21_sprintf(sc, "%- i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+i", wall[i]);
    s21_sprintf(sc, "%+i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%15.3i", wall[i]);
    s21_sprintf(sc, "%15.3i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+14.4i", wall[i]);
    s21_sprintf(sc, "%-+14.4i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-+13i", wall[i]);
    s21_sprintf(sc, "%-+13i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-11.7i", wall[i]);
    s21_sprintf(sc, "%-11.7i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%- 13.4i", wall[i]);
    s21_sprintf(sc, "%- 13.4i", wall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%+13i", wall[i]);
    s21_sprintf(sc, "%+13i", wall[i]);
    ck_assert_str_eq(or, sc);
    ck_assert_int_eq(s21_sprintf(sc, "%i", wall[i]), sprintf(orig, "%i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-i", wall[i]), sprintf(orig, "%-i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%10i", wall[i]), sprintf(orig, "%10i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+i", wall[i]), sprintf(orig, "%-+i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- i", wall[i]), sprintf(orig, "%- i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+i", wall[i]), sprintf(orig, "%+i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%15.3i", wall[i]), sprintf(orig, "%15.3i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+14.4i", wall[i]), sprintf(orig, "%-+14.4i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-+13i", wall[i]), sprintf(orig, "%-+13i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-11.7i", wall[i]), sprintf(orig, "%-11.7i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%- 13.4i", wall[i]), sprintf(orig, "%- 13.4i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+13i", wall[i]), sprintf(orig, "%+13i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+11.7i", wall[i]), sprintf(orig, "%+11.7i", wall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%+i", wall[i]), sprintf(orig, "%+i", wall[i]));
  }


  char fl[1000] = {};

  float mall[15] = {0, 0.1, -0.1, -12341234.12341234,
                    12341234.12341234, 456, -234, 1.09876543, -2345.2754607};

  for (size_t i = 0; i < 9; i++) {
    sprintf(or, "%f", mall[i]);
    s21_sprintf(fl, "%f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-f", mall[i]);
    s21_sprintf(fl, "%-f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%10f", mall[i]);
    s21_sprintf(fl, "%10f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-+f", mall[i]);
    s21_sprintf(fl, "%-+f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%- f", mall[i]);
    s21_sprintf(fl, "%- f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%+f", mall[i]);
    s21_sprintf(fl, "%+f", mall[i]);
    sprintf(or, "%15.3f", mall[i]);
    s21_sprintf(fl, "%15.3f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-+14.4f", mall[i]);
    s21_sprintf(fl, "%-+14.4f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-+13f", mall[i]);
    s21_sprintf(fl, "%-+13f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-11.7f", mall[i]);
    s21_sprintf(fl, "%-11.7f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%- 13.4f", mall[i]);
    s21_sprintf(fl, "%- 13.4f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%+13f", mall[i]);
    s21_sprintf(fl, "%+13f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%+11.7f", mall[i]);
    s21_sprintf(fl, "%+11.7f", mall[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%+f", mall[i]);
    s21_sprintf(fl, "%+f", mall[i]);
    ck_assert_str_eq(or, fl);
  }

  char *lall[20] = {"some", "BODY", "oNce", "TOlD123"};
  for (size_t i = 0; i < 3; i++) {
    sprintf(or, "%s", lall[i]);
    s21_sprintf(sc, "%s", lall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-s", lall[i]);
    s21_sprintf(sc, "%-s", lall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%10s", lall[i]);
    s21_sprintf(sc, "%10s", lall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%15.3s", lall[i]);
    s21_sprintf(sc, "%15.3s", lall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-11.7s", lall[i]);
    s21_sprintf(sc, "%-11.7s", lall[i]);
    ck_assert_str_eq(or, sc);
    sprintf(or, "%-15s", lall[i]);
    s21_sprintf(sc, "%-15s", lall[i]);
    ck_assert_str_eq(or, sc);
    ck_assert_int_eq(s21_sprintf(sc, "%s", lall[i]), sprintf(orig, "%s", lall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-s", lall[i]), sprintf(orig, "%-s", lall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%10s", lall[i]), sprintf(orig, "%10s", lall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%15.3s", lall[i]), sprintf(orig, "%15.3s", lall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-11.7s", lall[i]), sprintf(orig, "%-11.7s", lall[i]));
    ck_assert_int_eq(s21_sprintf(sc, "%-15s", lall[i]), sprintf(orig, "%-15s", lall[i]));

    sprintf(or, "%-+14.4hd %10ld %- d", var3[i], var2[i], var1[i]);
    s21_sprintf(fl, "%-+14.4hd %10ld %- d", var3[i], var2[i], var1[i]);
    ck_assert_str_eq(or, fl);
    sprintf(or, "%-+14.4f %11.7s %- 13.4i", mall[i], lall[i], wall[i]);
    s21_sprintf(fl, "%-+14.4f %11.7s %- 13.4i", mall[i], lall[i], wall[i]);
    ck_assert_str_eq(or, fl);
  }

  sprintf(or, "%ls", L"hello");
  s21_sprintf(fl, "%ls", L"hello");
  ck_assert_str_eq(or, fl);
  sprintf(or, "%19.9ls", L"WORld");
  s21_sprintf(fl, "%19.9ls", L"WORld");
  ck_assert_str_eq(or, fl);
  sprintf(or, "%-19.9ls", L"WORld");
  s21_sprintf(fl, "%-19.9ls", L"WORld");
  ck_assert_str_eq(or, fl);

  sprintf(or, "%u %lu %hu", UINT_MAX, ULONG_MAX, USHRT_MAX);
    s21_sprintf(fl, "%u %lu %hu", UINT_MAX, ULONG_MAX, USHRT_MAX);
    ck_assert_str_eq(or, fl);

  sprintf(or, "%%");
  s21_sprintf(fl, "%%");
  ck_assert_str_eq(or, fl);
  sprintf(or, "\\");
  s21_sprintf(fl, "\\");
  ck_assert_str_eq(or, fl);
  sprintf(or, "%%");
  s21_sprintf(fl, "%%");
  ck_assert_str_eq(or, fl);
  sprintf(or, " ");
  s21_sprintf(fl, " ");
  ck_assert_str_eq(or, fl);
  sprintf(or, "Helwo!69)");
  s21_sprintf(fl, "Helwo!69)");
  ck_assert_str_eq(or, fl);
}

END_TEST



START_TEST(s21_sprintf_test_d) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  int r1 = sprintf(
          str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
          335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  int r2 = s21_sprintf(
          str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
          335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  long l = 2353423523424;
  int r1 =
          sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                  34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  int r2 =
          s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                      34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
          str1,
          "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%+10.f%*.*f",
          2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
          3456789123.43245, 2, 12345.6788, 1, 34.4325432, 4325678.43242,
          34567.2345432, 10, 2, 34567.43244);
  int r2 = s21_sprintf(
          str2,
          "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%+10.f%*.*f",
          2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
          3456789123.43245, 2, 12345.6788, 1, 34.4325432, 4325678.43242,
          34567.2345432, 10, 2, 34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST


START_TEST(s21_sprintf_test_u) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
          sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                  4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5,
                  2345u, 20, 2432u, l, h);
  int r2 = s21_sprintf(
          str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
          34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
          h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char str1[1000];
  char str2[1000];
  wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
  int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                   "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                   "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  int r2 =
          s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                      "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                      "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST


START_TEST(s21_sprintf_test_percent) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf1) {
    char c[255] = {}, d[255] = {}, x1 = 't';
    wchar_t wch1 = 'W', wch2 = 'C';
    int n = 2100, n1 = 0, n2 = -21;
    short sh = 123, sh1 = -123;
    float f = 21.21, f1 = -21.21;
    long int lg = 12345678912345, lg1 = -12345678912345;
//    s21_sprintf(c, "%% %p", &n);
//    sprintf(d, "%% %p", &n);
//    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg,
                lg1, lg1);
    sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
            lg1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n,
                212121, 2121, n2, n, 21, 55, -55);
    sprintf(d, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
            2121, n2, n, 21, 55, -55);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
    sprintf(d, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
    ck_assert_str_eq(c, d);
    s21_sprintf(
            c, "[%.*d] [%3.10d] [%.d] [%-+.5d] [%-+10.5d] [%.10d] [%.10d] [%2.2d] [%.d] [% d] [%.0d]", 10,
            n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
    sprintf(d, "[%.*d] [%3.10d] [%.d] [%-+.5d] [%-+10.5d] [%.10d] [%.10d] [%2.2d] [%.d] [% d] [%.0d]",
            10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX,
                SHRT_MIN, USHRT_MAX, LONG_MAX, LONG_MIN);
    sprintf(d, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
            USHRT_MAX, LONG_MAX, LONG_MIN);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%c %10c %-10c %5lc %-5lc", '!', 'a', 'b', wch1, wch2);
    sprintf(d, "%c %10c %-10c %5lc %-5lc", '!', 'a', 'b', wch1, wch2);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello",
                "hello", "hello", "hello", "hello", "hello");
    sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
            "hello", "hello", "hello", "hello");
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello",
                L"hello", L"hello", L"hello", L"hello", L"hello", L"hello");
    sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
            L"hello", L"hello", L"hello", L"hello", L"hello");
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%u %lu", UINT_MAX, ULONG_MAX);
    sprintf(d, "%u %lu", UINT_MAX, ULONG_MAX);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "hello %n", &n);
    sprintf(d, "hello %n", &n1);
    ck_assert_msg(c, d, "error");
//    s21_sprintf(c, "[%-10o] [%lo] [%lo] [%o] [%o] [%o] [%10o] [%#10o] [%0#10o]", 21, lg, lg1, n,
//                0, n2, 0, 21, 42);
//    sprintf(d, "[%-10o] [%lo] [%lo] [%o] [%o] [%o] [%10o] [%#10o] [%0#10o]", 21, lg, lg1, n, 0,
//            n2, 0, 21, 42);
//    ck_assert_str_eq(c, d);
//    s21_sprintf(c, "[%#o] [%#o] [%#10o] [%0#10o] [%.10o] [%.0o] [%#5.10o]", n, n2, 0, 0, n, 0,
//                123);
//    sprintf(d, "[%#o] [%#o] [%#10o] [%0#10o] [%.10o] [%.0o] [%#5.10o]", n, n2, 0, 0, n, 0,
//            123);
//    ck_assert_str_eq(c, d);
//    s21_sprintf(c, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21,
//                n, 0, 123);
//    sprintf(d, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n, 0,
//            123);
//    ck_assert_str_eq(c, d);
//    s21_sprintf(c, "[%#x] [%#x] [%#5x] [%#2x] [%-#5x] [%0#7x] [%0#10x] [%-10.5x] [%lx] [%lx]",
//                n, n2, 21, 0, 42, 21, 0, -65, lg, lg1);
//    sprintf(d, "[%#x] [%#x] [%#5x] [%#2x] [%-#5x] [%0#7x] [%0#10x] [%-10.5x] [%lx] [%lx]", n,
//            n2, 21, 0, 42, 21, 0, -65, lg, lg1);
//    ck_assert_str_eq(c, d);
//    s21_sprintf(c, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
//    sprintf(d, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
//    ck_assert_str_eq(c, d);
//    s21_sprintf(c, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
//                4221, n1);
//    sprintf(d, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
//            4221, n1);
//    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
                21.21, -21.21, 42.42, -42.42, f, f1);
    sprintf(d, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
            21.21, -21.21, 42.42, -42.42, f, f1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "[% 10f] [% 10f] [%f] [%.0f] [%.0f] [%#.0f] [%.0f] [%f] [%010f]", f, f1, 21.,
                21.21, 0.0, 21.21, 21., 0.0, 21.21);
    sprintf(d, "[% 10f] [% 10f] [%f] [%.0f] [%.0f] [%#.0f] [%.0f] [%f] [%010f]", f, f1, 21.,
            21.21, 0.0, 21.21, 21., 0.0, 21.21);
    ck_assert_str_eq(c, d);
//    ck_assert_int_eq(
//            s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1,
//                        21., 21.21, 0.0, 21.21, 21., 0.0, 21.21),
//            sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
//                    21.21, 0.0, 21.21, 21., 0.0, 21.21));
//    ck_assert_int_eq(
//            s21_sprintf(c,
//                        "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
//                        n, n2, 21, 0, 42, 21, 0, -65, lg, lg1),
//            sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
//                    n, n2, 21, 0, 42, 21, 0, -65, lg, lg1));
}
END_TEST

START_TEST(s21_sprintf_test_dd) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    int r1 = sprintf(
            str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
            335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    int r2 = s21_sprintf(
            str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
            335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_ii) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    long l = 2353423523424;
    int r1 =
            sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                    34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    int r2 =
            s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                        34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_cc) {
    char str1[1000];
    char str2[1000];
    wchar_t c1 = 'T', c2 = 'Z';
    int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e',
                 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a',
                     'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_uu) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 115;
    unsigned long l = 123325242342l;
    int r1 =
            sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                    4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5,
                    2345u, 20, 2432u, l, h);
    int r2 = s21_sprintf(
            str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
            34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
            h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_ss) {
    char str1[1000];
    char str2[1000];
    wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
    int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                 "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                 "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    int r2 =
            s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                        "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                        "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percenttt) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *Suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *tcase_test = tcase_create("test");

  tcase_add_test(tcase_test, memchr_test);
  tcase_add_test(tcase_test, memcmp_test);
  tcase_add_test(tcase_test, memcpy_test);
  tcase_add_test(tcase_test, memmove_test);
  tcase_add_test(tcase_test, memset_test);
  tcase_add_test(tcase_test, strlen_test);
  tcase_add_test(tcase_test, strcmp_test);
  tcase_add_test(tcase_test, strncmp_test);
  tcase_add_test(tcase_test, strcpy_test);
  tcase_add_test(tcase_test, strncpy_test);
  tcase_add_test(tcase_test, strcat_test);
  tcase_add_test(tcase_test, strncat_test);
  tcase_add_test(tcase_test, strchr_test);
  tcase_add_test(tcase_test, strrchr_test);
  tcase_add_test(tcase_test, strpbrk_test);
  tcase_add_test(tcase_test, strerror_test);
  tcase_add_test(tcase_test, strtok_test);
  tcase_add_test(tcase_test, strspn_test);
  tcase_add_test(tcase_test, strcspn_test);
  tcase_add_test(tcase_test, strstr_test);
  tcase_add_test(tcase_test, tolower_test);
  tcase_add_test(tcase_test, toupper_test);
  tcase_add_test(tcase_test, trim_test);
  tcase_add_test(tcase_test, insert_test);

  tcase_add_test(tcase_test, s21_sprintf_test);
  tcase_add_test(tcase_test, s21_sprintf_test_d);
  tcase_add_test(tcase_test, s21_sprintf_test_i);
  tcase_add_test(tcase_test, s21_sprintf_test_f);
  tcase_add_test(tcase_test, s21_sprintf_test_u);
  tcase_add_test(tcase_test, s21_sprintf_test_s);
  tcase_add_test(tcase_test, s21_sprintf_test_percent);

  tcase_add_test(tcase_test, s21_sprintf_test_dd);
  tcase_add_test(tcase_test, s21_sprintf_test_ii);
  tcase_add_test(tcase_test, s21_sprintf_test_cc);
  tcase_add_test(tcase_test, s21_sprintf_test_uu);
  tcase_add_test(tcase_test, s21_sprintf_test_ss);
  tcase_add_test(tcase_test, s21_sprintf_test_percenttt);
  tcase_add_test(tcase_test, test_s21_sprintf1);
  suite_add_tcase(s21_string, tcase_test);

  return s21_string;
}

int main(void) {
  Suite *suite = Suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);

  return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
