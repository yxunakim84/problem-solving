#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

/*
1. 치킨가게들 좌표를 저장하고 그 중에 M개를 뽑는 조합을 실행

2. 조합 구현 코드의 기저 조건에서, 각 집에서 치킨집들까지를 하나씩 순회하면서 최소 거리를 저장

3. 각 집에 대한 순회가 끝나면 모든 집들의 최소 거리 합을 구해서 값이 가장 작은 경우를 선택
*/

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int N, M;
int min_distance_sum = 1e9;

void combi(vector<pair<int, int>> &selected_chicken, int start) {
  // 기저 조건
  if(selected_chicken.size() == M) {
    // 각 집에서 선택된 치킨집들까지의 거리 계산 -> 최소의 치킨 거리
    int distance_sum = 0;
    for(const auto& h : house) {
      int distance = 1e9;
      for(const auto& c : selected_chicken) {
        int temp_distance = abs(h.first - c.first) + abs(h.second - c.second);
        distance = min(distance, temp_distance);
      }
      distance_sum += distance;
    }
    // 각 집에서 가장 최소 거리를 갖는 치킨 거리를 최종값에 더해줌
    min_distance_sum = min(min_distance_sum, distance_sum);
    
    return;
  }

  for(int i = start + 1; i < chicken.size(); i++) {
    selected_chicken.push_back(chicken[i]);
    combi(selected_chicken, i);
    selected_chicken.pop_back();
  }

}


int main() {
  cin >> N >> M;

  // 좌표값들 저장
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int flag;
      cin >> flag;
      switch(flag) {
        case 1: house.push_back({i, j}); break;
        case 2: chicken.push_back({i, j}); break;
        default: break;
      }
    }
  }

  // 치킨집들 중에 M개 뽑기
  vector<pair<int, int>> selected_chicken;
  combi(selected_chicken, -1);


  cout << min_distance_sum << "\n";

  return 0;
}