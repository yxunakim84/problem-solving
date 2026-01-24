#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

char matrix[6][6];

int main() {

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
    }
  }
  while(1) {
    string word;
    cin >> word;
    string temp;
    // 시작 단어 좌표
    vector<pair<int, int>> v;

    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        if(matrix[i][j] == word[0]) {
          v.push_back({i, j});
        }
      }
    }

    for(int i = 0; i < v.size(); i++) {
      int a, b;
      tie(a, b) = v[0];
      for(int j = 1; j < word.length(); j++) {
        /*
        a-1, b+1
        a, b-1
        a+1, b+1
        a+1, b
        a+1, b-1
        a, b-1
        a-1, b-1
        a-1, b
        */
      }

    }

  }
  return 0;
}