#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m, j;
int basket[12];

int main() {
  cin >> n >> m;
  cin >> j;
  for(int i = 0; i < m; i++) {
    basket[i] = i;
  }
  int ret = 0;
  for(int i = 0; i < j; i++) {
    int apple_p;
    cin >> apple_p;
    int apple = apple_p - 1;
    if(basket[0] <= apple && basket[m-1] >= apple) {
      continue;
    }
    else {
      int val;
      if(apple-basket[0] < 0) {
        val = min(abs(apple-basket[0]), abs(apple-basket[m-1]));
        val = val * -1;
      } else {
        val = min(apple-basket[0], apple-basket[m-1]);
      }
      ret+=abs(val);
      for(int k = 0; k < m; k++) {
        basket[k] += val;
      }
    }
  }
  cout << ret << "\n";

  return 0;
}