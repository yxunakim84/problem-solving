#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, c;
int arr[1005];
map<int, int> mp, mp_first;
// 뭘로 정렬할건지.
vector<pair<int, int>> v; // (등장횟수, 숫자)
bool cmp(pair<int, int> a, pair<int, int> b) {
  // {5, 2} {4, 1}
  if(a.first == b.first) {
    return mp_first[a.second] < mp_first[b.second];
  }
  return a.first > b.first;
}

int main() {
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    int key;
    cin >> key;
    if(mp[key] == 0) {
      mp_first[key] = i;
    }
    mp[key] += 1;
  }

  for(auto it:mp) {
    v.push_back({it.second, it.first});
    // {5번 등장, 2라는 값이}
  }

  sort(v.begin(), v.end(), cmp);

  for(auto it:v) {
    for(int i = 0; i < it.first; i++) {
      cout << it.second << " ";
    }
  }
  

  return 0;
}