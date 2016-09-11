#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
class No_default{
public:
	No_default() = default;
	No_default(const string &s) : st(s){}
	string st;

};
int construct_main(void)
{
	vector<No_default> vec{No_default("smell")};
	//vector<No_default> vec (10);	//输出了十个空串
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
		cout << iter->st << std::endl;
	return 0;
}