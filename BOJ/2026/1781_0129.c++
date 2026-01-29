#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/**
 * max day에서부터 탐색하면서 가능한 것들 중 가장 최대의 것을 넣어주는 방식의 greedy
 */

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> p_list(N);

  int max_day = 0;

  for(int i = 0; i < N; i++) {
    cin >> p_list[i].first >> p_list[i].second;
    max_day = max(max_day, p_list[i].first);
  }

  sort(p_list.rbegin(), p_list.rend());
  
  priority_queue<int> pq;
  int p = 0;
  int ret = 0;
  for(int d = max_day; d > 0; d--) {
    while(p < N && d <= p_list[p].first) {
      pq.push(p_list[p++].second); // 해당 날짜에서 가능한 것들 중 가장 최대의 value를 갖는 것을 찾기 위해 가능한 모든 value들을 pq에 넣는다.
    }
    if(!pq.empty()) {
      ret += pq.top(); // priority queue이므로 맨 앞에 있는 값이 가장 큰 value를 갖는다
      pq.pop();
    }
  }

  cout << ret << "\n";


  return 0;
}