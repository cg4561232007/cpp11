#include<iostream>
using namespace std;
int smain()
{
	cout << "hello world!" << endl;
	int i = 42, *p=nullptr;
	int *&r = p;	//int *&r=p; r��һ����ָ������ã�����������˽���Ķ�������.
	r = &i;
	*r = 0;
	cout << i << endl;
	return 0;
}