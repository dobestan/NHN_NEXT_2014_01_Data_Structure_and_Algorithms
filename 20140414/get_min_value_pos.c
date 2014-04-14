#include <stdio.h>

int get_min_value_pos(int *, int);
void get_min_value_pos_test(int *, int, int);
void get_min_value_pos_tests(void);

int main() {
  get_min_value_pos_tests();
  return 0;
}

int get_min_value_pos(int * list, int size) {
  int pos = 0;

  if ( list == NULL || size == 0 ) return -1;

  for ( int i = 1 ; i < 10 ; i++ ) {
    if ( list[pos] > list[i] ) pos = i;
  }

  return pos;
}

void get_min_value_pos_test(int * list, int size, int expected) {
  printf("%s\n", ( get_min_value_pos(list, size) == expected ) ? "success" : "failed" );
}

void get_min_value_pos_tests(void) {
  int foo[10] = {10, 3, 4, 1, 6, 9, 8, 2, 5, 7};
  get_min_value_pos_test(foo, sizeof(foo)/sizeof(int), 3);
}
