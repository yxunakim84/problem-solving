#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
string s;
int ret = -987654321;

vector<char> op;
vector<int> num;

int cal(int a, int b, char op) {
  if(op == '*') {
    return a * b;
  }
  if(op == '+') {
    return a + b;
  }
  if(op == '-') {
    return a - b;
  }
}

// idx는 문자열에서 현재 위치. cur은 현재까지의 값
void dfs(int idx, int sum) {
  // 1. 종료(기저) 조건
  if(idx == num.size()-1) {
    ret = max(ret, sum);
    return;
  }
  
  // 괄호로묶는다: 이전 값 + 괄호 계산
  // num[idx], op[idx],num[idx+1] op[idx+1] num[idx+2]
  if(idx + 2 < num.size()) {
    int _sum = cal(num[idx+1], num[idx+2], op[idx+1]);
    dfs(idx+2, cal(sum, _sum, op[idx]));
  }

  // 괄호로 묶지 않는다: 계산
  // (sum) sum = num[idx] op[idx] num[idx+1]
  // (next idx) = idx+2
  dfs(idx+1, cal(sum, num[idx+1], op[idx]));
  
  return;
}

int main() {
  cin >> n;
  cin >> s;

  // 숫자와 연산자 분리
  for(int i = 0; i < n; i++) {
    if(i%2 == 0) num.push_back(s[i] - '0');
    else op.push_back(s[i]);
  }

  dfs(0, num[0]);

  cout << ret << "\n";
  return 0;
}