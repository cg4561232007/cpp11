#pragma once
#ifndef SALES_DATE_H
#define SALES_DATE_H	//将其设定为以定义
#include<string>
using std::string;
struct Sales_date{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn();
};
const unsigned sale_id = 000001;
//头文件中还包括函数的声明
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);
#endif