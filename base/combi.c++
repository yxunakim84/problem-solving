#include <vector>
#include <iostream>
using namespace std;

int k, n;

void print(vector<int> b) {
  for(int i:b) cout << i << " ";
  cout << "\n";
}

void combi(int start, vector<int> &b) {
  // 기저조건: 뽑을 개수와 일치하면 해당 벡터 프린트
  if(b.size() == k) {
    print(b);
    return;
  }
  // 벡터에 다음 인수 넣기
  for(int i = start + 1; i < n; i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
  return;
}

int main() {
  vector<int> b;
  combi(-1, b);
  return 0;
}