#include<iostream>
#include<vector>
#include<string>
using namespace std;
//��������
void f(int);
void f(double, double a = 3.14);
void f(int, int);
//����ָ���β�
void useBigger(const string&, const string&, void (*p)(string&,string&));	//�������β���ָ������ָ��.
//Ҳ��ʹ��typedef����
typedef void(*func)(const string &, const string&);
using func = void(*)(const string&, const string&);
void useBigger(const string&, const string&,func);
void f(double a, double b )
{
	a = 3.1;
}
//ֱ������ָ������һ��ָ��
int (*fool(int))(int *, int);
int function_ptmain(void)
{
	//����ָ��
	void(*pf)(double, double) = f;	//�������������һ������ָ��!�����������൱�ڰ�f�ֽ���pf.
	pf(3.3, 4.4);	//�൱�ڵ�����f(4.4).
	return 0;
}
