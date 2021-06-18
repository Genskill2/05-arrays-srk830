/* Enter your solutions in this file */
#include <stdio.h>

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

float average(int a[], int n) {
  float avg = a[0];
  for(int i = 1; i < n; i++) {
    avg += a[i];
  }
  return avg/n;
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
