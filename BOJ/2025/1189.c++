#include <cstdio>
#include <iostream>

using namespace std;

int R, C, K;
char map[10][10];
char visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


int dfs(int startY, int startX) {
  // 기저사례
  if(startY == 0 && startX == R-1) {
    if(visited[startY][startX] == K) return 1;
    return 0;
  }
  
  int ret = 0;
  for(int i = 0; i < 4; i++) {
    int nextY = startY + dy[i];
    int nextX = startX + dx[i];
    if(nextY >= C || nextY < 0 || nextX >= R || nextX < 0) continue;
    if(map[nextY][nextX] == 'T') continue;
    if(visited[nextY][nextX]) continue;

    visited[nextY][nextX] = visited[startY][startX] + 1;
    ret += dfs(nextY, nextX);
    visited[nextY][nextX] = 0;
  }

  return ret;
}

int main() {
  cin >> R >> C >> K;
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < R; j++) {
      cin >> map[i][j];
    }
  }

  visited[C-1][0] = 1;
  cout << dfs(C-1, 0) << "\n";

  

  return 0;
}