#include<iostream>
#include<vector>
#include<string>
using namespace std;
//函数声明
void f(int);
void f(double, double a = 3.14);
void f(int, int);
//函数指针形参
void useBigger(const string&, const string&, void (*p)(string&,string&));	//第三个形参是指向函数的指针.
//也可使用typedef来简化
typedef void(*func)(const string &, const string&);
using func = void(*)(const string&, const string&);
void useBigger(const string&, const string&,func);
void f(double a, double b )
{
	a = 3.1;
}
//直接声明指向函数的一个指针
int (*fool(int))(int *, int);
int function_ptmain(void)
{
	//函数指针
	void(*pf)(double, double) = f;	//函数名本身就是一个函数指针!所以字面上相当于把f又叫了pf.
	pf(3.3, 4.4);	//相当于调用了f(4.4).
	return 0;
}
