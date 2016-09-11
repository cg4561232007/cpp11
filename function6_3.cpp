#include<iostream>
#include<vector>
#include<string>
#include<cassert>
#include<initializer_list>
using namespace std;
using std::vector;
vector<string> process(initializer_list<string> ls)
{
	auto ip = ls.begin();
	if (!ls.size())
		return{};
	else if (*ip == *(ip + 2))
		return{ "functionX", "okay" };
	else
		return{ "functionX", "expected", "actual" };
}
//函数匹配
void f(int);
//void f(double, double a= 3.14);
void f(int, int);

int function6_3main(void)
{
	initializer_list<string> ls{ "and", "or", "","and", "name" };
	vector<string> s1(process(ls));	//验证下对不对
	assert(s1.size()>3);	//确保s1.size()大于3,否则报错.
	//#ifndef NODBUG
	//cerr << __func__ << __FILE__ << endl;	//func代表此时的函数名，file代表此时的文件名.
	//#endif
	for (auto iter = s1.begin(); iter != s1.end()&&!iter->empty(); ++iter)	//不能在vector迭代器里面使用范围for循环，任何试图改变迭代器大小的操作都会使迭代器失效.
		cout << *iter << endl;
	//f(3.14);	//调用第二个函数得到最优的精确匹配.
	//f(42, 2.56); 对第一个形参来说3好，对第二个形参来说2好，因此发生二义性匹配.
	return 0;
}