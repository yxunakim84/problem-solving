#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1005];
bool visited[1005];
vector<int> dfs_route;
vector<int> bfs_route;

void dfs(int startNode) {
  visited[startNode] = true;
  dfs_route.push_back(startNode);
  
  for(int i = 0; i < graph[startNode].size(); i++) {
    int nextNode = graph[startNode][i];
    if(!visited[nextNode]) {
      dfs(nextNode);
    }
  }
}

void bfs(int startNode) {
  // queue 사용
  queue<int> q;
  q.push(startNode);
  visited[startNode] = true;
  bfs_route.push_back(startNode);
  
  // q에 있는 값을 계속 꺼낸다.
  while(!q.empty()) {
    int currentNode = q.front();
    q.pop();
    for(int i = 0; i < graph[currentNode].size(); i++) {
      int nextNode = graph[currentNode][i];
      if(!visited[nextNode]) { 
        visited[nextNode] = true;
        q.push(nextNode);
        bfs_route.push_back(nextNode);
      }
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

  // 정렬
  for(int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(V);

  for(int i = 0; i <= N; i++) {
    visited[i] = false;
  }

  bfs(V);

  for(int i = 0; i < dfs_route.size(); i++) {
    printf("%d ", dfs_route[i]);
  }
  
  printf("\n");

  for(int i = 0; i < bfs_route.size(); i++) {
    printf("%d ", bfs_route[i]);
  }
  
  return 0;
}