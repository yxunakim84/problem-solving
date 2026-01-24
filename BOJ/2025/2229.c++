#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }

  return 0;
}

// 9 8 7 6 5 4 3 3 2 1
// 1 2 3 3 4 5 6 7 8 9
// 8 6 4 3 1