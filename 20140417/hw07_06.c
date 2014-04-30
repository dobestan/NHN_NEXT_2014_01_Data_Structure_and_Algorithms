/**
 * @file hw07_06.c
 *
 * @brief Permutations
 */

#include <stdio.h>
#include <string.h>

void swap_char( char * ch1, char * ch2 );
void print_permutation( char * list, int startId, int endId );

int main() {
  // char foo[] = "1";
  // char bar[] = "12";
  char baz[] = "123";
  // char qux[] = "1234";

  // print_permutation(foo, 0, strlen(foo)-1);
  // print_permutation(bar, 0, strlen(bar)-1);
  print_permutation(baz, 0, strlen(baz)-1);
  // print_permutation(qux, 0, strlen(qux)-1);

  return 0;
}

void swap_char( char * ch1, char * ch2 ) {
  char tmp;

  tmp = *ch1;
  *ch1 = *ch2;
  *ch2 = tmp;
}

/**
 * @fn void print_permutation( char * list, int startId, int endId )
 * @brief
 * @details
 */
void print_permutation( char * list, int startId, int endId ) {
  /**
   * 만약 startId와 endId만 같다면,\n
   * 지금 모든 element의 위치가 결정되었다.\n
   * 즉 출력하자.\n
   */
  if ( startId == endId ) {
    for ( int pos = 0 ; pos <= endId ; pos++ )
      printf("%c", list[pos]);
    printf("\n");
  }

  else {
    /**
     * 만약 startId와 endId가 같지 않다면,\n
     * 맨 앞자리( pos = startId )를 고정하고\n
     * 나머지를 가지고 다시 permutations을 수행\n\n
     * ### [a, b, c]인 경우
     * [a, b, c]\n
     * [b, a, c] -> 이 상태로 [a, c]를 다시 연산수행\n
     * [a, b, c]\n
     * [c, b, a] -> 이 상태로 [b, a]를 다시 연산수행\n
     * [a, b, c]\n
     */
    for ( int pos = startId ; pos <= endId ; pos++ ) {
      swap_char(&list[startId], &list[pos]);
      print_permutation(list, startId+1, endId);
      swap_char(&list[startId], &list[pos]);
    }
  }
}
