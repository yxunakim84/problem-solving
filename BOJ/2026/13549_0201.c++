#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
const int INF = 1e9;
vector<int> dist(100001, INF); // cost 누적


void find(int start) {

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소힙
  pq.push({0, start});
  dist[start] = 0;
  while(!pq.empty()) {
    int here_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    
    if(dist[u] < here_cost) continue;

    // x-1
    if(u-1 >=0 && u-1<=100000 && dist[u-1] > here_cost+1) {
      pq.push({here_cost+1, u-1});
      dist[u-1] = here_cost+1;
    }
    
    // x+1
    if(u+1 >=0 && u+1<=100000 && dist[u+1] > here_cost+1) {
      pq.push({here_cost+1, u+1});
      dist[u+1] = here_cost+1;
    }
    
    // x*2
    if(u*2 >=0 && u*2<=100000 && dist[u*2] > here_cost) {
      pq.push({here_cost, u*2});
      dist[u*2] = here_cost;
    }

  }

}

int main() {
  cin >> N >> K;
  // 시작위치
  find(N);

  cout << dist[K] << "\n";

  return 0;
}