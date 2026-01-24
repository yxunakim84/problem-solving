#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

string s;

vector<string> split(const string& input, string delimiter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimiter);
  while(end != string::npos) {
    string token = input.substr(start, end-start);
    if(!token.empty()) result.push_back(token);
    start = end + delimiter.size();
    end = input.find(delimiter, start);
  }
  string token = input.substr(start);
  if(!token.empty()) result.push_back(token);
  return result;
}

int main() {
  
  getline(cin, s);

  cout << split(s, " ").size() << "\n";

  return 0;
}