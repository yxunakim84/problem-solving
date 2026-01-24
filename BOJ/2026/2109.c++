#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  int max_day = 0;
  cin >> n;
  vector<pair<int, int>> list(n);

  for(int i = 0; i < n; i++) {
    int p, d;
    cin >> p >> d;
    max_day = max(max_day, d);
    list[i].first = d; list[i].second = p;
  }

  sort(list.rbegin(), list.rend());

  priority_queue<int> pq;
  int cnt = 0;
  long long ret = 0;
  for(int day = max_day; day >= 1; day--) {
    while(cnt < n && list[cnt].first >= day) {
      pq.push(list[cnt].second);
      cnt++;
    }
    if(pq.size()) {
      ret += pq.top(); pq.pop();
    }
  }
  
  cout << ret << "\n";
  
  return 0;
}