#include <stdio.h>
#include <assert.h>


float average(int a[], int n) {
  float avg = a[0];
  for(int i = 1; i < n; i++) {
    avg += a[i];
  }
  return avg/n;
}

int main(void) {
  int x[] = {9,5,6,10,2,-3,4};
  assert ((average(x, 7) - 4.7142) < 0.001);

  int y[] = {5};
  assert (average(y, 1) == 5.0);
  printf("Average: passed\n");
  }
