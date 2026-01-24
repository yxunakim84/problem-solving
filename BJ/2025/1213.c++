#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int cnt[200], flag = 0;
char mid;
string s;
string ret;
int len;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  len = s.length();

  for(char a: s) cnt[a]++;

  for(int i = 'Z'; i >= 'A'; i--) {
    if(cnt[i] & 1) {
      mid = char(i); flag++;
      cnt[i]--;
    }
    if(flag == 2) break;
    for(int j = 0; j < cnt[i]; j += 2) {
      ret = char(i) + ret;
      ret += char(i);
    }
  }

  if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
  
  
  if(flag == 2) cout << "I'm Sorry Hansoo" << "\n";
  else if((len & 1 && flag ==0) || (len & 0 && flag > 0)) cout << "I'm Sorry Hansoo" << "\n";
  else cout << ret << "\n";

  return 0;
}