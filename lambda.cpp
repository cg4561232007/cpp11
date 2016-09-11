#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//传入一元谓词lambda表达式最简单的形式.
bool cmp(const string &s1, const string &s2)
{
	return s1.size() > s2.size();
}
string  make_plural(size_t cnt, const string& word, const string &ending)
{
	return (cnt==1)?word:word+ending;	//在这里不能返回对其的引用，因为word+ending是局部变量，在函数体内对传入的参数进行了修改并返回其拷贝是合理的.
}
int lambda_main(void)
{
	////按照长度由大到小排序.
	vector<string> ivec{ "aa", "bbb", "vvv" };
	stable_sort(ivec.begin(), ivec.end(),cmp);
	for (auto &str : ivec)
		cout << str << endl;
	////
	//a simple lambda expression
	//可以向算法传递任何类别的可调用表达式
	vector<string> words{ "aa", "bbb", "vvv","smell","2007","your" };
	unsigned sz = 4;
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a){return a.size() >=sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	//for_each算法
	for_each(wc, words.end(),
		[](const string &s){cout << s << " "; });
	cout << endl;

	return 0;
}