#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[100005], mx, ret, lo, hi;

bool check(int mid) {
  int cnt = 1, temp = mid;

  for(int i = 0; i < n; i++) {
    if(mid - a[i] < 0) {
      mid = temp;
      cnt++; //인출
    }
    mid -= a[i];
  }
  return cnt <= m;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }
  lo = mx; hi = 1000000004;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      hi -= 1;
      ret = mid;
    }
    else {
      lo += 1;
    }
  }
  return 0;
}