#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int arr[3][3] = {
  {10, 20, 21},
  {70, 90, 12},
  {80, 110, 120},
};
int visited[3][3];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> v;


void print() {
  for(int i:v) cout << i << " ";
  cout << "\n";
  // 각 경우의 수 찾으면 바로 출력 후 caller로 돌아감.
}

void go(int y, int x) {
  if(y == 2 && x == 2) {
    print();
    return;
  }
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny >= 3 || ny < 0 || nx >= 3 || nx < 0) continue;
    if(visited[ny][nx]) continue;
    visited[ny][nx] = 1;
    v.push_back(arr[ny][nx]);
    
    go(ny, nx);
    
    // print 되면 다른 경로 찾기 위해서 마지막 경로 삭제
    visited[ny][nx] = 0;
    v.pop_back();
  }
}

int main() {
  // {0,0} - {2,2}
  visited[0][0] = 1;
  v.push_back(arr[0][0]);
  go(0,0);
  return 0;
}