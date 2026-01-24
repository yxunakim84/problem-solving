#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<string> v;

int main() {
  cin >> N;

  int ret = 0;

  for(int i = 0; i < N; i++) {
    string input;
    cin >> input;

    stack<char> stk;
    for(int j  = 0; j < input.length(); j++) {
      if(stk.size() && (stk.top() == input[j])) {
        stk.pop();
      } else {
        stk.push(input[j]);
      }
    }
    if(stk.size() == 0) ret++;
    
  }

  cout << ret << "\n";

  return 0;
}



/*
int main() {
  cin >> N;

  for(int i = 0; i < N; i++) {
    string input;
    cin >> input;
    v.push_back(input);
  }

  int answer = 0;

  for(int i = 0; i < v.size(); i++) {
    // 홀수 len 이면 x
    string _input = v[i];
    int _input_len = _input.length();
    bool red_flag = false;

    if(_input_len % 2 == 1) {
      continue;
    }
    // 짝수
    // i/i+1 혹은 i/len-(i+1)
    for(int j = 0; j < _input_len;) {
      // i/i+1
      if(_input[j] == _input[j+1]) {
        j+=2;
      } else if(_input[j] == _input[_input_len-(j+1)]) {
        j++;
      } else {
        red_flag = true;
        break;
      }
    }
    if(!red_flag) answer++;
  }

  cout << answer << "\n";

  return 0;
}*/
