#include<iostream>
#include<cstring>
#include<cstddef>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int dmain(void){
	int a[] = { 0, 1, 2 };
	int a1[3] = { 0, 1 };//剩余一个默认初始化为0；
	char a2[8] = "hello";
	const char a3[] = "hello world";
	unsigned scores[11] = { 0 };
	unsigned grade;
	//数组与指针
	string nums[] = { "one", "two", "three" };
	char *nums2[] = { "one", "two", "three" };
	string *p = &nums[0];
	//or 
	p = nums;
	int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto ia2(ia);//相当于auto ia2(&ia[0]);
	//不能用整形指针给数组赋值。
	int *pl = &ia[10], *b = ia;
	for (; b != pl; ++b)
		cout << *b << endl;
	return 0;
}