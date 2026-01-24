#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[105];
bool visited[105] = {false};

void dfs(int startNode) {
  visited[startNode] = true;

  for(int i = 0; i < graph[startNode].size(); i++) {
    int nextNode = graph[startNode][i];
    if(!visited[nextNode]) {
      dfs(nextNode);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M); //컴퓨터 수

  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b); // 간선 정보 연결
    graph[b].push_back(a);
  }

  dfs(1); // 1번 컴퓨터부터 시작

  int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(visited[i]) cnt++;
  }

  printf("%d", cnt - 1);

  return 0;
}