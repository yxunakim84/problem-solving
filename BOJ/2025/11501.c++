#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int arr[1000005];

int main() {
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> n;
    // arr초기화
    memset(arr, 0, sizeof(arr));
    for(int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    int max = 0;
    long long ret = 0;
    for(int k = n-1; k >= 0; k--) {
      if(max < arr[k]) {
        max = arr[k];
      } else {
        ret += (max - arr[k]);
      }
    }
    cout << ret << "\n";

  }

  return 0;
}