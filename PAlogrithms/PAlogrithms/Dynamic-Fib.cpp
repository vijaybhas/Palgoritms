#include "stdafx.h"

#include <iostream>


using namespace std;

unsigned long Fib[100];

void init()
{
  memset(Fib, 0, sizeof(Fib));
}

unsigned long fib(int n)
{
  if( Fib[n] != 0)
    return Fib[n];

  return Fib[n-1] + Fib[n-2];
}

int run()
{
  init();
  cout << fib(20);
  
  return 0;
}
