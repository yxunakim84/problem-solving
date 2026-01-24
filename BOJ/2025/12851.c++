#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001];

int cal(int val, int op) {
  if(op == 0) {
    return (val + 1);
  }
  if(op == 1) {
    return (val - 1);
  }
  if(op == 2) {
    return (val * 2);
  }
}

int cnt = 0;
int ans = 987654321;
void bfs(int start) {
  visited[start] = 1;
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int cur = q.front();
    int cur_dist = visited[cur];
    q.pop();
    if(cur == K) {
      if(ans > cur_dist) {
        ans = cur_dist;
        cnt = 1;
      } else if(ans == cur_dist) {
        cnt++;
      }
    }
    for(int i = 0; i < 3; i++) {
     int _next = cal(cur, i);
     if(_next < 0 || _next > 100000) continue;
     // 이미 방문했는데 그 값이 더 작은 값이면?
     if(visited[_next] && visited[_next] < cur_dist + 1) continue;
     visited[_next] = cur_dist + 1;
     q.push(_next);
    }
  }
}

int main() {
  cin >> N >> K;
  // x-1, x+1, x*2
  // 수빈이는 움직이고, 동생은 고정. 방향은 총 세 가지

  bfs(N);

  cout << visited[K] - 1 << "\n" << cnt << "\n";
  return 0;
}