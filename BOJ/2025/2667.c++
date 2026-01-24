#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[30][30] ={0};
bool visited[30][30] = {false};
int cnt = 0;

void dfs(int i, int j) {
  visited[i][j] = true;
  cnt++;
  vector<pair<int, int>> arr = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
  for(int i = 0; i < 4; i++) {
    int nextA = arr[i].first;
    int nextB = arr[i].second;
    
    if(nextA < 0 || nextA >= N || nextB < 0 || nextB >= N) continue;

    if(!visited[nextA][nextB] && map[nextA][nextB] == 1) {
      dfs(nextA, nextB);
    }
  }      
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  vector<int> ret;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(map[i][j] == 1 && !visited[i][j]) {
        dfs(i, j);
        ret.push_back(cnt);
        cnt = 0;
      }
    }
  }

  sort(ret.begin(), ret.end());

  printf("%d\n", (int)ret.size());

  for(int i = 0; i < ret.size(); i++) {
    printf("%d\n", ret[i]);
  }
  

  return 0;
}