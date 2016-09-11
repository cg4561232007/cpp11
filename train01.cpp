#include<iostream>
using namespace std;
int smain()
{
	cout << "hello world!" << endl;
	int i = 42, *p=nullptr;
	int *&r = p;	//int *&r=p; r是一个对指针的引用，从右向左读了解其的定义类型.
	r = &i;
	*r = 0;
	cout << i << endl;
	return 0;
}