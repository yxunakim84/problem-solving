#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, Q;
long long arr[100005];
long long tree[400000];
int leafStartNode = 131072;



long long get(int l, int r) {
  if(r > l) {
    int temp = l;
    l = r;
    r = temp;
  }
  int leftTreeNode = leafStartNode + l - 1;
  int rightTreeNode = leafStartNode + r - 1;
  long long sum = 0;

  while(leftTreeNode <= rightTreeNode) {

    if(leftTreeNode % 2 == 1) sum += tree[leftTreeNode++];
    if(rightTreeNode % 2 == 0) sum += tree[rightTreeNode--];

    leftTreeNode /= 2;
    rightTreeNode /= 2;

  }
  return sum;
}

void update(int idx, long long val) {
  int leafTargetNode = leafStartNode + idx - 1;
  tree[leafTargetNode] = val;
  int parentTargetNode = leafTargetNode / 2;
  
  while(parentTargetNode > 1) {
    tree[parentTargetNode] = tree[parentTargetNode * 2] + tree[parentTargetNode * 2 + 1];
    parentTargetNode /= 2;
  }

}

int main() {

  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
    // tree 만들기
    tree[leafStartNode + i] = arr[i];
  }

  // 중간 노드 채우기
  for(int i = leafStartNode - 1; i >= 1; i--) {
    tree[i] = tree[i*2] + tree[i*2+1];
  }

  for(int i = 0; i < Q; i++) {
    int x, y, a, b;
    // x~y합, a <-> b
    scanf("%d %d %d %d", &x, &y, &a, &b);
    // get
    printf("%lld\n", get(x, y));
    // update
    update(a, b);
  }


  return 0;
}