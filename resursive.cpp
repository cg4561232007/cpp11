#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define SOME_FAILURE 0
int factorial(int val)
{
	if (val>1)
		return factorial(val-1)*val; //����ʹ��v--�����ʹ��--v��õ�f(4)�Ľ��.
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