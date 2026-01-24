#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main() {
  string s, rot;
  getline(cin, s);
  rot = s;

  for(int i = 0; i < s.length(); i++) {
    if(s[i] >= 'a' && s[i] <= 'z') {
      rot[i] = (s[i] - 'a' + 13) % 26 + 'a';
    } 
    else if(s[i] >= 'A' && s[i] <= 'Z') {
      rot[i] = (s[i] - 'A' + 13) % 26 + 'A';
    } 
    else {
      rot[i] = s[i];
    }
  }

  cout << rot;

  return 0;
}