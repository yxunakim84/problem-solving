#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int map[105][105];
int visited[105][105];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int N;

void dfs(pair<int, int> start) {
  int curr_y = start.first;
  int curr_x = start.second;

  visited[curr_y][curr_x] = 1;

  for(int i = 0; i < 4; i++) {
    int next_y = curr_y + dy[i];
    int next_x = curr_x + dx[i];
    if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
    if(visited[next_y][next_x]) continue;
    if(map[next_y][next_x] == 0) continue;
    dfs({next_y, next_x});
  }
}

int main() {
  cin >> N;
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      int height;
      cin >> height;
      if(height > N) {
        map[y][x] = 1;
      } else {
        map[y][x] = 0;
      }
    }
  }

  int cnt = 0;
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      if(visited[y][x] == 0 && map[y][x] == 1) {
        dfs({y, x});
        cnt++;
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}