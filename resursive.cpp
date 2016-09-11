#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define SOME_FAILURE 0
int factorial(int val)
{
	if (val>1)
		return factorial(val-1)*val; //这里使用v--会出错，使用--v会得到f(4)的结果.
	else
		return 1;
}
int resmain(void)
{
	cout << factorial(5) << endl;
	if (SOME_FAILURE)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}