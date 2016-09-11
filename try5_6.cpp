#include<iostream>
#include<vector>
#include<stdexcept>
#include"Sales_data.h";
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::runtime_error;

int try_main(void)
{
	vector<string> svec(3,getstring());
	auto iter = svec.begin();
	while (iter != svec.end())
		++iter;

	Sales_date item1, item2;
	cin >> item1>>item2;
	if (item1.isbn() == item2.isbn){
		cout << item1 + item2 << endl;
		return 0;
	}
	else {
		std::cerr << "Date must refer to the same ISBN" << endl;
		return -1;
	}
	//�쳣����: try block
	if (item1.isbn() != item2.isbn)
		throw runtime_error("Date must refer to the same ISBN");
		cout << item1 + item2 << endl;
	//����������try catch block
		while (cin >> item1 >> item2){
			try{
				cout >> item1 + item2 >> endl;
			}
			catch (runtime_error err){
				cout << err.what()
					<< "\nTry Again? Enter y or n" << endl;
				char c;
				cin >> c;
				if (!cin || c == 'n')
					break;	//�������������while,do-while,for,switch��������ѭ�������߶��֧ѡ�����.
			}
		}
}
string getstring()
{
	string st1 = "nihao";       
	const char *s1 = st1.c_str();//c_str()���ص���һ���Կ��ַ�'\0'��β�ĳ����ַ�����.
	const char* const str = "C++ primer";
	return  s1;
}