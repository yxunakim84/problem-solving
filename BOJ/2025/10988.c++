#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  string reversed;

  cin >> s;

  reversed = s;
  reverse(reversed.begin(), reversed.end());

  int ret = 0;
  if(s == reversed) ret = 1;
  
  cout << ret;

  return 0;
}