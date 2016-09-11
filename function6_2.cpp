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
	for (decltype(ret) i=0; i != s.size(); ++i)	//��Ҫ�±��ֵ�����õ�����.
	{
		if ( *(sc+i)== c){			//��c����ַ���Ҳ����.
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
	return (find_char(s, '.', cnt) == s.size() - 1) && cnt == 1;//��ϵ��������ȼ�С�����������
}
void print_a(const int a[])
{
	printf("%d",a[0]);	//��ͬ��const int *.
}
void print(const char *cp)
{
	if (cp)
	while (*cp)
		cout << *cp++;
}
void print(const int *beg, const int *end)	//����������Ԫ��ָ���β��Ԫ��ָ��.
{
	while (beg != end)
		cout << *beg++ << endl;
}
void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; i++)
		cout << ia[i] << endl;
}
void print(const int matrix[][10], int rowSize)	//�൱��const int (*matrix)[10]��һ��ָ��ʮ������Ԫ�������ָ�룬�����Ҫ˵���ڶ�ά��.
{
	return; 
}
//initializer_list�β�
void error_msg(initializer_list<string> ls)
{
	for (const auto &elem : ls)
		cout << elem << " ";
	cout << endl;
}
const string &ret()	//��������Ǵ���ģ���ͼ���ؾֲ����������û��ַ.!!!���԰Ѻ�������ֵд���������һ��ҪС�ģ�����
{
	const string ret = "hello world";	//�ں������ڲ�����ı������ں�����˵�Ǿֲ�������������ββ���.
	return ret;
}
int function_main(int argc,char *argv[])	//int main(int argc,char **argv)Ҳ���ԣ�ָ���������ָ��ָ���ָ��.
{
	size_t cnt;
	auto index = find_char("what's your name", 'a', cnt);
	cout << index << "\n";
	cout << cnt << endl;
	//�����β�
	int i = 0, j[2] = { 0, 1 };
	print_a(&i);	//��i��ַָ�봫��ȥʱû�г����������������Ϊprintf:a[1]������������Ϊ���ָ��ֻ��a[0]��λ���ж���ֵ0.
	print_a(j);
	///
	const string s1 = "expected";
	const string s2 = "actual";
	///
	initializer_list<string> il{ "ab", "cd" };
	initializer_list<string> il2(il);
	error_msg({"function",s1,s2});//ע�⣬Ҫ�ô�����������.
	error_msg({ "hello", "world", "smell" });	//�βθ����ǿɱ��.
	cout << "\n" << ret() << endl;
	return 0;
}  