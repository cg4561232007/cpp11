#include<cstdio>
#include<string>
using std::string;
//��������
string lookup(string);
string lookup(const string);	//������������ʵ��һ����
string lookup(string *);
string lookup(string* const);	//������������ʵ��һ����

//�������û�ָ���������
string lookup(string &);
string lookup(const string &);	//������������һ��
string lookup(string *);
string lookup(const string *);	//������������һ��

//�������ڰ�ָ����ָ�������ָ��������.
//���ְ취:typedef �ؼ���,using �ؼ���,decltype �ؼ���.
typedef int (*int_array)[4];//ָ������Ԫ�������ָ����ָ�����α�����ָ�벻ͬ
using int_array = int(*)[4];//using ָ��ʹ����ʹ�õģ�int (*)[4]�ĸ�������ɵ����飬int *[4]�ĸ�����ָ������
int(*func(int i))[4]	//�൱�� int _array func(int i)	,	int	(&func(int i))[4]���Ƿ���һ�������������.
{
	int a[4];
	int(*p2)[4] = &a;	//�������Ҫ������a����ȡ��ַ���㣬��Ϊint *��int(*)[4]�ǲ�ͬ������.
	return p2;
}
auto func1(int i) ->int(*)[4]	//β�÷�������
{
	int a[4]={ 0 };
	return &a;		//���󣬷�������ʱ�����ĵ�ַ
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