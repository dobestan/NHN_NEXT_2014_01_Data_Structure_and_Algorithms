/**
 * @file hw07_10.c
 * @brief Ascending Orders with Recursive
 * @details
 * - Fundamentals Of Data Structures
 * - 1.3.2 Recursive Algorithm
 * - Exercises 4
 *
 * ### Write a C program that prints out the integer values of x, y, z in ascending order.
 */

#include <stdio.h>

void print_list_ascending_order(int * list, int startId, int endId);
void print_list(int * list, int size);
int get_min_index(int * list, int startId, int endId);
void swap_int(int * foo, int * bar);

int main() {
  int foo[3] = {2, 1, 3};
  print_list_ascending_order(foo, 0, sizeof(foo)/sizeof(int));
  return 0;
}

/**
 * @fn void print_list_ascending_order(int * list, int startId, int endId)
 * @brief recursive implementation of sorting
 * @return void
 *
 * ###아이디어
 * - 만약에 정렬이 끝났으면 출력하라. ( startId+1 == endId )
 * - 만약에 정렬이 끝나지 않았으면 다음의 순서로 진행하라.
 * - 일단은 가장 작은 값(list[get_min_index(...)])과 현재 list[startId]을 교환한다.
 * - print_list_ascending_order(... startId+1 ...)를 다시 호출한다.
 */
void print_list_ascending_order(int * list, int startId, int endId) {
  if ( startId+1 == endId ) {
    print_list(list, endId);
  }

  else {
    swap_int(&list[startId], &list[get_min_index(list, startId, endId)]);
    print_list_ascending_order(list, startId+1, endId);
  }
}

void print_list(int * list, int size) {
  for ( int i = 0 ; i < size ; i++ ) printf("%2d ", list[i]);
  printf("\n");
}

int get_min_index(int * list, int startId, int endId) {
  int min_index = startId;
  for ( int i = startId ; i < endId ; i++ ) {
    if ( list[min_index] > list[i] ) min_index = i;
  }
  return min_index;
}

void swap_int(int * foo, int * bar) {
  int temp = *foo;
  *foo = *bar;
  *bar = temp;
}
