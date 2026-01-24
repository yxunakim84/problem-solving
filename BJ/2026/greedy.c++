#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

ll N, K;

int main() {
  
  cin >> N >> K;

  vector<pair<ll, ll>> list(N);
  vector<ll> bag(K);

  for(int i = 0; i < N; i++) {
    cin >> list[i].first >> list[i].second;
  }
  
  for(int i = 0; i < K; i++) {
    cin >> bag[i];
  }
  
  sort(list.begin(), list.end());
  sort(bag.begin(), bag.end());
  
  priority_queue<ll> pq;

  int j = 0; // 넣은 보석 index
  int ret = 0;
  // 가방 개수만큼 순회. 하나씩 채워주는거
  for(int i = 0; i < K; i++) { // 다음 bag[i++]는 이전 bag[i]보다 무조건 더 많이 들어감. 그래서 이미 들어간 pq들 전부 넣을 수 있음
    while(j < N && list[j].first <= bag[i]) {
      pq.push(list[j++].second); // 그 가방에 들어갈 수 있는 보석들 후보 리스트
    }
    if(pq.size()) {
      ret += pq.top(); pq.pop();
    }
  }

  cout << ret << "\n";

  return 0;
}