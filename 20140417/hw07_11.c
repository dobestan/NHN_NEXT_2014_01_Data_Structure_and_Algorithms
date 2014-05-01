/**
 * @file hw07_11.c
 * @brief Ackerman's function NOT_IMPLEMENTED
 * @details
 * - Fundamentals Of Data Structures
 * - 1.3.2 Recursive Algorithm
 * - Exercises 10
 *
 * ### Ackerman's function A(m,n)
 * A(m, n)
 * = n + 1 ( if, m = 0 )
 * = A(m-1, 1 ) ( if, n=0 )
 * = A(m-1, A(m, n-1)) ( otherwise )
 */

#include <stdio.h>

int get_ackerman_result( int m, int n );
int get_ackerman_result_iterative_method( int m, int n );

int main() {

  printf("%d", get_ackerman_result(1, 3));
  return 0;
}

int get_ackerman_result( int m, int n ) {
  /**
   * - 재귀적으로 짜는 방식은 굉장히 쉽다.
   * - 정의를 그대로 이용하면 된다.
   */

  if ( m == 0 ) return n + 1;
  else if ( n == 0 ) return get_ackerman_result( m-1, 1 );
  else return get_ackerman_result( m-1, get_ackerman_result( m, n-1 ) );
}

int get_ackerman_result_iterative_method( int m, int n ) {
  int result;
  while (1) {
    if ( m == 0 ) return n+1;
    else if ( n == 0 ) {
      m = m - 1;
      n = 1;
    }
    else {
      m = m-1;
      // n = get_ackerman_result(m, n-1);
    }
  }
}
