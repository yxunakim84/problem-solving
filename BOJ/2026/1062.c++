#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> word_masks;

int total_max_words = 0;

void combi(int mask, int cnt, int start) {
  // 기저조건
  if(cnt == K) {
    // 총 몇 개의 단어를 알 수 있는지 체크
    int max_words = 0;
    for(int w_mask: word_masks) {
      if((w_mask & mask) == w_mask) { // 읽을 수 있는 단어
        max_words++;
      }
    }
    total_max_words = max(total_max_words, max_words);
    
    return;
  }

  for(int i = start+1; i < 26; i++) {
    if(mask & (1 << i)) continue; // 이미 들어있는 5개 알파벳은 넘어가야함
    else {
      mask |= (1 << i);
      combi(mask, cnt + 1, i);
      mask &= ~(1 << i);
    }
  }
}


int main() {
  cin >> N >> K;
  // 1. a~z까지 26개 중 k개를 뽑는 조합
  // 단, a, n, t, r, c, i => 6개는 무조건 포함. => 20C(k-5)가지

  // 단어들 저장
  for(int i = 0; i < N; i++) {
    string word;
    cin >> word;
    // 단어 자체를 비트마스크로 저장
    int w_mask = 0;
    for(char c: word) {w_mask |= (1 << (c - 'a'));}
    word_masks.push_back(w_mask);
  }
  
  // default S 구현
  int mask = 0;
  char arr[5] = {'a', 'n', 't', 'i', 'c'};
  for(char c:arr) {
    mask |= (1 << (c - 'a'));
  }

  // 알파벳(글자) 개수
  int cnt = 5;

  if(K < cnt) {
    cout << "0" << "\n";
    return 0;
  }

  combi(mask, cnt, -1);

  cout << total_max_words << "\n";

  return 0;
}