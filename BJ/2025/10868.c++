#include <stdio.h>
#include <limits.h>

int N, M; // 총 N개, M개의 쌍
long long arr[100005];
long long tree[400000];
int leafStartIdx = 131072;
long long Min(long long a, long long b) {return a < b ? a : b;}

long long search(int l, int r) {
  int leftTreeIdx = leafStartIdx + l - 1;
  int rightTreeIdx = leafStartIdx + r - 1;
  long long minVal = LLONG_MAX;

  while(leftTreeIdx <= rightTreeIdx) {
    if(leftTreeIdx % 2 == 1) {
      if(minVal > tree[leftTreeIdx]) minVal = Min(minVal, tree[leftTreeIdx]);
      leftTreeIdx++;
    }
    if(rightTreeIdx % 2 == 0) {
      if(minVal > tree[rightTreeIdx]) minVal = Min(minVal, tree[rightTreeIdx]);
      rightTreeIdx--;
    }
    leftTreeIdx /= 2;
    rightTreeIdx /= 2;
  }
  
  return minVal;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
    tree[leafStartIdx + i] = arr[i];
  }

  for(int i = leafStartIdx - 1; i >= 1; i--) {
    tree[i] = Min(tree[i*2], tree[i*2+1]);
  }

  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", search(a, b));
  }
  return 0;
}