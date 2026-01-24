#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// {headgear: {hat, turban}} map과 vector
map<string, vector<string>> mp;

int main() {
  int test_case;
  cin >> test_case;
  for(int t = 0; t < test_case; t++) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string name; string type;
      cin >> name >> type;
      mp[type].push_back(name);
    }
  
    // 조합
    int sum = 1;
    for(auto it = mp.begin(); it != mp.end(); it++) {
      sum *= ((*it).second.size() + 1);
    }

    cout << sum - 1 << "\n";

    mp.clear();

  }

  return 0;
}