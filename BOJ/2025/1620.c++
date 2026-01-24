#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<string, int> mp;
map<int, string> mp2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> N >> M;
  // 이름
  for(int i = 0; i < N; i++) {
    string name;
    cin >> name;
    mp[name] = i + 1;
    mp2[i+1] = name;
  }

  // 명령
  for(int j = 0; j < M; j++) {
    string input;
    cin >> input;
    if(atoi(input.c_str()) == 0) {
      cout << mp[input] << "\n";
    } else {
      cout << mp2[atoi(input.c_str())] << "\n";
    }
  }


  return 0;
}