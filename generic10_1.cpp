#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<iterator>
#include<numeric>
#include<algorithm>
using namespace std;	//begin,end,copy等泛型函数都是定义为std里的.
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique=unique(words.begin(), words.end());
	//标准库不会对容器本身进行操作
	words.erase(end_unique,words.end());
	for (const string &s : words)
		cout << s << "";
	cout << endl;
	//打字拙计啊...
}
int generic10_1main(void)
{
	//用于不同类型的元素和多种容器类型，一般传入算法中的参数是迭代器或者内置数组的指针
	vector<int> vect{ 1, 2, 3, 4, 5, 42, 56 };
	int val = 42;
	auto result = find(vect.cbegin(),vect.cend(),val);
	cout << "The value " << val << "is "
		<< (result == vect.cend() ? "not present": "present")<<endl;
	int sum = accumulate(vect.cbegin(), vect.cend(), 0);
	//可以增加任何类型的元素
	vector<string> v{"jiji","jojo","huo"};
	//string sum_str = accumulate(v.cbegin(), v.cend(), "");	//编译会出现错误，因为""是常量字符串const char*,相当于字符串字面值。
														//返回类型不能是const char*,并且const char*上没有定义+运算.
	//应该改为：利用string()构造器传入空字符串参数构造一个string对象，也可以认为是做了一强制类型转换？
	string sum_str = accumulate(v.cbegin(), v.cend(), string(""));
	vector<string> roster{ "asdasd", "sss", "ffff" };
	bool is_equal = equal(v.cbegin(),v.cend(),roster.cbegin()+1);
	//fill_n
	vector<int> myvec;
	//fill_n(myvec.begin(), 10, 0);//错误，myvec现在为空！myvec应该至少包含10个元素.
	fill_n(myvec.begin(), myvec.size(), 0);
	
	auto it = back_inserter(myvec);
	*it = 42;	//插入42
	//一般这样使用,返回一个插入迭代器，送入fill_n作为第一个参数而不是begin()
	fill_n(back_inserter(myvec), 10,0);
	int a1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);
	list<string> ilst = { "ad", "sdsd" };
	replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(roster), string(""), string("ffff"));	//搞不懂为什么const char*不行;
	ilst.sort();
	//sort(begin(il), end(il));  sort只能用于随机迭代器上.
	for (auto &lis : ilst)
		cout << lis << " ";
		cout << endl;
	return 0;
}