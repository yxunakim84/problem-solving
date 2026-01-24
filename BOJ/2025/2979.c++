#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> v;

int main() {

  // A원 B원 C원
  int A, B, C;
  cin >> A;
  cin >> B;
  cin >> C;

  for(int i = 0; i < 3; i++) {
    int start, end;
    cin >> start >> end;
    v.push_back({start, end});
  }



  int arr[101] = {0};
  for(int i = 0; i < 3; i++) {
    for(int j = v[i].first; j < v[i].second; j++) {
      arr[j]++;
    }
  }

  int cnt_a = 0, cnt_b = 0, cnt_c = 0;
  for(int i = 0; i < 101; i++) {
    if(arr[i] == 1) cnt_a++;
    else if(arr[i] == 2) cnt_b++;
    else if(arr[i] == 3) cnt_c++; 
  }

  int ret = cnt_a * A + cnt_b * B * 2 + cnt_c * C * 3;
  cout << ret << '\n';
  return 0;
}