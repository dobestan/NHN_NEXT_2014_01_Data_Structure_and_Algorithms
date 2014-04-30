/**
 * @file hw07_03.c
 *
 * @brief Binary Search with Iteration
 *
 * ### 테스트 코드
 * 매우 간단한 예제라서 테스트 코드는 생략하였습니다.
 */

#include <stdio.h>

void printList(int list[], int size);
int binarySearch(int list[], int left, int right, int key);

int main() {
  int key; /// key는 찾고자 하는 값을 의미한다.
  int list[10] = {1, 3, 4, 5, 6, 7, 8, 9, 12, 20};
  int size = sizeof(list) / sizeof(int);
  int pos;

  printList(list, size);

  key = 3;
  if ( ( pos = binarySearch(list, 0, size-1, key) ) != -1 )
    printf("key is at %d.\n", pos);
  else
    printf("key %d not found\n", key);

  return 0;
}

void printList(int list[], int size) {
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
int binarySearch(int list[], int left, int right, int key) {
  /**
   * initial state
   *  - left = 0
   *  - right = n-1
   */

  while ( left <= right ) {
    int middle = ( left + right ) / 2;

    if ( key < list[middle] ) right = middle -1;
    else if ( key == list[middle] ) return middle;
    else left = middle + 1;
  }

  return -1;
}
