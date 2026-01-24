#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int map[105][105];
int visited[105][105];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(pair<int, int> start) {
  visited[start.first][start.second] = 1;
  queue<pair<int, int>> q;
  q.push({start.first, start.second});

  while(!q.empty()) {
    int curr_y, curr_x;
    tie(curr_y, curr_x) = q.front();
    q.pop();
    int curr_dist = visited[curr_y][curr_x];
    
    for(int i = 0; i < 4; i++) {
      int next_y = curr_y + dy[i];
      int next_x = curr_x + dx[i];
      if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
      if(visited[next_y][next_x]) continue;
      if(map[next_y][next_x] == 0) continue;
      visited[next_y][next_x] = curr_dist + 1;
      q.push({next_y, next_x});
    }
  }
}

int main() {
  cin >> N >> M;
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      scanf("%1d", &map[y][x]);
    }
  }

  bfs({0, 0});

  cout << visited[N-1][M-1] << "\n";

  return 0;
}