#include <cstdio>
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

int n;
// string을 만들어야되므로 int가 아닌 char로 취급
char arr[101][101];
string s;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

string quard(int y, int x, int size) {
  // ch 타입을 string 타입으로 만들어 주는 부분 string(1, arr[y][x])
  if(size == 1) {return string(1, arr[y][x]);}
   
  // 시작지점
  char b = arr[y][x];
  string ret = "";

  for(int i = y; i < y+size; i++) {
    for(int j = x; j < x+size; j++) {
      // 해당 영역에서 다른 문자 등장
      if(arr[i][j] != b) {
        // 그럼 다시 재귀 돌려야 함.
        ret += '(';
        ret += quard(y, x, size/2);
        ret += quard(y, x + size/2, size/2);
        ret += quard(y+size/2, x, size/2);
        ret += quard(y+size/2, x+size/2, size/2);
        ret += ')';
        return ret;
      }
    }
  }
  return string(1, arr[y][x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      arr[i][j] = s[j];
    }
  }

  
  return 0;
}