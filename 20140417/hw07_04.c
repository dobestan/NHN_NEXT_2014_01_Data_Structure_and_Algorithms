/**
 * @file hw07_04.c
 * @brief Binary Search with duplicated values
 */

#include <stdio.h>

void printList(int list[], int size);
int binary_search(int list[], int left, int right, int key);

int search_left_most(int * list, int left, int right, int key);
int search_right_most(int * list, int left, int right, int key);
int get_num_of_key(int * list, int left, int right, int key);

void integration_test(void);
void unit_test(int * list, int left, int right, int key);

void integration_test(void) {
  int foo[5] = {1, 1, 1, 1, 1};
  unit_test(foo, 0, sizeof(foo)/sizeof(foo[0])-1, 1);

  int bar[5] = {1, 2, 2, 2, 5};
  unit_test(bar, 0, sizeof(bar)/sizeof(bar[0])-1, 5);

  int baz[10] = {1, 2, 5, 6, 8, 8, 8, 8, 8, 8};
  unit_test(baz, 0, sizeof(baz)/sizeof(baz[0])-1, 8);
}

void unit_test(int * list, int left, int right, int key) {
  printList(list, right+1);
  printf("looking for ... [%d]\n", key);

  int pos;
  if ( ( pos = binary_search(list, 0, right+1, key) ) != -1 ) {
    printf("gotcha! key is at [%d].\n", pos);
    printf("Umm... the left most key is at [%d]\n", search_left_most(list, 0, right, key));
    printf("Umm... the right most key is at [%d]\n", search_right_most(list, 0, right, key));
    printf("So... the number of [%d] is [%d]\n", key, get_num_of_key(list, 0, right, key));
  }
  else
    printf("[%d]를 찾을 수 없습니다.\n", key);
}


int main() {
  integration_test();
}

void printList(int list[], int size) {
  for ( int i = 0 ; i < size ; i++ ) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

/**
 * @fn int binary_search(int list[], int left, int right, int key)
 * @brief binary search implementation
 * @details
 * @return
 * - key값이 존재하면 (int) position 리턴
 * - key값이 존재하지 않으면 -1 리턴
 */
int binary_search(int list[], int left, int right, int key) {
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

int search_left_most(int * list, int left, int right, int key) {
  int left_most_index = binary_search(list, left, right, key);
  if ( left_most_index == -1 ) return -1;

  while ( list[left_most_index - 1] == key && left_most_index != 0 ) {
    left_most_index--;
  }
  return left_most_index;
}

int search_right_most(int * list, int left, int right, int key) {
  int right_most_index = binary_search(list, left, right, key);
  if ( right_most_index == -1 ) return -1;

  while ( list[right_most_index + 1] == key ) {
    right_most_index++;
  }
  return right_most_index;
}


int get_num_of_key(int * list, int left, int right, int key) {
  int left_most_index = search_left_most(list, left, right, key);
  int right_most_index = search_right_most(list, left, right, key);
  if ( left_most_index == -1 || right_most_index == -1 ) return -1;
  return right_most_index - left_most_index + 1;
}
