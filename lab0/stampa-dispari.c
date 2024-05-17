#include <stdio.h>

int main()
{
  int n1 = 21, n2 = 47;
  for (int i = n1 + 1; i < n2; i++)
  {
    if (i % 2 == 1)
      printf("%d\n", i);
  }
}
