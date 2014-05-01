/**
 * @file hw07_09.c
 * @brief print boolean pairs
 * @details
 * - Fundamentals Of Data Structures
 * - 1.3.2 Recursive Algorithm
 * - Exercises 3
 *
 * ### n = 2 -> <true, true>, <true, false>, <false, true>, <false, false>
 */

#include <stdio.h>
#include <stdlib.h>

void print_boolean_pairs(int num);
void print_boolean_paris_implementation(int * is_true, int startId, int endId);
void print_list(int * list, int size);

int main() {
  print_boolean_pairs(3);
  return 0;
}

void print_boolean_pairs(int num) {
  int * is_true = ( int * ) malloc (sizeof(int) * num);
  print_boolean_paris_implementation(is_true, 0, num);
  free(is_true);
}

void print_boolean_paris_implementation(int * is_true, int startId, int endId) {
  if ( startId == endId ) print_list(is_true, endId);
  else {
    is_true[startId] = 1;
    print_boolean_paris_implementation(is_true, startId+1, endId);

    is_true[startId] = 0;
    print_boolean_paris_implementation(is_true, startId+1, endId);
  }
}

void print_list(int * list, int size) {
  for ( int i = 0 ; i < size ; i++ ) {
    printf("%s ", (list[i]) ? "true" : "false");
  }
  printf("\n");
}
