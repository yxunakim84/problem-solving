#define _NO_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N;
int arr[95];

int main() {
  scanf("%d", &N);
  arr[0] = 0;
  arr[1] = 1;
  for(int i = 2; i <=N; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  printf("%d", arr[N]);
  
  return 0;
}