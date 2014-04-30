/**
 * @file hw07_03.c
 *
 * @brief binary search
 *
 * @details
 * 실습 주제 7.3 (binary search) 코드 완료해서 제출\n
 *
 * ### 주의 사항
 * - Compile error 발생하면 0점 처리함
 * - File의 맨 앞에 주석(comment) 추가
 * - Indentation
 *
 * ### 입력
 * - 정수 배열, 배열 내에서 검색 범위, 찾고자 하는 key 값
 *
 * ### 출력
 * - Key 값이 배열에 있으면 key가 있는 위치를 return
 * - Key 값이 배열에 없으면 -1을 return
 *
 * ### 구현할 함수 API :
 * - int binarySearch (int list[], int left, int right, int key); 
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

  key = 0;
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

  if ( left > right ) return -1;

  int middle = ( left + right ) / 2;

  if ( list[middle] == key ) return middle;
  else if ( list[middle] > key ) return binarySearch(list, left, middle-1, key);
  else return binarySearch(list, middle+1, right, key);
}
