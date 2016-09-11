#include<iostream>
#include<stack>
#include<string>
#include<vector>
using std::string;
using std::stack;
using std::vector;
using std::cout;
using std::endl;
int adapter9_5main(void)
{
	vector<string> vec1(10, "ioio");
	stack<string, vector<string>> stk(vec1);
	return 0;
}