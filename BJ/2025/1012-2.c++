#include <cstdio>
#include <tuple>
#include <iostream>
#include <cstring>

using namespace std;

int TEST_CASE;
int map[55][55] = {0};
int visited[55][55];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int M, N, K;

void dfs(pair<int, int> start) {
  int curr_y, curr_x;
  tie(curr_y, curr_x) = start;
  visited[curr_y][curr_x] = 1; //1이면 true
  
  for(int i = 0; i < 4; i++) {
    int next_y = curr_y + dy[i];
    int next_x = curr_x + dx[i];
    if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
    if(visited[next_y][next_x]) continue;
    if(map[next_y][next_x] == 0) continue;
    dfs({next_y, next_x});
  }
}

int main() {
  cin >> TEST_CASE;
  
  for(int test_case = 0; test_case < TEST_CASE; test_case++) {
    cin >> M >> N >> K;
    // Map 정보 채우기
    for(int i = 0; i < K; i++) {
      int pos_y, pos_x;
      cin >> pos_x >> pos_y;
      map[pos_y][pos_x] = 1;
    }
    
    int cnt = 0;
    // Map 돌면서 1인 곳 기준으로 dfs
    for(int x = 0; x < M; x++) {
      for(int y = 0; y < N; y++) {
        // 이동 가능하고 방문을 안 한 상태
        if(map[y][x] == 1 && visited[y][x] == 0) {
          dfs({y, x});
          cnt++;
        }
      }
    }
   
    cout << cnt << "\n";
    //초기화
    // visited, map
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
  }
  
  return 0;
}