#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int arr[100005];
  int sum[100005] = {0};

  for(int i = 1; i <= N; i++) {
    cin >> arr[i];
    sum[i] = sum[i-1] + arr[i];
  }

  int max = -10000004;
  int j;
  for(int i = 0; i < N-K+1; i++) {
    j = K + i;
    if(max < sum[j] - sum[i]) {
      max = sum[j] - sum[i];
    }
  }

  cout << max;
  return 0;
}