#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[3][3];
bool visited[3][3];

void go(int y, int x) {
  // 한 좌표를 기준으로 위 옆 아래 탐색
  visited[y][x] = 1;
  cout << y << x << "\n";
  
  for(int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];
    if(a[y][x] == 0) continue;
    if(next_y >= 3 || next_y < 0 || next_x >= 3 || next_x < 0) continue;
    if(a[next_y][next_x] && !visited[next_y][next_x]) {
      go(next_y, next_x);
    }
  }
}
*/

int visited[10];
vector<int> graph[10];

void dfs(int u) {
  visited[u] = 1;
  cout << u << "\n";

  for(int i = 0; graph[u].size(); i++) {
    int v = graph[u][i];
    if(visited[v] == 0) {
      dfs(v);
    }
  }
}

int main() {

dfs(1);






  /*
int y = 0; int x = 0;
go(y, x);
*/
  /*
  string dopa = "umzunsik";
  
 
  // for(int i = 0; i < 3; i++) {
  //   cout << dopa[i];
  // }
  string dopa2 = dopa.substr(0, 3);
  cout << dopa2 << '\n';
  // cout << '\n';
  
  // sort(dopa.begin(), dopa.end(), less());
  reverse(dopa2.begin(), dopa2.end());
  cout << dopa2 << '\n';
  // for(int i = 0; i < dopa.length(); i++) {
  //   cout << dopa[i];
  // }
  
  dopa2 += "umzunsik";
  cout << dopa2 << '\n';
  // for(int i = 0; i < dopa.length(); i++) {
  //   cout << dopa[i];
  // }
 */  


 int arr[105];
// vector<int> v;
 int N;
 cin >> N;

 for(int i = 0; i < N; i++) {
  cin >> arr[i];
 }

//  sort(v.begin(), v.end());
 sort(arr, arr+N);
 double sum = 0;

 for(int i = 0; i < N; i++) {
  cout << arr[i] << ' ';
  sum += arr[i];
 }

 double ret = sum / N;
 printf("%.2f\n", ret);



  return 0;
}