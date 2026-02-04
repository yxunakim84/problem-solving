#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {

  int N, K;
  cin >> N >> K;
  
  vector<pair<int, int>> jewels(N);
  vector<int> bags(K);

  for(int i = 0; i < N; i++) {
    cin >> jewels[i].first >> jewels[i].second;
  }
  for(int i = 0; i < K; i++) {
    cin >> bags[i];
  }
  
  // 가방 작은것부터
  sort(bags.begin(), bags.end());
  
  // 보석 무게 작은것부터
  sort(jewels.begin(), jewels.end());
  int j_index = 0;
  priority_queue<int> pq;
  long long sum = 0;

  for(auto it : bags) {
    while(j_index < jewels.size() && jewels[j_index].first <= it) {
      pq.push(jewels[j_index++].second); // pq에는 무게 가능한 보석들 중 값이 가장 큰 것 순으로 정렬됨
    }
    if(!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }

  cout << sum << "\n";
  
  return 0;
}