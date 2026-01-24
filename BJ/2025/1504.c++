#include <stdio.h>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

long long Min(long long a, long long b) { return a < b ? a : b; }

int N, E;
vector<pair<int, int>> graph[805]; //node-{node, dist}


// 1 -> v1, 1 -> v2
// v1 -> v2, v1 -> N
// v2 -> v1, v2 -> N
vector<int> dijkstra(int start) {
  vector<int> dist;
  dist.assign(N + 1, INT_MAX);
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start}); //{dist, node}

  while(!pq.empty()) {
    int curr_node = pq.top().second;
    int curr_dist = pq.top().first;
    pq.pop();

    if(curr_dist > dist[curr_node]) continue;

    for(int i = 0; i < graph[curr_node].size(); i++) {
      int next_node = graph[curr_node][i].first;
      int next_dist = graph[curr_node][i].second;
      int total = curr_dist + next_dist;
      if(total < dist[next_node]) dist[next_node] = total; pq.push({ total, next_node });
    }
  }

  return dist;

}

int main() {
  scanf("%d %d", &N, &E);
  for(int i = 0; i < E; i++) {
    int a, b, c; // a~b 정점까지. 거리 c
    scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  int v1, v2; //v1, v2를 반드시 거쳐가는 b까지 가는 최단 경로..
  scanf("%d %d", &v1, &v2);

  vector<int> dist_from_1 = dijkstra(1);
  vector<int> dist_from_v1 = dijkstra(v1);
  vector<int> dist_from_v2 = dijkstra(v2);

  // 1: 1 -> v1 -> v2 -> N
  long long path1 = (long long)dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N];
  // 2: 1 -> v2 -> v1 -> N
  long long path2 = (long long)dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N];

  long long result = Min(path1, path2);

  if(result >= INT_MAX) {
    printf("-1\n");
  } else {
    printf("%lld\n", result);
  }

  return 0;
}