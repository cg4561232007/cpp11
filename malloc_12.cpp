#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;
int malloc_12main(void)
{
	shared_ptr<int> sp=make_shared<int>(43);
	shared_ptr<int> sg(new int(1024));
	return 0;
}