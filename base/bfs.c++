#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// bfs 최단거리 문제
// 표가 주어졌으므로, dy dx 판단해줘야됨

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int visited[105][105];
int graph[105][105];

int N, M;
pair<int, int> startPosition;
pair<int, int> endPosition;

void bfs(int startY, int startX) {
  visited[startY][startX] = 1;
  queue<pair<int, int>> q;
  q.push({startY, startX});

  while(!q.empty()) {
    int curr_y, curr_x;
    tie(curr_y, curr_x) = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_y = curr_y + dy[i];
      int next_x = curr_x + dx[i];
      int curr_dist = visited[curr_y][curr_x];
      if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
      if(graph[next_y][next_x] == 0) continue;
      if(visited[next_y][next_x]) continue;
      q.push({next_y, next_x});
      visited[next_y][next_x] = curr_dist+1;
    }
  }
}

int main() {
  cin >> N >> M;
  int start_y, start_x;
  int end_y, end_x;
  cin >> start_y >> start_x;
  cin >> end_y >> end_x;

  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      cin >> graph[y][x]; // 0혹은 1의 좌표값을 입력 받음
    }
  }

  bfs(start_y, start_x);

  cout << visited[end_y][end_x] << "\n";

  return 0;
}