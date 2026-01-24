#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int map[100][100];
int visited[100][100];
int result = 0;

void go(int y, int x) {
  visited[y][x] = 1;

  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
    if(visited[ny][nx] == 1) continue;
    if(map[ny][nx] == 0) continue;
    go(ny, nx);
  }
}


int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int val;
      cin >> val;
      map[i][j] = val; 
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(visited[i][j] == 1 || map[i][j] == 0) continue;
      else {
        go(i, j);
        result++;
      }
    }
  }

  cout << result << "\n";
  return 0;
}