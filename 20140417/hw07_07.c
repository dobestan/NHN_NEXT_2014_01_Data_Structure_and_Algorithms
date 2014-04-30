/**
 * @file hw07_07.c
 *
 * @brief Combinations
 *
 * @details
 * n 개의 문자로 구성된 문자열이 주어져 있을 때 길이가 1이상이고 n 보다 작거나 같은 모든 조합을 출력하는 함수를 만들어라.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_combination(char * list, int startId, int length, int * is_selected);

int main() {
  // char foo[] = "1";
  // char bar[] = "12";
  // char baz[] = "123";
  char quz[] = "1234";

  // print_combination(foo, 0, strlen(foo), NULL);
  // print_combination(bar, 0, strlen(bar), NULL);
  // print_combination(baz, 0, strlen(baz), NULL);
  print_combination(quz, 0, strlen(quz), NULL);
  return 0;
}

/**
 * @fn void print_combination(char * list, int startId, int length, int * is_selected)
 * @brief combinations implementation
 * @bug
 * - 메모리 동적할당 후에 free되지 않음
 * - 현재 print_combination 설계에서는 구현 불가
 *
 * ### 조금 더 나은 설계
 * - print_combination : C(n, r)
 * - print_all_combination : C(n, 0) + C(n, 1) + ... + C(n, r)\n\n
 * 이렇게 모듈화를 시켜서 진행하면 조금 더 예쁜 출력결과와 나은 결과를 얻을 수 있다.
 * 하지만 오늘은 시간이 없으므로 여기까지 진행하도록 한다.
 */
void print_combination(char * list, int startId, int length, int * is_selected) {
  /**
   * startId == 0인 경우, is_selected 배열을 동적할당한다.
   */
  if ( startId == 0 )
    is_selected = (int *) malloc (sizeof(int) * (length));

  /**
   * startId == length인 경우,\n
   * 이렇게 되면 모두 selected(1) or Not-selected(0)가 결정된 상태이다.\n
   * selected(1)인 경우에만 출력하라.
   */
  if ( startId == length ) {
    for ( int pos = 0 ; pos < length ; pos++ )
      if ( is_selected[pos] ) printf("%c", list[pos]);
    printf("\n");
  }

  else {
    is_selected[startId] = 1;
    print_combination(list, startId+1, length, is_selected);

    is_selected[startId] = 0;
    print_combination(list, startId+1, length, is_selected);
  }
}
