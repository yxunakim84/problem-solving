#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int arr[300000];
int result = 987654321;

// 최댓값으로 잡을 범위가 part인거고, ret은 그렇게 묶었을 때 나오는 묶음 개수
bool search(int part) {
  int ret = 0;
  for(int i = 0; i < m; i++) {
    ret += arr[m] / part;
    if(ret % part) ret++; // 나머지는 part 보다 무조건 적음. 그냥 한 사람한테 주면 됨. 인원은 한 명 추가인거니까 +1
  }

  // 모든 인원이 다 받을 필요가 없음
  return ret <= n;
}

int main() {
  cin >> n >> m;
  int l, r, m;
  l = 1; // 가장 많이 받는 경우 최소 1
  r = -1;
  for(int i = 0; i < m; i++) {
    cin >> arr[i];
    r = max(r, arr[i]); // 가장 많이 받는 경우 가장 큰 값을 통째로 받을 수도
  }
  
  while(l <= r) {
    m = (l + r) / 2;
    if(search(m)) {
      result = min(result, m);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << result << "\n";


  return 0;
}