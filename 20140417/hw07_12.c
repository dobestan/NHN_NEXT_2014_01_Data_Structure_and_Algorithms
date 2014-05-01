/**
 * @file hw07_12.c
 * @brief Tower of Hanoi
 * @details
 * - Fundamentals Of Data Structures
 * - 1.3.2 Recursive Algorithm
 * - Exercises 11
 *
 * ### Write a recursive function that prints out the sequence of moves needed to accomplish this task.
 * ### IDEA
 * - 일단은 아이디어를 몇 개 적어보자.
 * - 우리가 흔히 알다시피 하노이 탑 문제는 재귀적으로 풀 수 있다.
 * - n개의 접시를 옮기는 방법은 (n-1)개의 접시를 옮기는 것을 2번 반복하면 된다.
 * - 즉, P(n) = 2*P(n-1) + 1
 */

#include <stdio.h>

void how_to_solve_hanoi(int disks, int src, int dest);

int main() {
  how_to_solve_hanoi(4, 0, 1);
  return 0;
}

void how_to_solve_hanoi(int disks, int src, int dest) {
  if ( disks == 1 ) printf("%d -> %d\n", src, dest);
  else {
    /**
     * - 일단은 우리가 접시를 놓을 곳은 크게 3부분이 있습니다.
     * - 0또는 1또는 2입니다. src / dest가 아닌 값을 구해봅시다.
     */
    int left;
    if ( src != 0 && dest != 0 ) left = 0;
    if ( src != 1 && dest != 1 ) left = 1;
    if ( src != 2 && dest != 2 ) left = 2;

    /**
     * - 알고리즘은 너무 쉬워서 간단하게 요약해서 설명한다.
     * - [ src, dest, left ] 라고 가정하자.
     * - n-1개를 src -> left로 옮긴다.
     * - 맨 밑에 큰 접시를 src -> dest로 옮긴다.
     * - n-1개를 left -> dest로 옮긴다.
     */
    how_to_solve_hanoi(disks-1, src, left);
    printf("%d -> %d\n", src, dest);
    how_to_solve_hanoi(disks-1, left, dest);
  }
}
