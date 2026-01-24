#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

void print(vector<int> b) {
  for(int i : b) cout << i << " ";
  cout << "\n";
  return;
}

void combi(int start, vector<int> &b) {
  // 기저조건
  if(b.size() == k) {
    print(b);
  }
  // i는 항상 start+1부터 시작 <- 앞으로만 전진하므로. (순열은 0부터 시작했음)
  for(int i = start + 1; i < n; i++) {
    b.push_back(a[i]);
    combi(i, b);
    b.pop_back();
  }
}

int combiMain() {
  vector<int> b;
  combi(-1, b);
  return 0;
}


/*

// 5C1, 5C2, ..등 여러 개의 경우의 수를 따져야 할 때 > 비트마스킹

const int n = 4;
int bitmasking() {
  string arr[n] = {"사과", "딸기", "포도", "배"};
  for(int i = 0; i < (1 << n); i++) { // 1<<4, 2^4 = 16 (총 16개 경우의 수)
    string ret = "";
    cout << i << ":";
    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) {
        ret += (arr[j] + " ");
      }
    }
    cout << ret << "\n";
  }
}

int main() {
  const int n = 4;
  string a[n] = {"사과", "딸기", "포도", "배"};
  
  // i는
  // 0000, 0001, 0010, 0100, 1000, 0011, ... 이렇게 총 16개 존재. (0~15)
 
  for(int i = 0; i < (1 << n); i++) { // 1<<4 => 10000 = 16.
    int cnt = 0;
    // 1. 먼저 비트가 몇 개 켜졌는지(r) 센다
    // 비트가 1이면 켜졌다는 뜻. -> 켜진 개수를 cnt에 저장.
    for(int j = 0; j < n; j++) { // (0~3) / n은4 
        if(i & (1 << j)) cnt++; // 1 << 0 은 0001, 1 << 1 은 0010, ..0100, ..1000 
    }

    // 2. 내가 원하는 개수(예: 2개)일 때만 출력한다
    // 즉, cnt == 2는 비트가 n개 중에 2개 켜졌다, 선택되었다는 뜻
    if(cnt == 2) { 
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) cout << a[j] << " ";
        }
        cout << "\n";
    }
  }
}
*/