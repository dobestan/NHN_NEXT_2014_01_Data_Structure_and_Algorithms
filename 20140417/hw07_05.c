/**
 * @file hw07_05.c
 *
 * @brief binary search with Recursion
 */

#include <stdio.h>

void print_list(int list[], int size);
int recursive_binary_search(int list[], int left, int right, int key);

int main() {
  int key; /// key는 찾고자 하는 값을 의미한다.
  int list[10] = {1, 3, 4, 5, 6, 7, 8, 9, 12, 20};
  int size = sizeof(list) / sizeof(int);
  int pos;

  print_list(list, size);

  key = 3;
  if ( ( pos = recursive_binary_search(list, 0, size-1, key) ) != -1 )
    printf("key is at %d.\n", pos);
  else
    printf("key %d not found\n", key);

  return 0;
}

void print_list(int list[], int size) {
  for ( int i = 0 ; i < size ; i++ ) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

/**
 * @fn int binarySearch(int list[], int left, int right, int key)
 * @brief binary search implementation
 * @details
 * @return
 * - key값이 존재하면 (int) position 리턴
 * - key값이 존재하지 않으면 -1 리턴
 */
int recursive_binary_search(int list[], int left, int right, int key) {
  /**
   * initial state
   *  - left = 0
   *  - right = n-1
   */

  if ( left > right ) return -1;

  int middle = ( left + right ) / 2;

  if ( list[middle] == key ) return middle;
  else if ( list[middle] > key ) return recursive_binary_search(list, left, middle-1, key);
  else return recursive_binary_search(list, middle+1, right, key);
}
