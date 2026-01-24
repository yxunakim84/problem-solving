#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int map[50][50];
int visited[50][50];
int N, M;
int result = 987654321;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

// void print(vector<int> b) {
//   for(int i:b) cout << i << " ";
//   cout << "\n";
// }

vector<vector<int>> chickenList;

void combi(int start, vector<int> v) {
  // 여기에 조합 뽑힌거 어떻게 처리할지가 들어감.
  if(v.size() == M) {
    // 치킨집 조합을 리스트에 Push
    chickenList.push_back(v);
    return;
  }

  for(int i = start+1; i < chicken.size(); i++) {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> map[i][j];
      // 1. 집과 치킨집들 위치 정보(좌표) 저장
      if(map[i][j] == 2) chicken.push_back({i, j});
      if(map[i][j] == 1) home.push_back({i, j});
    }
  }

  vector<int> v; // 조합 뽑을 벡터
  combi(-1, v);

  // 치킨 가게 K개 중에 M개 뽑아서 각 지점까지의 최소 거리 구하기 kCm
  //chickenList: 치킨집 조합이 들어있다.
  // 각 치킨집~집들 사이의 거리
  for(vector<int> cList: chickenList) {
    int ret = 0;
    for(pair<int, int> _home: home) {
      int _min = 987654321;
      // 각 집에서 치킨집까지의 거리
      for(int ch: cList) {
        int _y = abs(_home.first - chicken[ch].first);
        int _x = abs(_home.second - chicken[ch].second);
        int _dist = _y + _x;
        _min = min(_min, _dist);
      }
      ret += _min;
    }
    result = min(result, ret);
  }

  cout << result << "\n";

  return 0;
}