#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int n; //최대 10? 2^4
int arr[100];
long long tree[10 * 4];

long long init(int node, int start, int end) {
  if(start == end) {
    // leaf 노드라는 뜻
    return tree[node] = arr[start];
  }
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid+1, end);
}

long long get(int node, int start, int end, int left, int right) {
  if(left > end || right < start) {
    return 0;
  }


}
int main() {
  //1. 트리 생성 init
  // init(int node, int start, int end) { }
  init(1, 0, n-1);
  int leafStart = pow(2, 20);

  for(int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
    tree[leafStart + i] = arr[i];
  }

  for(int i = leafStart-1; i > 0; i--) {
    tree[i] = tree[i*2] + tree[i*2 + 1];
  }

}