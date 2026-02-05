#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
/*
vector<pair<int, int>> graph[1005]; //도시 개수만큼
vector<int> dist(1005, INF); //도시(=사람) 개수만큼
int N, M, K; // 사람, 도로, 도착지
int ret_dist[1005];

void find(int start) {
  // 출발지가 여러개이므로 dist 배열 매번 초기화
  fill(dist.begin(), dist.end(), INF);

  // dist가 작은 것부터 탐색하도록 우선순위큐 Minheap
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  dist[start] = 0; //start-start는 0
  
  while(!pq.empty()) {
    int curr = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    for(auto it : graph[curr]) {
      int next = it.first;
      int acc_cost = cost + it.second;

      if(dist[next] > acc_cost) { // 저장된 거리보다 현재 탐색중인 거리가 더 짧으면 갱신
        dist[next] = acc_cost;
        pq.push({acc_cost, next});
      }
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K; 
  // 출발지 - 도착지, 거리
  
  for(int i = 0; i < M; i++) {
    int start, end, cost;
    cin >> start >> end >> cost;
    graph[start].push_back({end, cost});
  }
  
  // 각 지점에서 목적지까지 걸리는 총 시간 (올때, 갈때 각각)
  for(int i = 0; i < N; i++) {
    find(i+1);
    ret_dist[i+1] = dist[K];
  }
  
  int max_dist = -1;
  // 목적지에서 각 도시까지
  find(K);
  for(int i = 0; i < N; i++) {
    max_dist = max(max_dist, ret_dist[i+1]+dist[i+1]);
  }

  cout << max_dist << "\n";

  return 0;
}

*/


vector<pair<int, int>> graph[1005];
vector<pair<int, int>> rev_graph[1005];
vector<int> dist(1005, INF);
vector<int> rev_dist(1005, INF);
int N, M, K; // 사람, 도로, 도착지

void dijkstra(int start, vector<pair<int, int>>* _graph, vector<int>& _dist) {
  // dist가 작은 것부터 탐색하도록 우선순위큐 Minheap
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  _dist[start] = 0;
  
  while(!pq.empty()) {
    int curr = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    for(auto it : _graph[curr]) {
      int next = it.first;
      int acc_cost = cost + it.second;

      if(_dist[next] > acc_cost) {
        _dist[next] = acc_cost;
        pq.push({acc_cost, next});
      }
    }
  }

}

int main() {
  cin >> N >> M >> K;

  for(int i = 0; i < M; i++) {
    int start, end, cost;
    cin >> start >> end >> cost;
    graph[start].push_back({end, cost});
    rev_graph[end].push_back({start, cost});
  }

  // 출발지 K에 대한 rev_graph (파티 갈 때)
  dijkstra(K, rev_graph, rev_dist);

  // 출발지 K에 대한 graph (돌아올 때)
  dijkstra(K, graph, dist);
  
  int max_dist = -1;

  for(int i = 0; i < N; i++) {
    max_dist = max(max_dist, rev_dist[i+1] + dist[i+1]);
  }

  cout << max_dist << "\n";

  return 0;
}