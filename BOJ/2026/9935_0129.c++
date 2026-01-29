#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

/**
 * 2중 for문으로 구현하게 되면 (1,000,000 * 1,000,000 => 1조)
 * 
 * 부분문자열의 끝 두자리 문자를 비교하는 방식으로
 */
string input, target, ret;

int main() {
  cin >> input >> target;

  int targetSize = target.size();
  bool flag = true;

  for(char c:input) {
    ret += c;
    if(ret.size() >= targetSize && ret.substr(ret.size()-targetSize, targetSize) == target) {
      ret.erase(ret.size()-targetSize, targetSize);
    }
  }
  if(!ret.size()) cout << "FRULA" << "\n";
  else cout << ret << "\n";
  
  return 0;
}
