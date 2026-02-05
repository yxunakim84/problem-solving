/**
 * combi에서 return을 꼭 챙기자
 * 배열(map) 복사
 * 범위 경계값 next_x >= N (8이 아니고 N or M)
 */
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int NEW_WALL = 3;
int N, M;
vector<pair<int, int>> empty_room;
vector<pair<int, int>> virus_room;
int map[8][8];
bool visited[8][8];

int x_dir[] = {0, 1, 0, -1};
int y_dir[] = {1, 0, -1, 0};

int max_safe_cnt = 0;

void dfs(int x, int y, int (&temp)[8][8]) {
  
  for(int i = 0; i < 4; i++) {
    int next_x = x + x_dir[i];
    int next_y = y + y_dir[i];
    
    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
    
    if(temp[next_x][next_y] != 0 || visited[next_x][next_y]) continue;
    // if(temp[next_x][next_y] == 0 && !visited[next_x][next_y])  {
    //   temp[next_x][next_y] = 2;
    //   dfs(next_x, next_y, temp);
    // }
    visited[x][y] = true;
    temp[next_x][next_y] = 2;
    dfs(next_x, next_y, temp);

  }
}

void combi(int start, vector<pair<int, int>>& _selected_empty) {
  if(_selected_empty.size() == NEW_WALL) {
    int temp[8][8];
    memcpy(temp, map, sizeof(map));
    memset(visited, false, sizeof(visited));
    
    // 선택된 공간에 벽 세우기
    for(int i = 0; i < NEW_WALL; i++) {
      temp[_selected_empty[i].first][_selected_empty[i].second] = 1;
    }
    // 안전지역 탐색 > 1만나기 전까지 2확산 > dfs?
    for(auto it: virus_room) {
      dfs(it.first, it.second, temp);
    }
    // 최종 map에서 0개수 구하기
    int safe_cnt = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(temp[i][j] == 0) safe_cnt++;
      }
    }

    max_safe_cnt = max(max_safe_cnt, safe_cnt);
    return;
  }

  for(int i = start+1; i < empty_room.size(); i++) {
    _selected_empty.push_back(empty_room[i]);
    combi(i, _selected_empty);
    _selected_empty.pop_back();
  }
}

int main() {
  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> map[i][j];
      // 빈공간
      if(map[i][j] == 0) {
        empty_room.push_back({i, j});
      }
      // 바이러스
      else if(map[i][j] == 2) {
        virus_room.push_back({i, j});
      }
    }
  }

  // empty를 순회하면서 3개 뽑기
  vector<pair<int, int>> selected_empty;
  combi(-1, selected_empty);

  cout << max_safe_cnt << "\n";



  return 0;
}