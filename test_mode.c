#include <stdio.h>
#include <assert.h>

int min(int a[], int n) {
  int MIN = a[0];
  for(int i = 1; i < n; i++) {
    if(MIN > a[i]) MIN = a[i];
  }
  return MIN;
}

int max(int a[], int n) {
  int MAX = a[0];
  for(int i = 1; i < n; i++) {
    if(MAX < a[i]) MAX = a[i];
  }
  return MAX;
}

int mode(int a[], int n) {
  int MIN = min(a, n);
  int MAX = max(a, n);
  int l = MAX-MIN+1;
  int count[l];
  for(int i = 0; i < l; i++) {
    count[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    count[a[i]-MIN]++;
  }
  int pos = 0, temp = count[0];
  for (int i = 1; i < l; i++) {
    if(count[i] > temp) {
      temp = count[i];
      pos = i;
    }
  }
  return pos+MIN;
}

int main(void) {
  int x[] = {4, 9,5,6,5,10,0,2,-3, -3,4, 4};
  assert ((mode(x, 12) == 4));

  int y[] = {5};
  assert (mode(y, 1) == 5);
  printf("Mode: passed\n");
  }
