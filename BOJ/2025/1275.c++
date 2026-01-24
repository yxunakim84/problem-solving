#include <stdio.h>

int N, Q;
long long arr[100005];
long long tree[400000];
int leafStart = 131072; // 2^17

void update(int idx, long long val) {
  int leafIdx = leafStart + idx - 1;
  tree[leafIdx] = val;
  int parentIdx = leafIdx;
  while(parentIdx > 1) {
    parentIdx /= 2;
    tree[parentIdx] = tree[parentIdx * 2] + tree[parentIdx * 2 + 1];
  }
}

long long get(int l, int r)  {
  if(l > r) {
    int temp = l;
    l = r;
    r = temp;
  }
  int leafLeft = leafStart + l - 1;
  int leafRight = leafStart + r - 1;
  long long ret = 0;
  while (leafLeft <= leafRight) {
    if(leafLeft % 2 == 1) ret += tree[leafLeft++];
    if(leafRight % 2 == 0) ret += tree[leafRight--];
    leafLeft /= 2;
    leafRight /= 2;
  }
  return ret;
 }

int main() {
  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
    tree[leafStart + i] = arr[i];
  }
  for(int i = leafStart - 1; i >= 1; i--) {
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }
  for(int i = 0; i < Q; i++) {
     int x, y, a, b; //x~y 합, a번째를 b로
     scanf("%d %d %d %d", &x, &y, &a, &b);
     printf("%lld\n", get(x, y));
     update(a, b);
  }

  return 0;

}
