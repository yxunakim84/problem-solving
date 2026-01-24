#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
// vector<int> graph[105];
int map[105][105];
int dist[105][105]; // graph가 2차원 배열이므로 visit 표시하는 배열도 2차원으로 관리해야됨

void bfs() {
  queue<pair<int, int>> q;
  q.push({1, 1}); // startNode {y, x} 좌표 위치
  dist[1][1] = 1; // 방문 표시

  while(!q.empty()) {
    pair<int, int> currentNode = q.front();
    q.pop();
    int currentY = currentNode.first; //y
    int currentX = currentNode.second; //x
    // {currentY, currentX+1}, {currentY+1, currentX}, {currentY-1, currentX} 탐색 가능
    vector<pair<int, int>> arr = {{currentY, currentX+1}, {currentY+1, currentX}, {currentY-1, currentX}, {currentY, currentX-1}};
    
    for(int i = 0; i < 4; i++) {
      // 범위 넘어가는지 체크
      if(arr[i].first <= 0 || arr[i].first > N || arr[i].second <= 0 || arr[i].second > M) continue;
      if(dist[arr[i].first][arr[i].second] == 0 && map[arr[i].first][arr[i].second] == 1) {
        q.push({arr[i].first, arr[i].second});
        dist[arr[i].first][arr[i].second] = dist[currentY][currentX] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) scanf("%1d", &map[i][j]);
  }

  bfs();

  int ret = dist[N][M];
  printf("%d", ret);

  return 0;
}