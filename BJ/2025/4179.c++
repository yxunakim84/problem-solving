#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int R, C;
char map[1005][1005];
int visited[1005][1005];
int fire_visited[1005][1005];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int ret;

void bfs(int y, int x, int arr[1005][1005]) {
  arr[y][x] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});
  
  while(!q.empty()) {
    int curr_y, curr_x;
    tie(curr_y, curr_x) = q.front();
    int curr_dist = arr[curr_y][curr_x];
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_y = curr_y + dy[i];
      int next_x = curr_x + dx[i];
  
      if(next_y >= R || next_y < 0 || next_x >= C || next_x < 0) continue;
      if(map[next_y][next_x] == '#') continue;
      if(arr[next_y][next_x]) continue;
      q.push({next_y, next_x});
      arr[next_y][next_x] = curr_dist + 1;
    }
  }
}

int main() {
  pair<int, int> pos;
  vector<pair<int, int>> f_pos;
  queue<pair<int, int>> q;

  cin >> R >> C;
  fill(&fire_visited[0][0], &fire_visited[0][0] + 1005 * 1005, INF);

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> map[i][j];
      if(map[i][j] == 'J') {
        pos = {i, j};
        visited[i][j] = 1;
      }
      if(map[i][j] == 'F') {
        q.push({i, j});
        fire_visited[i][j] = 1;
      }
    }
  }
  
  // 불들의 시작 자리를 그냥 queue에 넣어주면 됨. 그럼 bfs로 자동으로 최단거리들 기록되는 것
  
  // 불의 초기 위치들을 큐에 전부 집어 넣어서 좌표마다 방문거리 계산
  while(!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= R || ny < 0 || nx >= C || nx < 0) continue;
      if(fire_visited[ny][nx] != INF || map[ny][nx] == '#') continue;
      fire_visited[ny][nx] = fire_visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  q.push({pos});
  while(!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    
    if(y == R-1 || x == C-1 || y == 0 || x == 0) {
      ret = visited[y][x];
      break;
    }

    for(int i = 0; i < 4; i++) {
      int ny = dy[i] + y;
      int nx = dx[i] + x;
      if(ny >= R || ny < 0 || nx >= C || nx < 0) continue;
      if(visited[ny][nx] || map[ny][nx] == '#') continue;
      //이미 불이 앞지른 길은 가지 않는다
      if(fire_visited[ny][nx] <= visited[y][x] + 1) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny,nx});
    }
  }

  if(ret != 0) cout << ret << "\n";
  else cout << "IMPOSSIBLE";


  return 0;
}