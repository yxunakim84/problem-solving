#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
  /* 입출력 */
  string a, b, c;
  cin >> a >> b >> c;
  cout << a << ' ' << b << ' ' << c << endl;


  
  /* split */
  string str1 = "This is Test";
  istringstream ss1(str1);
  string buffer;
  vector<string> ret;

  while(getline(ss1, buffer, ' ')) {
    ret.push_back(buffer);
    // string 타입은 c++, printf는 c라서 맞지 않음. 따라서 c로 쓸거면 c_str() 처리
    // printf("%s", buffer.c_str());
  }
  for(int i = 0; i < ret.size(); i++) {
    cout << ret[i] << endl;
    // printf("%s", ret[i].c_str());
  }




  
  return 0;
}


/* vector */
pair<int, int> p;
// p.first, p.second
vector<pair<int, int>> v;
/* queue */
queue <pair<int, int>> q;
// q.front().first;
// q.front().second;


#include <vector>
using namespace std;

vector<int> solution(const vector<vector<int> >& v) {
    int ans_x = 0;
    int ans_y = 0;

    // 중복되는 값은 XOR로 상쇄됨: a^a = 0, 0^b = b
    for (int i = 0; i < (int)v.size(); i++) {
        ans_x ^= v[i][0];
        ans_y ^= v[i][1];
    }
    vector<int> ans;
    ans.push_back(ans_x);
    ans.push_back(ans_y);
    return ans;
}




/*
c++ 입력
string a, b, c;
cin >> a >> b >> c;

char a[100], b[100], c[100];
scanf("%s %s %s", a, b, c);
*/