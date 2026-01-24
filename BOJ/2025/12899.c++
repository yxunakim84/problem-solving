#include <stdio.h>

// 자연수를 저장하는 데이터베이스 S에 대해 다음의 쿼리를 처리합시다.
// 유형 1 : S에 자연수 X를 추가한다.
// 유형 2 : S에 포함된 숫자 중 X번째로 작은 수를 응답하고 그 수를 삭제한다.

int N;
int tree[4 * 2000000];
int leafStart = 2097152;

// 값 X를 트리 노드의 인덱스로 취급하고 그 개수를 관리.
void update(int idx, int val) {
  int treeIdx = leafStart + idx;
  tree[treeIdx] +=  val;
  while(treeIdx > 1) {
    treeIdx /= 2;
    tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
  }
}

int query(int k) {
  int startTreeIdx = 1;
  
  while(startTreeIdx < leafStart) {
    int left_count = tree[startTreeIdx * 2];
    if(k <= left_count) {
      startTreeIdx *= 2;
    }
    else {
      k = k - left_count;
      startTreeIdx = startTreeIdx * 2 + 1;
    }
  }
  return startTreeIdx - leafStart;
 }

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int T, X;
    scanf("%d %d", &T, &X);

    if(T == 1) {
      update(X, 1);
      // X를 +1개 추가
    }
    else {
      // X번째 작은 수 찾기
      int res = query(X);
      printf("%d\n", res);
      update(res, -1);
    }
  }

}