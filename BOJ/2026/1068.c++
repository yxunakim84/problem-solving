/*
- 루트 노드가 항상 0이 아님
- 노드 삭제 시 부모 노드가 리프 노드가 되는 경우 고려
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50];
int N, deleteNode, rootNode, leafNodeCnt=0;

void dfs(int node) {
  // if(node == deleteNode) {
  //   // 종료, 더이상 dfs 탐색 x
  //   return;
  // }
  if(!tree[node].size()) { // leafNode
    leafNodeCnt++;
    return;
  }
  
  int validChildCnt = 0; // 삭제 이후에 남은 자식
  for(int i = 0; i < tree[node].size(); i++) {
    int childNode = tree[node][i];
    if(childNode != deleteNode) {
      dfs(childNode);
      validChildCnt++;
    }
  }
  if(validChildCnt == 0) {
    leafNodeCnt++;
  }
  return;
}

int main() {
  cin >> N; 

  for(int i = 0; i < N; i++) {
    int ParentNodeIndex;
    cin >> ParentNodeIndex;
    if(ParentNodeIndex == -1) rootNode = i;
    else tree[ParentNodeIndex].push_back(i);
    // tree[0] = 1, 2
    // tree[2] = 3, 4
    // tree[4] = 5, 6
    // tree[6] = 7, 8
    // 자식이 있는 것들만 값이 존재
  }

  cin >> deleteNode;

  if (deleteNode != rootNode) {
    dfs(rootNode); // rootNodeIndex가 0이 아닐 수도 있음
  }

  cout << leafNodeCnt << "\n";

  return 0;
}

/**
12
-1 0 0 1 1 2 2 3 6 8 8 10
8
 */