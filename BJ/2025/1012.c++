#include <stdio.h>
#include <vector>
#include <string.h>


using namespace std;

int T, N, M;
int map[55][55] = { 0 };
bool visited[55][55] = { false };
int cnt = 0;
// 한 그룹당 한 마리 필요
void dfs(int i, int j) {
  visited[i][j] = true;
  
  vector<pair<int, int>> arr = {{i-1, j}, {i+1, j}, {i, j+1}, {i, j-1}};
  
  for(int i = 0; i < 4; i++) {
    int nextX = arr[i].first;
    int nextY = arr[i].second;
    
    if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
    
    if(!visited[nextX][nextY] && map[nextX][nextY] == 1) {
      dfs(nextX, nextY);
    }
  }
}

int main() {
  scanf("%d", &T);

  for(int i = 0; i < T; i++) {
    int K; // 가로 세로 배추 개수
    scanf("%d %d %d", &M, &N, &K);
    int cnt = 0;
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));

    for(int j = 0; j < K; j++) {
      int x, y;
      scanf("%d %d", &x, &y);
      map[y][x] = 1;
    }

    // k번만큼 dfs 반복? 끊어진 부분은 탐색 불가능하므로..
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(map[i][j] == 1 && visited[i][j] == false) {
          cnt++;
          dfs(i, j);
        }
      }
   }

   printf("%d\n", cnt);
  }


}