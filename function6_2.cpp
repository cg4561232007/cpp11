#include<iostream>
#include<string>
#include<initializer_list>
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;
using std::string;
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	const char *sc = s.c_str();
	for (decltype(ret) i=0; i != s.size(); ++i)	//需要下标的值，不用迭代器.
	{
		if ( *(sc+i)== c){			//用c风格字符串也可以.
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}
bool is_sentencr(const string &s)
{
	string::size_type cnt = 0;
	return (find_char(s, '.', cnt) == s.size() - 1) && cnt == 1;//关系运算符优先级小于算数运算符
}
void print_a(const int a[])
{
	printf("%d",a[0]);	//等同于const int *.
}
void print(const char *cp)
{
	if (cp)
	while (*cp)
		cout << *cp++;
}
void print(const int *beg, const int *end)	//传入数组首元素指针和尾后元素指针.
{
	while (beg != end)
		cout << *beg++ << endl;
}
void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; i++)
		cout << ia[i] << endl;
}
void print(const int matrix[][10], int rowSize)	//相当于const int (*matrix)[10]，一个指向十个整形元素数组的指针，因此需要说明第二维度.
{
	return; 
}
//initializer_list形参
void error_msg(initializer_list<string> ls)
{
	for (const auto &elem : ls)
		cout << elem << " ";
	cout << endl;
}
const string &ret()	//这个函数是错误的，试图返回局部变量的引用或地址.!!!所以把函数返回值写成这个样子一定要小心！！！
{
	const string ret = "hello world";	//在函数体内部定义的变量对于函数来说是局部变量，传入的形参不是.
	return ret;
}
int function_main(int argc,char *argv[])	//int main(int argc,char **argv)也可以，指针数组就是指向指针的指针.
{
	size_t cnt;
	auto index = find_char("what's your name", 'a', cnt);
	cout << index << "\n";
	cout << cnt << endl;
	//数组形参
	int i = 0, j[2] = { 0, 1 };
	print_a(&i);	//将i地址指针传进去时没有出错，但是如果函数改为printf:a[1]，则会溢出，因为这个指针只在a[0]的位置有定义值0.
	print_a(j);
	///
	const string s1 = "expected";
	const string s2 = "actual";
	///
	initializer_list<string> il{ "ab", "cd" };
	initializer_list<string> il2(il);
	error_msg({"function",s1,s2});//注意，要用大括号括起来.
	error_msg({ "hello", "world", "smell" });	//形参个数是可变的.
	cout << "\n" << ret() << endl;
	return 0;
}  