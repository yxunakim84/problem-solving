#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, L, R;
int arr[55][55];
int visited[55][55];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int movedDay = 0;

bool bfs(int start_y, int start_x) {
  
  int total = 0;
  visited[start_y][start_x] = 1;
  queue<pair<int, int>> q;
  queue<pair<int, int>> copy_q;
  q.push({start_y, start_x});
  copy_q.push({start_y, start_x});
  total += arr[start_y][start_x];
  
  bool isMoved = false;
  
  while(!q.empty()) {
    int cy, cx;
    tie(cy, cx) = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny >= N || nx >= N || ny < 0 || nx < 0) continue;
      if(visited[ny][nx]) continue;
      int diff = abs(arr[cy][cx] - arr[ny][nx]);
      if(diff >= L && diff <= R) {
        q.push({ny, nx});
        copy_q.push({ny, nx});
        visited[ny][nx] = 1;
        isMoved = true;
        total += arr[ny][nx];
      }
    }
  }
  if(!isMoved) return isMoved;
  int ret = total / copy_q.size();
  while (!copy_q.empty()) {
    arr[copy_q.front().first][copy_q.front().second] = ret;
    copy_q.pop();
  }
  
  return isMoved;
}

int main() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  
  while(true) {
    memset(visited, 0, sizeof(visited));
    
    bool anyMovedToday = false;
    // {i, j} 좌표를 q에 넣어줌
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(!visited[i][j]) {
          bool movedThisUnion = bfs(i, j);
          if(movedThisUnion) {
            anyMovedToday = true;
          }
        }
      }
    }

    // 3. 오늘 아무 이동도 없으면 종료
    if (!anyMovedToday) break;

    // 4. 이동이 있었다면 날짜 +1
    movedDay++;
  }

  cout << movedDay << "\n";
  return 0;
}