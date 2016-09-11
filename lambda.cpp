#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//����һԪν��lambda���ʽ��򵥵���ʽ.
bool cmp(const string &s1, const string &s2)
{
	return s1.size() > s2.size();
}
string  make_plural(size_t cnt, const string& word, const string &ending)
{
	return (cnt==1)?word:word+ending;	//�����ﲻ�ܷ��ض�������ã���Ϊword+ending�Ǿֲ��������ں������ڶԴ���Ĳ����������޸Ĳ������俽���Ǻ����.
}
int lambda_main(void)
{
	////���ճ����ɴ�С����.
	vector<string> ivec{ "aa", "bbb", "vvv" };
	stable_sort(ivec.begin(), ivec.end(),cmp);
	for (auto &str : ivec)
		cout << str << endl;
	////
	//a simple lambda expression
	//�������㷨�����κ����Ŀɵ��ñ��ʽ
	vector<string> words{ "aa", "bbb", "vvv","smell","2007","your" };
	unsigned sz = 4;
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a){return a.size() >=sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	//for_each�㷨
	for_each(wc, words.end(),
		[](const string &s){cout << s << " "; });
	cout << endl;

	return 0;
}