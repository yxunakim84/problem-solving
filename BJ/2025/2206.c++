#include <stdio.h>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int N, M;
int map[1005][1005];
int dist[1005][1005][2];

// 최소 거리니까 bfs
void bfs(int startY, int startX) {
  queue<tuple<int, int, int>> q;

  dist[startY][startX][0] = 1;
  q.push({startY, startX, 0});
  
  while(!q.empty()) {   
    int currentY, currentX, broken; 
    tie(currentY, currentX, broken) = q.front();
    q.pop();
    
    int currentDist = dist[currentY][currentX][broken];
    
    pair<int, int> arr[4] = {{currentY+1, currentX}, {currentY-1, currentX}, {currentY, currentX+1}, {currentY, currentX-1}};
    
    
    for(int i = 0; i < 4; i++) { // 여기 안에서는 opt 중복해서 사용 가능
      int nextY = arr[i].first;
      int nextX = arr[i].second;
      
      // 범위 벗어나는 경우 예외처리 (경계값은 항상 입력값 기준으로)
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;

      if(map[nextY][nextX] == 0 && dist[nextY][nextX][broken] == 0) { // 진입 가능
        dist[nextY][nextX][broken] = currentDist + 1;
        q.push({nextY, nextX, broken});
      } 
      else if(map[nextY][nextX] == 1 && broken == 0 && dist[nextY][nextX][1] == 0) { // 벽을 깰 수 있는 경우
        dist[nextY][nextX][1] = currentDist + 1;
        q.push({nextY, nextX, 1});
      }
    }
  }
}

int main() {

  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      scanf("%1d", &map[i][j]); // i가 y, j가 x
    }
  }
  
  // N, M이 1인 예외 케이스 처리
  if (N == 1 && M == 1) {
    printf("1");
    return 0;
  }

  bfs(1, 1);

  int res_not_broken = dist[N][M][0];
  int res_broken = dist[N][M][1];

  if(res_not_broken == 0 && res_broken == 0) {
    printf("-1");
  } else if(res_not_broken != 0 && res_broken != 0) {
    printf("%d", res_broken < res_not_broken ? res_broken : res_not_broken);
  } else if(res_not_broken != 0) {
    printf("%d", res_not_broken);
  } else {
    printf("%d", res_broken);
  }

  return 0;
}