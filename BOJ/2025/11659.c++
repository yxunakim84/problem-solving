#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N, M;
int arr[100005];
int sum[100005];

int main() {
  scanf("%d %d", &N, &M);
  sum[0] = 0;
  for(int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    sum[i] = sum[i-1] + arr[i];
  }
  for(int i = 0; i < M; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%d\n", sum[end] - sum[start-1]);
  }

  return 0;
}