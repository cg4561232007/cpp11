#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;
int vessel9_2main(void)
{
	int a[8]={ 1, 2, 3, 4, 5, 6 };
	list<string> authors = { "Milon", "Shakespare", "Austen" };
	vector<const char*> articles = { "a", "an", "the" };
	forward_list<string> words(articles.begin(),articles.end());
	//数组是内置类型，不是类类型，因此没有begin(),end()成员函数,要使用begin(),end()库函数.
	authors.assign(articles.cbegin(), articles.cend());	//只有顺序容器才能使用assign.
	//assign的第二个版本
	list<string> slist(1);	//1个元素为空string
	slist.assign(10, "hiya");
	//相当于
	slist.clear();
	slist.insert(slist.begin(), 10, "hiya");	//slist.push_front("hiya");10次
	//swap交换
	vector<string> svec1(10);
	vector<string> svec2(24);
	swap(svec1, svec2);	//交换之后svec1含有24个元素，svec2含有10个元素,并没有元素交换，只是内部数据结构交换，时间很短.
	//对string交换会破坏迭代器,对array交换会真正交换元素，但是迭代器绑定的元素没变.
	auto iter = authors.begin();
	string word;
	while (cin >> word)
		iter = authors.insert(iter, word);

	if (!articles.empty()){
		articles.front() = "42hihi"; //返回的是一个引用，可以改变其值.
		auto &v = articles.back();
		v = "love";	//改变了尾元素的值
		auto v1 = articles.back();
		v1 = "love";	//v1仅仅是尾元素的一个拷贝，不会改变尾元素的值. 
	}
	//forward_list的添加和删除操作
	forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = flst.before_begin();
	forward_list<int>::iterator curr = flst.begin();
	while (curr!=flst.end()){
		if (*curr % 2)
			curr=flst.erase_after(prev);	//要对迭代器进行更新
		else{
			prev = curr;
			++curr;
		}
	}
	//保存end迭代器是一个坏注意
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
	auto begin = v.begin();
	while (begin != v.end()){
		++begin;
		begin = v.insert(begin, 3);
		++begin;
	}
	//vector 对象的增长,分配一部分预留空间，在预留空间用完之前增长很快.
	//v.capacity();	v.reserve(n); v.size();
	//每次需要分配新的空间时会使当前容量翻倍，这是标准库的实现方式.
	string s1("hello",2);
	string s2(10, 'v');
	string s20 = string(10, 'v');
	const char *cp = "your business";	//以空字符结尾的字符串
	char null[] = { 'h', 'y', 'o' };
	string s10(cp,2);	//拷贝两个字符
	string s3(null);	//会出错，因为识别不到空字符.
	//花式拷贝
	string s4(cp + 6, 5);	//从cp[6]开始拷贝5个字符.
	string s5(s1, 6, 5);	//从s1[6]开始拷贝5个字符.	string 也可以用下标访问成员字符!!!
	string s6(s1, 6);

	string s("hello world");
	string s21 = s.substr(6, 11);
	s.assign(cp, 7);
	s.insert(s.size(), cp + 7);

	//append与replace
	string so("C++ primer"), sp(s);
	so.append(" 4th Ed.");
	s2.replace(11, 3, "fifth");	//从第11个字符开始数3个删除并插入fifth.
	
	//字符串搜索操作
	string name("r4t5y6u1i3"), numbers("0123456749");
	string::size_type pos = 0;
	auto iter1 = numbers.begin();
	while ((pos=name.find_first_of(numbers,pos))!=string::npos){
		cout << "found number at index: " << pos
			<< "value is: " << *(iter1 + pos) << endl;
		++pos;
	}
	return 0;
}