#include <stdio.h>

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[100001]; // 그래프를 인접 리스트로 표현
bool visited[100001]; // 방문 여부를 체크하는 배열



void dfs(int currentNode) {
  // 1. 현재 노드를 방문 처리
  visited[currentNode] = true;
  printf("%d ", currentNode);

  // 2. 현재 노드와 연결된 모든 노드를 재귀적으로 방문
  // while (!graph[currentNode].empty()) {
  // }
  for(int i = 0; i < graph[currentNode].size(); i++) {
    int nextNode = graph[currentNode][i];
    if(!visited[nextNode]) dfs(nextNode); // 인접 노드를 아직 방문하지 않았다면 더 깊이 들어간다.
  }
}

void dfs_stack(int startNode) {
  stack<int> s; // int 자료형으로 구성된 stack
  // 방문하는 노드들을 전부 이 스택에 넣어주는 것. 중복될 수 있으므로 visited check 필수
  // 1. 시작 노드를 스택에 넣는다.
  s.push(startNode);

  // 2. 스택이 빌 때까지 반복한다.
  while(!s.empty()) {
    int currentNode = s.top();
    s.pop(); // currentNode 조회 후 꺼낸 것.
    
    if(visited[currentNode]) continue;

    visited[currentNode] = true;
    printf("%d ", currentNode);
      
    // 3. 현재 
    for(int i = 0; i < graph[currentNode].size(); i++) {
      int nextNode = graph[currentNode][i];
      if(!visited[nextNode]) {
        s.push(nextNode);
      }
    }
  }
}


void bfs(int startNode) {
  queue<int> q;

  q.push(startNode);

  while(!q.empty()) {
    int currentNode = q.front();
    q.pop();
    printf("%d ", currentNode);
    
    for(int i = 0; i < graph[currentNode].size(); i++) {
      int nextNode = graph[currentNode][i];
      if(!visited[nextNode]) {
        q.push(nextNode);
        visited[currentNode] = true;
      }
    }
  }
}


int main(void) {
 // 예시 그래프 설정 (간선 연결)
    // 1-2, 1-3, 2-4, 2-5, 3-6, 3-7, 4-8, 5-8
    graph[1].push_back(2);
    graph[1].push_back(3);
    
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[3].push_back(6);
    graph[3].push_back(7);

    graph[4].push_back(2);
    graph[4].push_back(8);

    graph[5].push_back(2);
    graph[5].push_back(8);

    graph[6].push_back(3);
    graph[7].push_back(3);
    graph[8].push_back(4);
    graph[8].push_back(5);

    dfs(1);


    return 0;
}