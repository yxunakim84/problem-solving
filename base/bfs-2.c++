#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;



/*
int N, M;
int graph[105][105];
int visited[105][105];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void bfs(int startY, int startX) {
  visited[startY][startX] = 1;
  queue<pair<int, int>> q;
  q.push({startY, startX});

  while(!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    int cur_dist = visited[y][x];
    q.pop();
    for(int i = 0; i < 4; i++) {
      int next_y = dy[i] + y;
      int next_x = dx[i] + x;
      if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
      if(visited[next_y][next_x]) continue;
      q.push({next_y, next_x});
      visited[next_y][next_x] = cur_dist + 1;
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
      cin >> graph[y][x];
    }
  }

  bfs(start_y, start_x);

  return 0;
}
*/


// dfs


// 조합
/*
void comb(int start, vector<int> &b) {
  if(b.size()== 3) {
    //print
  }
  for(int i = start + 1; i < 5; i++) {
    b.push_back(i);
    comb(i, b);
    b.pop_back();
  }
}

int main() {
  vector<int> b;
  comb(-1, b);
  return 0;
}
*/


vector<string> split(const string &input, string delimiter) {
  vector<string> result; // 반환할 문자열
  auto start = 0;
  auto end = input.find(delimiter); //index추출됨
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(end != string::npos) {
    result.push_back(input.substr(start, end-start));
    start = end + delimiter.size();
    auto end = input.find(delimiter, start);
  }
}