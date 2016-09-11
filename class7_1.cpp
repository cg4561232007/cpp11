#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::string;
//�µ�Sales_data��
class Sales_data{
private:
	//private function
	string bookNo;
	unsigned units_sold{ 0 };
	double revenue{ 0 };
	Sales_data & combine(const Sales_data&);
	double avg_price() const;
public:
	//construct function
	Sales_data() = default;	//Ĭ�Ϲ��캯��,�����ڳ�ԱĬ�ϳ�ʼ�������û���������캯��,�������ͺͷ������ͻ����δ����.
	Sales_data(const string &s) :bookNo(s){}
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n){}
	Sales_data(istream &is);
	string isbn() const{ return bookNo; }
	//��Ԫ,��֤�˽ӿں������Է������ڲ���Ա
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
};
//���ⲿ�Ĺ��캯��
Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}
//Sales_data�ķǳ�Ա�ӿں�������,��֤����Ԫ�����û��ɼ�.
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);	//��Ϊostream�ǲ����Կ����ģ��ʱ��뷵������.
std::istream& read(std::istream&, Sales_data&);
double Sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data& Sales_data::combine(const Sales_data&){
	units_sold += 3;
	revenue += 21;
	return *this;
}
std::ostream& print(std::ostream& os, const Sales_data& item){
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}
std::istream& read(std::istream& is, Sales_data& item){
	double price = 0;
	is >> item.isbn() >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
int class7_1main(void)
{

	return 0;
}
