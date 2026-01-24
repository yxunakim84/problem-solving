#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10];
vector<int> v;
pair<int, int> ret;

int main() {
  int sum = 0;
  for(int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }


  sort(arr, arr+9);
  
  bool found = false;
  int target_i, target_j;
  for(int i = 0; i < 8 && !found; i++) {
    for(int j = i+1; j < 9; j++) {
      if(sum - (arr[i] + arr[j]) == 100) {
        target_i = i;
        target_j = j;
        // ret = {i, j};
        found = true;
        break;
      }
    }
  }
  
  for(int i = 0; i < 9; i++) {
    if(i == target_i || i == target_j) continue;
    // if(i == ret.first == i || ret.second == i) continue;
    printf("%d ", arr[i]);
  }
  
  return 0;

}

  /*
  permutation

  do {
    for(int i : arr) {
      cout << i << " ";
    }
    cout << '\n';

    int sum = 0;
    for(int i = 0; i < 7; i++) {
      sum += arr[i];
      if(sum == 100) break;
    }
    
  } while(next_permutation(arr, arr+9));

  for(int i = 0; i < 7; i++) {
    cout << arr[i] << "\n";
  }
  */