#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
// #include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, E;
// 거리저장배열. 각 노드 인덱스에 맞게
vector<int> dist(N, INF);
// 그래프 {노드, 가중치}
vector<pair<int, int>> graph[10005];


void dijkstra(int start) {
  // 짧은 경로 알아낼 우선순위 큐 {가중치, 정점}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>()>> pq;
  pq.push({0, start});
  dist[0] = 0;
  while(!pq.empty()) {
    int cur_dist = pq.top().first;
    int cur_node = pq.top().second; // 이 노드와 연결된 간선을 전부 탐색하면 된다.
    pq.pop();
    for(int i = 0; i < graph[cur_node].size(); i++) {
      int next_dist = cur_dist + graph[cur_node][i].second;
      int next_node = graph[cur_node][i].first;
      int total_dist = next_dist + cur_dist;
      if(dist[next_node] > total_dist) {
        dist[next_node] = total_dist;
        pq.push({next_dist, next_node});
      }
    }
  }

}

int main() {
  cin >> N >> E;
  for(int i = 0; i < N; i++) {
    int f, v, w;
    cin >> f >> v >> w;
    graph[f].push_back({v, w});
  }

  dijkstra(0);

  
  return 0;
}