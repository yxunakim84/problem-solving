#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;


void printV(vector<int> &a) {
  for(int i = 0; i < 7; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int permutation() {

  // 1. vector
  vector<int> a = {20, 7, 23, 19, 10, 15, 25, 8, 13};

  // 2. list
  // int a[] = {1, 2, 3};

  sort(a.begin(), a.end());

  do{
    //5개 중에 2개만 순서 상관있이 뽑는다.
    printV(a);
  }while(next_permutation(a.begin(), a.end()));

  a.clear();

  
  return 0;
}

// 재귀(Dfs)로 푸는 순열

int total = 3;
int target = 2;
int arr[] = {1, 2, 3};
bool visited[3];
vector<int> selected;

void dfs(int curr_depth) {

  // 기저 조건
  if(curr_depth == target) {
    for(int val : selected) {
      cout << val << " ";
    }
    cout << "\n";
  }

  // arr에 들어있는 숫자들에서 숫자를 뽑아서 selected에 넣어준다.
  // 그러면 arr를 순회해야겠지?
  for(int i = 0; i < total; i++) {
    // selected = [1] 인 상태에서 반복문 다시 진입하게 되면,
    // 1을 다시 넣어주면 안됨.
    if(visited[i]) continue; // 이때는 넘어가. 그럼 i가 2일때로 반복문 다시 돌게 됨.

    selected.push_back(arr[i]);
    visited[i] = true;

    dfs(curr_depth + 1);

    selected.pop_back();
    visited[i] = false;
  }
}

int main() {
  dfs(0);
  return 0;
}