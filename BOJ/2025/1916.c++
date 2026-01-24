#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M; // 도시 N개, 간선 M개
vector<pair<int, int>> graph[1005];
vector<int> dist;

int dijkstra(int startNode, int endNode) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  // { 거리, 노드 번호 }
  dist.assign(N+1, INT_MAX);
  dist[startNode] = 0;

  pq.push({0, startNode});

  while(!pq.empty()) {
    int curr_node = pq.top().second;
    int curr_dist = pq.top().first;
    pq.pop();

    if(dist[curr_node] < curr_dist) continue;
    // ⭐️ 큐에서 꺼낸 경로의 거리가 이미 기록된 최단 거리보다 길다면, 이 경로는 더 이상 볼 필요 없음

    for(int i = 0; i < graph[curr_node].size(); i++) {
      int next_node = graph[curr_node][i].first; // from
      int next_dist = graph[curr_node][i].second; // cost
      int total_new_dist = curr_dist + next_dist;
      if(total_new_dist < dist[next_node]) {
        dist[next_node] = total_new_dist;
        pq.push({dist[next_node], next_node});
      }
    }
  }

  return dist[endNode];

}

int main() {
  scanf("%d", &N);
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    // 출발 도시 번호, 도착지 도시 번호, 비용
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    graph[from].push_back({ to, cost });
  }
  
  int startNode, endNode;
  scanf("%d %d", &startNode, &endNode);
  int ret = dijkstra(startNode, endNode);
  printf("%d", ret);

  return 0;
}