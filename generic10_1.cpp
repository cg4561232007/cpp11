#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<iterator>
#include<numeric>
#include<algorithm>
using namespace std;	//begin,end,copy�ȷ��ͺ������Ƕ���Ϊstd���.
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique=unique(words.begin(), words.end());
	//��׼�ⲻ�������������в���
	words.erase(end_unique,words.end());
	for (const string &s : words)
		cout << s << "";
	cout << endl;
	//����׾�ư�...
}
int generic10_1main(void)
{
	//���ڲ�ͬ���͵�Ԫ�غͶ����������ͣ�һ�㴫���㷨�еĲ����ǵ������������������ָ��
	vector<int> vect{ 1, 2, 3, 4, 5, 42, 56 };
	int val = 42;
	auto result = find(vect.cbegin(),vect.cend(),val);
	cout << "The value " << val << "is "
		<< (result == vect.cend() ? "not present": "present")<<endl;
	int sum = accumulate(vect.cbegin(), vect.cend(), 0);
	//���������κ����͵�Ԫ��
	vector<string> v{"jiji","jojo","huo"};
	//string sum_str = accumulate(v.cbegin(), v.cend(), "");	//�������ִ�����Ϊ""�ǳ����ַ���const char*,�൱���ַ�������ֵ��
														//�������Ͳ�����const char*,����const char*��û�ж���+����.
	//Ӧ�ø�Ϊ������string()������������ַ�����������һ��string����Ҳ������Ϊ������һǿ������ת����
	string sum_str = accumulate(v.cbegin(), v.cend(), string(""));
	vector<string> roster{ "asdasd", "sss", "ffff" };
	bool is_equal = equal(v.cbegin(),v.cend(),roster.cbegin()+1);
	//fill_n
	vector<int> myvec;
	//fill_n(myvec.begin(), 10, 0);//����myvec����Ϊ�գ�myvecӦ�����ٰ���10��Ԫ��.
	fill_n(myvec.begin(), myvec.size(), 0);
	
	auto it = back_inserter(myvec);
	*it = 42;	//����42
	//һ������ʹ��,����һ�����������������fill_n��Ϊ��һ������������begin()
	fill_n(back_inserter(myvec), 10,0);
	int a1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);
	list<string> ilst = { "ad", "sdsd" };
	replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(roster), string(""), string("ffff"));	//�㲻��Ϊʲôconst char*����;
	ilst.sort();
	//sort(begin(il), end(il));  sortֻ�����������������.
	for (auto &lis : ilst)
		cout << lis << " ";
		cout << endl;
	return 0;
}