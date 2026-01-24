#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
int dist[100005];

void bfs(int startNode) {
  queue<int> q;
  q.push(startNode);
  dist[startNode] = 0;

  while(!q.empty()) {
    int currentNode = q.front();
    q.pop();

    int currentDist = dist[currentNode];

    // 3가지가 있음
    int nodes[3] = {currentNode - 1, currentNode + 1, currentNode * 2};
    for(int i = 0; i < 3; i++) {
      int nextNode = nodes[i];
      if(nextNode < 0 || nextNode > 100000) continue;
      if(dist[nextNode] == -1) {
        q.push(nextNode);
        dist[nextNode] = currentDist + 1;
      }
    }
  }
}


int main() {
  scanf("%d %d", &N, &K);

  // for (int i = 0; i < 100005; i++) {
  //   dist[i] = -1;
  // }
  memset(dist, -1, sizeof(dist));

  // 앞서 있는 경우도 고려했어야
  if(N >= K) {
    printf("%d", N-K);
  }
  else {
    bfs(N);
    printf("%d", dist[K]);
  }

  return 0;
}


// 배열 초기화 선언 시에 arr[5] = {-1} 처럼 하면 첫 번째 원소만 초기화 된다. 반복문으로 전체 초기화 진행해줘야됨. 기본 값이 0
