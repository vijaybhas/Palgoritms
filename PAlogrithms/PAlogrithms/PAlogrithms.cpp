#include <stdio.h>
#include<iostream>
using namespace std;

struct CS {
	int x;

	CS() {
		x = 100;
		cout << "==== CS constr" << endl;
	}
};

CS& fun(CS c) {
	
	c.x = 1;

	return c;
}

void fun2(CS& x) {

	cout << x.x << endl;

}

int main()
{
  cout << "hi";
  CS c;
  fun2(fun(c));
  return 0;
}

