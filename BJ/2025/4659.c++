#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int t;

int main() {
  while(1) {
    string s;
    cin >> s;
    if(s == "end") break;

    // 검증
    // char arr[] = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel = false;
    bool isValid = true;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') isVowel = true;
      int vowelCnt = 0;
      if(i+2 < s.size()) {
        for(int j = i; j < i+3; j++) {
          if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') vowelCnt++;
        }
        if(vowelCnt == 0 || vowelCnt == 3) isValid = false; 
      }
      if(i > 0 && s[i-1] == s[i]) {
        if(s[i] == 'e' || s[i] == 'o') break;
        isValid = false;
      }
    }
    if(!isVowel) isValid = false;
    
    string ret = "<" + s + ">" + " is ";
    ret += isValid ? "acceptable." : "not acceptable.";

    cout << ret << "\n";

  }
  return 0;
}