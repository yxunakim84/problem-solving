#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int N;
int queue[10005];
// 실제로 배열의 값을 빼고 옮기는 것이 아니라 투포인터로 유효한 값 범위를 가리킨다.
int startIdx = 0; // 값이 시작하는 부분
int endIdx = 0;

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    char command[10];
    scanf("%s", command);

    if(strcmp(command, "push") == 0) { //endIdx에 넣어주기
      int val;
      scanf("%d", &val);
      queue[endIdx++] = val;
    }
    else if(strcmp(command, "pop") == 0) { //startIdx를 옮겨주기
      if(startIdx == endIdx) {
        printf("-1\n");
      } else {
        printf("%d\n", queue[startIdx++]);
      }
    }
    else if(strcmp(command, "size") == 0) {
      printf("%d\n", endIdx - startIdx);
    }
    else if(strcmp(command, "empty") == 0) {
      printf("%d\n", startIdx == endIdx ? 1 : 0);
    }
    else if(strcmp(command, "front") == 0) {
      if(startIdx == endIdx) {
        printf("-1\n");
      } else {
        printf("%d\n", queue[startIdx]);
      }
    }
    else if(strcmp(command, "back") == 0) {
      if(startIdx == endIdx) {
        printf("-1\n");
      } else {
        printf("%d\n", queue[endIdx-1]);
      }
    }
   
  }
  return 0;
}