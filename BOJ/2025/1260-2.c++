#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
// vector<pair<int, int>> v;
vector<int> graph[1005];
vector<int> dfs_route; // 탐색하면서 방문한 노드들을 순서대로 기록하는데, 방문 순서의 개수가 초기에 고정 x, 유동적이기 때문에 vector로 선언
vector<int> bfs_route;
bool visited[1005];

void dfs(int startNode) {
  visited[startNode] = true;
  dfs_route.push_back(startNode);
  
  for(int i = 0; i < graph[startNode].size(); i++) {
    int nextNode = graph[startNode][i];
    if(visited[nextNode]) continue;
    dfs(nextNode);
  }
}

void bfs(int startNode) {
  // queue 사용
  queue<int> q;
  q.push(startNode);
  visited[startNode] = true;
  bfs_route.push_back(startNode);

  while(!q.empty()) {
    int currentNode = q.front();
    q.pop();
    // 큐에서 현재 노드를 다시 뽑아서, 
    for(int i = 0; i < graph[currentNode].size(); i++) {
      int nextNode = graph[currentNode][i];
      if(visited[nextNode]) continue;
      visited[nextNode] = true;
      q.push(nextNode);
      bfs_route.push_back(nextNode);
    }
  }
}


int main() {
  scanf("%d %d %d", &N, &M, &V);
  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for(int i = 0; i < N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(V);

  // visited 배열 초기화
  for(int i = 0; i < N; i++) {
    visited[i] = false;
  }

  bfs(V);

  for(int i = 0; i < N; i++) {
    printf("%d ", dfs_route[i]);
  }
  printf("\n");
  for(int i = 0; i < N; i++) {
    printf("%d ", bfs_route[i]);
  }

  return 0;
}