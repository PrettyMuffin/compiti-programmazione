#include <stdio.h>

#define SOGLIA 63

int main()
{
  int n = SOGLIA + 1;
  while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
  {
    n += 1;
  } // while
  printf("%d", n);
}
