#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
int c_str_main(void)
{
	char s1[] = "hello";
	char *s2 = "hello";
	cout << strcmp(s1, s2) << endl;
	cout << strcpy(s1, s2) << endl;	//s1������const char *����ʽ����Ϊ�����ַ����������ܸı��!!!
	return 0;

}