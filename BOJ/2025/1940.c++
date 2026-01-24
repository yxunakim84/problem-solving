#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[15005];
int temp[15005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  sort(arr, arr+N);
  int sum = 0;
  int cnt = 0;
  
  // 투포인터는 두 포인터의 범위를 기준으로 잡아야함
  int l = 0; int r = N-1;
  while(l < r) {
    sum = arr[l] + arr[r];
    if(sum == M) {cnt++; l++; r--;}
    else if(sum < M) {l++;}
    else r--;
  }
  
  cout << cnt << "\n";

  return 0;
}