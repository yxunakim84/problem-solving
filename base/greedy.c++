// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int ret, totalAmount = 12100;
int main() {
  // 각 화폐 단위와 개수를 저장한 벡터
  vector<pair<int, int>> currency = {{10000, 5}, {5000, 5}, {1000, 5},
  {100, 5}};
  // 내림차순으로 정렬
  sort(currency.rbegin(), currency.rend());
  for (auto &c : currency) {
    while (totalAmount >= c.first) {
    totalAmount -= c.first;
    c.second--;
    ret++;
    }
  }
  if(totalAmount == 0) cout << ret << '\n';
  else cout << "불가능합니다. \n";
  return 0;
}