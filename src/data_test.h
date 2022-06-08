#ifndef SRC_DATA_TEST_H_
#define SRC_DATA_TEST_H_

char test1[50] = "Hello world\0";
char test2[50] = "Hello world\n\0";
char test3[50] = "a\n\0";
char test4[50] = " \n\0";
char test5[50] = " \0";
char test6[50] = "\n\0";
char test7[50] = "\0";
char test8[200] = "()_+\b \r\nABC\fabc\t123\vsome\?\n tob\" also \' and \\ \n\0";
char test9[200] = "()_+ABC\fabc\t123\vsome\? tob\" also \'and\\\0";
char test10[200] = "This is-example of work string tok";

#endif  //  SRC_DATA_TEST_H_
