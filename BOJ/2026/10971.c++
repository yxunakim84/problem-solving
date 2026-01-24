#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int N;

void combi(int start, vector<int> selected) {
  if(selected.size() == N) {
    // 최솟값 저장?
  }
  
  for(int i = start; i < N; i++) {
    selected.push_back()
  }
}

int main() {
  cin >> N;
  
  vector<vector<int>> v;
  vector<int> selected;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int distance;
      v[i].push_back(distance);
    }
  }
  
  // start 지점 후보: 1,2, 3, 4
  for(int i = 0; i < N; i++) {
    combi(i, selected);
  }
  
  return 0;
}
*/


int N;
int w[11][11];
bool visited[11];
int min_cost = 1e9;

void dfs(int current, int cnt, int cost, int start) {
  if(cnt == N) {
    if(w[current][start] != 0) {
      min_cost = min(min_cost, cost + w[current][start]);
    }
    return;
  }

  for(int i = 0; i < N; i++) {
    if(w[current][i] != 0 && !visited[i]) {
      visited[i] = true;
      dfs(i, cnt + 1, cost + w[current][i], start);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> w[i][j];
    }
  }

  visited[0] = true;
  dfs(0, 1, 0, 0);

  cout << min_cost << "\n";

  return 0;
}