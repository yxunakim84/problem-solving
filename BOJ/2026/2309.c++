#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<int> arr;
#define TOTAL_DWARFS 9
#define TARGET_DWARFS 7

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int height_sum = 0;
  
  for(int i  = 0; i < TOTAL_DWARFS; i++) {
    int height;
    cin >> height;
    height_sum += height;
    // 난쟁이들 키를 저장
    arr.push_back(height);
  }

  // 난쟁이들 키를 정렬
  sort(arr.begin(), arr.end());

  int not_target_i, not_target_j;
  bool found = false;
  for(int i = 0; i < arr.size()-1 && !found; i++) {
    for(int j = 1; j < arr.size(); j++) {
      if((height_sum - (arr[i] + arr[j])) == 100) {
        not_target_i = arr[i];
        not_target_j = arr[j];
        found = true;
        break;
      }
    }
  }

  for(int height : arr) {
    if(height == not_target_i || height == not_target_j) {
      continue;
    }
    cout << height << "\n";
  }
 
  return 0;
}
*/


// 2. 재귀함수 combi 구현 풀이

#define TOTAL_DWARFS 9
#define TARGET_DWARFS 7

vector<int> total_dwarfs;
vector<int> arr;

void print(vector<int> &arr) {
  for(int val : arr) {
    cout << val << "\n";
  }
  return;
}

void combi(int start, int sum) {
  // 기저 조건
  if(arr.size() == TARGET_DWARFS) {
    //합도 100이면 ok, 아예 종료
    if(sum == 100) {
      print(arr);
      exit(0);
    }
    //합이 100이 아니면 다시 리턴, 백트래킹
    return;
  }
  for(int i = start+1; i < TOTAL_DWARFS; i++) {
    arr.push_back(total_dwarfs[i]);
    combi(i, sum + total_dwarfs[i]);
    arr.pop_back();
  }
}


int main() {
  vector<int> arr;
  int sum = 0;
  
  for(int i = 0; i < TOTAL_DWARFS; i++) {
    int height;
    cin >> height;
    total_dwarfs.push_back(height);
  }

  sort(total_dwarfs.begin(), total_dwarfs.end());
  
  combi(-1, sum);


  return 0;
}