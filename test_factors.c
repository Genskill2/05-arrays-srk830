#include <stdio.h>
#include <assert.h>


int factors(int n, int a[]) {
  int k = 0;
  while (n % 2 == 0) {
    a[k] = 2; k++;
    n = n/2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      a[k] = i; k++;
      n = n/i;
    }
  }
  if (n > 2)
    a[k] = n;
  return k+1;
}

int main(void) {
  int ret[100] = {0};
  int count = factors(180, ret);
  assert (count == 5);
  assert (ret[0] == 2);
  assert (ret[1] == 2);
  assert (ret[2] == 3);
  assert (ret[3] == 3);
  assert (ret[4] == 5);


  count = factors(143, ret);
  assert (count == 2);
  assert (ret[0] == 11);
  assert (ret[1] == 13);
  printf("Factors: passed\n");
}
