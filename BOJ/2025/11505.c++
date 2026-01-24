#include <stdio.h>

int N, M, K;
//M; 변경이 일어나는 횟수
//K: 구간의 곱
long long arr[1000005];
long long tree[4000000];
int leafStartIdx = 1048576; 
long long mod = 1000000007;

// update()
void update(int idx, int val) {
  int leafIdx = leafStartIdx + idx - 1;
  tree[leafIdx] = val;
  while(leafIdx > 1) {
    leafIdx /= 2;
    tree[leafIdx] = (tree[leafIdx * 2]  * tree[leafIdx * 2 + 1]) % mod;
  }
}

// multiply()
long long multiply(int l, int r) {
  int leftLeafIdx = leafStartIdx + l - 1;
  int rightLeafIdx = leafStartIdx + r - 1;
  long long ret = 1;
  while(leftLeafIdx <= rightLeafIdx) {
    if(leftLeafIdx % 2 == 1) ret = (ret * tree[leftLeafIdx++]) % mod;
    if(rightLeafIdx % 2 == 0) ret = (ret * tree[rightLeafIdx--]) % mod;
    leftLeafIdx /= 2;
    rightLeafIdx /= 2;
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
    tree[leafStartIdx + i] = arr[i] % mod;
  }
  for(int i = leafStartIdx - 1; i >= 1; i--) {
    tree[i] = (tree[i*2] * tree[i*2+1]) % mod;
  }
  for(int i = 0; i < M + K; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 1) {
      // b를 c로 바꾸기
      update(b, c);
    }
    else if (a == 2) {
      // b~c의 곱
      printf("%lld\n", multiply(b, c));
    }
  }

  return 0;
}