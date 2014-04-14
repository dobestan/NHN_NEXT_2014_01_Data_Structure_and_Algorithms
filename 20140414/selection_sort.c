// NHN NEXT - Data Structure and Algorithms
// @dobestan (Suchan An) / dobestan@gmail.com
//
// 20140414 : Selection Sort

#include <stdio.h>

void print_list(int *, const int);
void swap(int *, int *);

void selection_sort(int *, const int);
void selection_sort_test(int *, const int, int *);
void selection_sort_tests(void);

int main() {
  selection_sort_tests();

  return 0;
}

void print_list(int * list, const int size) {
  for ( int i = 0 ; i < size ; i++ ) printf("%2d ", list[i]);
  printf("\n");
}

void swap(int * foo, int * bar) {
  int baz = *foo;
  *foo = *bar;
  *bar = baz;
}

void selection_sort(int * list, const int size) {
  int min_value_index = 0;
  for ( int i = 0 ; i < size-1 ; i++ ) {
    min_value_index = i;
    for ( int j = i + 1 ; j < size ; j++ )
      if ( list[min_value_index] > list[j] ) min_value_index = j;
    swap( &list[i], &list[min_value_index] );
  }
}

void selection_sort_test(int * list, const int size, int * expected) {
  print_list(list, size);
  selection_sort(list, size);
  print_list(list, size);

  int is_success = 1; // default true
  for ( int i = 0 ; i < size ; i++ )
    if ( list[i] != expected[i] ) is_success = 0;
  printf("%s\n", (is_success) ? "success" : "failed" );
}

void selection_sort_tests(void) {
  int test1[] = {10};
  int test2[] = {10, 3};
  int test3[] = {20, 3, 1};
  int test4[] = {3, 10};
  int test5[] = {3, 10, 20};

  int test1_expected[] = {10};
  int test2_expected[] = {3, 10};
  int test3_expected[] = {1, 3, 20};
  int test4_expected[] = {3, 10};
  int test5_expected[] = {3, 10, 20};

  selection_sort_test(test1, sizeof(test1)/sizeof(int), test1_expected);
  selection_sort_test(test2, sizeof(test2)/sizeof(int), test2_expected);
  selection_sort_test(test3, sizeof(test3)/sizeof(int), test3_expected);
  selection_sort_test(test4, sizeof(test4)/sizeof(int), test4_expected);
  selection_sort_test(test5, sizeof(test5)/sizeof(int), test5_expected);
}
