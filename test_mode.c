#include <stdio.h>
#include <assert.h>

int min(int a[], int n) {
  int min = a[0];
  for(int i = 1; i < n; i++) {
    if(min > a[i]) min = a[i];
  }
  return min;
}

int max(int a[], int n) {
  int max = a[0];
  for(int i = 1; i < n; i++) {
    if(max < a[i]) max = a[i];
  }
  return max;
}

int mode(int a[], int n) {
  int min = min(a, n);
  int max = max(a, n);
  int count[max-min+1];
  for(int i = 0; i < max-min; i++) {
    count[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    count[a[i]-min]++;
  }
  return max(count, max-min+1)+min;
}

int main(void) {
  int x[] = {4, 9,5,6,5,10,0,2,-3, -3,4, 4};
  assert ((mode(x, 12) == 4));

  int y[] = {5};
  assert (mode(y, 1) == 5);
  printf("Mode: passed\n");
  }
