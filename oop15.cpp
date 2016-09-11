#include<iostream>
#include<string>
using namespace std;
class Quote{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price){}
	std::string isbn() const{ return bookNo; }
	virtual double net_price(std::size_t n) const{ return n*price; }
	virtual ~Quote() = default;       
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
//抽象基类
class Disc_quote :public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price,
		std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc){}
	double net_price(std::size_t n) const = 0;//纯虚函数
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};
class Bulk_quote :public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t n, double disc) :
		Disc_quote(book, p,n,disc){}
	double net_price(std::size_t) const override;

};
double Bulk_quote::net_price(size_t cnt) const
{
	return (cnt >= quantity) ? cnt*(1 - discount)*price : cnt*price;
}
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " #sold: " << n << "total due: " << ret << endl;
	return ret;
}



////////////////
struct Base{
	Base() :mem(0) {}
protected:
	int mem;

};//派生类中与基类同名的成员可以隐藏基类成员.
struct Derived :Base{
	Derived(int i) :mem(i){}
	int get_mem(){ return mem; }
	//int get_mem(){return Base:mem;} 要使用类作用于说明符来使用隐藏的成员.
protected:
	int mem;
};

int oop15_main(void)
{
	Quote *iQutoe = new Quote();
	iQutoe->net_price(3);	//类的用户即类的对象不允许访问类的私有成员和受保护成员
	//protect成员介于public和private之间，因此派生类成员和友元是可以访问的.
	Bulk_quote *disquote = new Bulk_quote();
	disquote->isbn();//用户也不可以访问受保护成员.

	return 0;
}