#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int L, C;

void print(vector<char> &selected) {
  for(char alphabet : selected) {
    cout << alphabet;
  }
  cout << "\n";
}

/**
 * 복사값은 원본이 아닌 참조 형식으로 넘기기. vector<char> &selected
 */
void combi(int start, vector<char> &arr, vector<char> &selected, int vowel, int consonant) {
  // 기저조건
  if(selected.size() == L) {
    if(vowel >= 1 && consonant >= 2) {
      print(selected);
    }
    return;
  }
  for(int i = start+1; i < arr.size(); i++) {
    selected.push_back(arr[i]);
    bool isVowel = false;
    if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') isVowel = true;
    combi(i, arr, selected, vowel + (isVowel ? 1 : 0), consonant + (isVowel ? 0 : 1));
    selected.pop_back();
  }
}


int main() {
  vector<char> selected;
  vector<char> arr;

  cin >> L >> C;
  // cCl을 구하면 됨. C개 중 L개를 뽑는 경우의 수 + 오름차순 규칙 => 조합

  // 입력값
  for(int i = 0; i < C; i++) {
    char alphabet;
    cin >> alphabet;
    arr.push_back(alphabet);
  }

  // 오름차순이므로 정렬
  sort(arr.begin(), arr.end());

  combi(-1, arr, selected, 0, 0);

  return 0;
}