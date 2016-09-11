#include<cstdio>
#include<string>
using std::string;
//函数声明
string lookup(string);
string lookup(const string);	//这两个函数其实是一样的
string lookup(string *);
string lookup(string* const);	//这两个函数其实是一样的

//常量引用或指针可以区分
string lookup(string &);
string lookup(const string &);	//这两个函数不一样
string lookup(string *);
string lookup(const string *);	//这两个函数不一样

//这里终于把指针与指向数组的指针搞清楚了.
//三种办法:typedef 关键字,using 关键字,decltype 关键字.
typedef int (*int_array)[4];//指向整型元素数组的指针与指向整形变量的指针不同
using int_array = int(*)[4];//using 指令使这样使用的，int (*)[4]四个整型组成的数组，int *[4]四个整型指针数组
int(*func(int i))[4]	//相当于 int _array func(int i)	,	int	(&func(int i))[4]则是返回一个对数组的引用.
{
	int a[4];
	int(*p2)[4] = &a;	//这里必须要对数组a进行取地址运算，因为int *与int(*)[4]是不同的类型.
	return p2;
}
auto func1(int i) ->int(*)[4]	//尾置返回类型
{
	int a[4]={ 0 };
	return &a;		//错误，返回了临时变量的地址
}
int main(void)
{
	int ia[3][4] = { { 1 }, { 2 }, { 3 } };
	for (int_array p = ia; p != ia + 3;++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
			printf("%d", *q);
		printf("\n"); 
	}
	return 0;	
}