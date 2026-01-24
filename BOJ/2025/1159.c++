#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int N;
int surname[26] = {0};

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    string name;
    cin >> name;
    surname[name[0] - 'a']++;
  }
  
  bool isOverFive = false;

  for(int i = 0; i < 26; i++) {
    if(surname[i] >= 5) {cout << char('a' + i); isOverFive = true;}
  }

  !isOverFive && cout << "PREDAJA";

}