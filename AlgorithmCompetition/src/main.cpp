#include <math.h>
#include <stdio.h>
void test_1_1() { printf("%d\n", 8.0 / 0.0); }
void test_1_2() { printf("%.1f\n", 8.0 / 5); }
void test_1_3() { printf("%.8f\n", 1 + 2 * sqrt(3) / (5 - 1.0)); }

void test_1_4() {
  int a, b;
  printf("please input the adding numnbers: ");
  scanf("%d%d\n", &a, &b);
  printf("result: %d\n", a + b);
}

void test_1_8() {
  int a, b;  // swap two numbers
  scanf("%d%d\n", &a, &b);
  a = a + b;
  b = a - b;
  a = a - b;
  printf("a: %d, b: %d\n", a, b);
}

void test_1_11() {
  // n: number of chicken and rabbit, m: legs of chicken and rabbit
  int n, m, a, b;
  scanf("%d%d\n", &n, &m);
  a = (m - (2 * n)) / 2;
  b = n - a;
  if (m % 2 == 1 || a < 0 || b < 0)
    printf("No answers\n");
  else
    printf("%d,%d\n", a, b);
}

void test_1_12() {
  // sort the 3 numbers
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a >= b) {
    if (a >= c) {
      if (b >= c)
        printf("%d,%d,%d\n", c, b, a);
      else
        printf("%d,%d,%d\n", b, c, a);
    } else  // c> a > b,
      printf("%d,%d,%d\n", b, a, c);
  } else {  // a<b
    if (a > c)
      printf("%d,%d,%d\n", c, a, b);  // c<a<b
    else {
      if (a < c) {
        if (c > b)
          printf("%d,%d,%d\n", a, b, c);
        else
          printf("%d,%d,%d\n", a, c, b);
      }
    }
  }
}

void test_2_1() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) printf("%d\n", i);  // printf("%d\n", i)
  for (int i = 0; i < n; i++) printf("%d\n", i);
}

int main() {
  test_2_1();
  return 0;
}