#pragma once
#ifndef SALES_DATE_H
#define SALES_DATE_H	//�����趨Ϊ�Զ���
#include<string>
using std::string;
struct Sales_date{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn();
};
const unsigned sale_id = 000001;
//ͷ�ļ��л���������������
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);
#endif