#include <stdio.h>
int n, s;
int arr[10000];
int main() {
  scanf("%d %d", &n, &s);
  for(int i=0; i<n; i++) {
    scanf("%d", arr + i);
  }
  int l = 0, r = 1;
  int rst = 10001;
  int sum = arr[l];

  while(1) {

    if(sum >= s) {
      int len = r - l;
      if(len < rst) rst = len;
      l += 1;
      r = l + 1;
      sum = arr[l];
    }
    else if(r == n) break;
    else {
      sum += arr[r++];
    }
  }
  if(rst > 10000) rst = 0;

  printf("%d", rst);
}