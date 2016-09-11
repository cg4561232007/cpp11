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
//�������
class Disc_quote :public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price,
		std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc){}
	double net_price(std::size_t n) const = 0;//���麯��
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

};//�������������ͬ���ĳ�Ա�������ػ����Ա.
struct Derived :Base{
	Derived(int i) :mem(i){}
	int get_mem(){ return mem; }
	//int get_mem(){return Base:mem;} Ҫʹ����������˵������ʹ�����صĳ�Ա.
protected:
	int mem;
};

int oop15_main(void)
{
	Quote *iQutoe = new Quote();
	iQutoe->net_price(3);	//����û�����Ķ�������������˽�г�Ա���ܱ�����Ա
	//protect��Ա����public��private֮�䣬����������Ա����Ԫ�ǿ��Է��ʵ�.
	Bulk_quote *disquote = new Bulk_quote();
	disquote->isbn();//�û�Ҳ�����Է����ܱ�����Ա.

	return 0;
}