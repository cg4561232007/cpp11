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
//����ƥ��
void f(int);
//void f(double, double a= 3.14);
void f(int, int);

int function6_3main(void)
{
	initializer_list<string> ls{ "and", "or", "","and", "name" };
	vector<string> s1(process(ls));	//��֤�¶Բ���
	assert(s1.size()>3);	//ȷ��s1.size()����3,���򱨴�.
	//#ifndef NODBUG
	//cerr << __func__ << __FILE__ << endl;	//func�����ʱ�ĺ�������file�����ʱ���ļ���.
	//#endif
	for (auto iter = s1.begin(); iter != s1.end()&&!iter->empty(); ++iter)	//������vector����������ʹ�÷�Χforѭ�����κ���ͼ�ı��������С�Ĳ�������ʹ������ʧЧ.
		cout << *iter << endl;
	//f(3.14);	//���õڶ��������õ����ŵľ�ȷƥ��.
	//f(42, 2.56); �Ե�һ���β���˵3�ã��Եڶ����β���˵2�ã���˷���������ƥ��.
	return 0;
}