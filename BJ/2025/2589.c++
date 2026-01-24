#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

char map[65][65];
// vector<string> map;

int visited[50][50];
int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int max_ret = 0;

void bfs(int y, int x) {
  memset(visited, 0, sizeof(visited));
  visited[y][x] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});
  int cdist;

  while(!q.empty()) {
    int cy, cx;
    tie(cy, cx) = q.front();
    cdist = visited[cy][cx];
    q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = dy[i] + cy;
      int nx = dx[i] + cx;
      if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
      if(map[ny][nx] != 'L') continue;
      if(visited[ny][nx]) continue;
      visited[ny][nx] = cdist + 1;
      q.push({ny, nx});
    }
  }
  //cdist가 나올 것.
  // if(max_ret < cdist) max_ret = cdist;
  max_ret = max(max_ret, cdist);
}

int main() {
  // 육지 L 바다 w
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> map[i];
  }
  cout << "\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << map[i][j];
    }
    cout << "\n";
  }
  

  // 출발지점을 시작으로, (최단거리로) 이동가능한 곳까지 최대한 간다. 그 max값을 저장
  // bfs를 반복...
  // 끊긴 곳이 있을 수 있으므로 segment component?
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      // 기존 bfs랑 다른 점은, 시작 지점 visited 체크 안 한다는 것
      if(map[i][j] == 'L') {
        bfs(i, j);
      }
    }
  }

  cout << max_ret - 1 << "\n";
  return 0;
}