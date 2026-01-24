#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[65][65][65];
int visited[65][65][65];
int _case[6][3] = {
  {9, 3, 1},
  {9, 1, 3},
  {3, 9, 1},
  {3, 1, 9},
  {1, 3, 9},
  {1, 9, 3},
};
int a[3];
int n;

struct A {
  int a, b, c;
};

void bfs(int a, int b, int c) {
  visited[a][b][c] = 1;
  queue<A> q;
  q.push({a, b, c});
  
  while(!q.empty()) {
    int curr_a = q.front().a;
    int curr_b = q.front().b;
    int curr_c = q.front().c;
    q.pop();

    for(int i = 0; i < 6; i++) {
      int next_a = max(0, curr_a - _case[i][0]); // 0이하의 값일 수 있으니까.
      int next_b = max(0, curr_b - _case[i][1]);
      int next_c = max(0, curr_c - _case[i][2]);
      if(visited[next_a][next_b][next_c]) continue;
      visited[next_a][next_b][next_c] = visited[curr_a][curr_b][curr_c] + 1;
      q.push({next_a, next_b, next_c});
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bfs(a[0], a[1], a[2]);

  cout << visited[0][0][0] - 1 << "\n";

  return 0;
}