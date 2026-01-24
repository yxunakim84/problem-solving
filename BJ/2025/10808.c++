#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <string>

using namespace std;


int main() {
  
  // char S[105];
  // int arr[26] = {0};

  // scanf("%s", S);

  // sort(S, S + strlen(S));

  // for(int i = 0; i < strlen(S); i++) {
  //   arr[S[i] - 'a']++;
  // }

  // for(int i = 0; i < 26; i++) {
  //   printf("%d ", arr[i]);
  // }


  string word;
  int alphabet[26] = {0};

  cin >> word;

  for(int i = 0; i < word.length(); i++) {
    alphabet[word[i] - 'a']++;
  }

  for(int i = 0; i < 26; i++) {
    cout << alphabet[i] << ' ';
  }


  // for(auto p:mp) {
  //   printf("%cc")
  // }
  // string S;
  // cin >> S;
  // map<char, int> mp ={};

  // for(int i = 0; i < S.length(); i++) {
  //   mp[S[i]] += 0;
  // }


  return 0;
} 