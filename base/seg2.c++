#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>


int m, n, k;
long long arr[1000005];
/*트리 크기는 배열의 네 배로 하면 안전*/
long long tree[1000000 * 4];
/*4백만 배열에서 리프노드 찾기 2 ^ 20*/
int leafStart = 1048576;

void update(long long idx, long long val) {
  int leafIdx = leafStart + idx - 1;
  tree[leafIdx] = val;
  int idx = leafIdx;
  while (idx > 1) {
    idx = idx / 2;
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  }
}

long long get(long l, long r) {
  long long ret = 0;
  int leafLeftIdx = leafStart + l - 1;
  int leafRightIdx = leafStart + r - 1;

  while(l <= r) {
    if(leafLeftIdx % 2 == 1) ret += tree[leafLeftIdx++]; 
    if(leafRightIdx % 2 == 0) ret += tree[leafRightIdx--];
    l /= 2;
    r /= 2;
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
    // 리프노드에 입력값 저장
    tree[leafStart + i];
  }
  
  // 중간노드 채우기
  for(int i = leafStart - 1; i >= 1; i--) {
    tree[i] = tree[i*2] + tree[i*2+1];
  }
}