#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int map[1005][1005];
int dist[1005][1005] = {0}; // 누적 날짜
queue<pair<int, int>> q;

int M, N;

// int Min(int a, int b) {return a < b ? a : b;}

void bfs() {
  while(!q.empty()) {
    int currentY = q.front().first;
    int currentX = q.front().second;
    q.pop();
    
    int currentDist = dist[currentY][currentX];

    vector<pair<int, int>> pos = {{currentY, currentX+1}, {currentY+1, currentX}, {currentY, currentX-1}, {currentY-1, currentX}};

    for(int i = 0; i < 4; i++) {
      int nextY = pos[i].first;
      int nextX = pos[i].second;
      if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue; // 범위 벗어나면 pass

      if(map[nextY][nextX] == 0 && dist[nextY][nextX] == -1) { // 주변이 0인 곳만 탐색하면서 갱신 채움
        dist[nextY][nextX]  = currentDist + 1;
        q.push({nextY, nextX});
      }
    }
  }

}

int main() {
  scanf("%d %d", &M, &N); //M: 가로 N: 세로

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
      dist[i][j] = -1;
      if(map[i][j] == 1) {
        q.push({i, j}); // 익은 토마토는 탐색 가능하므로 큐에 넣어준다.
        dist[i][j] = 0;
      }
    }
  }

  bfs();

  int ret = 0;
  bool impossible = false;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(map[i][j] == 0 && dist[i][j] == -1) {
        impossible = true;
        break;
      }
      if(dist[i][j] > ret) ret = dist[i][j];
    }
    if(impossible) break;
  }

  if(impossible) ret = -1;
  printf("%d", ret);

  return 0;
}