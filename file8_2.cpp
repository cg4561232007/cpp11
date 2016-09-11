#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::istream;
void process(istream& is){
	is.clear(is.rdstate()&~is.failbit&~is.badbit);
}
int file8_2main(int argc,char *argv[])
{
	const char *fname = "C:\\Users\\heihei\\Desktop\\smell.txt";
	std::ifstream ifstrm;
	ifstrm.open(fname);
	for (auto p = argv + 1; p != argv + argc; ++p){
		std::ifstream input(*p);	//!!!*p
		if (input)
			process(input);
		else
			std::cerr << "couldn't open: " + std::string(*p);
	}
	if (ifstrm){
		cout << "opening successfully!" << endl;
		ifstrm.close();
		ifstrm.open(fname + '2');	//这里应该怎么做呢?
		if (ifstrm.good())
			cout << "good!" << endl;
		return 0;
	}
	else return -1;
}
