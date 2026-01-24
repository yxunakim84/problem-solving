#include <stdio.h>
#include <vector>
#include <limits.h>
#include <queue>

#define INF 21987654321

using namespace std;
/*
1. 주어지는 노드-간선-가중치를 담을 vector pair 그래프
2. 0,1,2,3.. 노드가 있다고 할 때 각 노드에 대한 거리값을 담을 1차원 배열
3. 다익스트라는 최단거리 위주로 탐색을 진행하므로 우선순위큐를 통해 탐색할 노드들을 '가중치' 기준으로 넣어줌
*/

vector<int> dijkstra(int start, int N, vector<pair<int, int>> graph[]) {
  // 거리 저장 배열
  vector<int> dist(N, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  dist[start] = 0; // 시작점 to 시작점은 거리가 0이므로.
  pq.push({0, start}); // 시작점을 큐에 넣어준다.

  while(!pq.empty()) {
    int cur_dist = pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();
    // 해당 노드의 인접 노드들을 돌아야됨.
    for(int i = 0; i < graph[cur_node].size(); i++) {
      int nxt_node = graph[cur_node][i].first; // 인접 정점 번호
      int nxt_dist = graph[cur_node][i].second; // 인접 정점까지의 거리
      int total_dist = cur_dist + nxt_dist;
      if(total_dist < dist[nxt_node]) {
        dist[nxt_node] = total_dist;
      }
    }
  }
  return dist;
}

int main() {
  const int N = 10; // 노드가 10개라고 가정
  int E = 20; // 간선의 개수는 20개라고 가정
  vector<pair<int, int>> graph[N]; // 그래프 형태. 각 노드에 연결된 간선 정보 그래프에 등록
  
  for(int i = 0; i < N; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    graph[from].push_back({to, cost});
  }

  vector<int> dist = dijkstra(0, N, graph);

  return 0;

}