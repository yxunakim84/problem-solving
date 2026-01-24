#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
// int arr_n[1000001];
vector<int> arr_n;
int arr_m[1000001];

// 매개변수로 배열보다는 벡터 넘겨주기
bool binary_search(vector<int> &arr, int target) {
  int l = 0;
  int r = arr.size() - 1;
  
  while(l <= r) {
    int m = (r + l) / 2;
    if(target < arr[m]) {
      r = m - 1;
    } else if(target > arr[m]) {
      l = m + 1;
    } else if(target == arr[m]) {
      return true;
    }
  }
  
  return false;
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      int val;
      cin >> val;
      arr_n.push_back(val);
    }
    sort(arr_n.begin(), arr_n.end());

    cin >> m;
    for(int i = 0; i < m; i++) {
      int t_val;
      cin >> t_val;
      bool ret = binary_search(arr_n, t_val);
      if(ret == true) cout << "큰돌이는 기억해!" << "\n";
      else cout << "큰돌이는 까먹었어!" << "\n";
    }
  }

  return 0;
}