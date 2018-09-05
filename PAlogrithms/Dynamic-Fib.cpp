#include <iostream>
#include<stream>

unsigned long Fib[100];

void init()
{
  memset(fib, 0, sizeof(fib));
}

unsigned long fib(int n)
{
  if( Fib[n] != 0)
    return Fib[n];

  return Fib[n-1] + Fib[n-2];
}

int main()
{
  cout << fib(20);
  gtch();
  
  
  return 0;
}
