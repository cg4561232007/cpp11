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
	//�������������ͣ����������ͣ����û��begin(),end()��Ա����,Ҫʹ��begin(),end()�⺯��.
	authors.assign(articles.cbegin(), articles.cend());	//ֻ��˳����������ʹ��assign.
	//assign�ĵڶ����汾
	list<string> slist(1);	//1��Ԫ��Ϊ��string
	slist.assign(10, "hiya");
	//�൱��
	slist.clear();
	slist.insert(slist.begin(), 10, "hiya");	//slist.push_front("hiya");10��
	//swap����
	vector<string> svec1(10);
	vector<string> svec2(24);
	swap(svec1, svec2);	//����֮��svec1����24��Ԫ�أ�svec2����10��Ԫ��,��û��Ԫ�ؽ�����ֻ���ڲ����ݽṹ������ʱ��ܶ�.
	//��string�������ƻ�������,��array��������������Ԫ�أ����ǵ������󶨵�Ԫ��û��.
	auto iter = authors.begin();
	string word;
	while (cin >> word)
		iter = authors.insert(iter, word);

	if (!articles.empty()){
		articles.front() = "42hihi"; //���ص���һ�����ã����Ըı���ֵ.
		auto &v = articles.back();
		v = "love";	//�ı���βԪ�ص�ֵ
		auto v1 = articles.back();
		v1 = "love";	//v1������βԪ�ص�һ������������ı�βԪ�ص�ֵ. 
	}
	//forward_list����Ӻ�ɾ������
	forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = flst.before_begin();
	forward_list<int>::iterator curr = flst.begin();
	while (curr!=flst.end()){
		if (*curr % 2)
			curr=flst.erase_after(prev);	//Ҫ�Ե��������и���
		else{
			prev = curr;
			++curr;
		}
	}
	//����end��������һ����ע��
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
	auto begin = v.begin();
	while (begin != v.end()){
		++begin;
		begin = v.insert(begin, 3);
		++begin;
	}
	//vector ���������,����һ����Ԥ���ռ䣬��Ԥ���ռ�����֮ǰ�����ܿ�.
	//v.capacity();	v.reserve(n); v.size();
	//ÿ����Ҫ�����µĿռ�ʱ��ʹ��ǰ�������������Ǳ�׼���ʵ�ַ�ʽ.
	string s1("hello",2);
	string s2(10, 'v');
	string s20 = string(10, 'v');
	const char *cp = "your business";	//�Կ��ַ���β���ַ���
	char null[] = { 'h', 'y', 'o' };
	string s10(cp,2);	//���������ַ�
	string s3(null);	//�������Ϊʶ�𲻵����ַ�.
	//��ʽ����
	string s4(cp + 6, 5);	//��cp[6]��ʼ����5���ַ�.
	string s5(s1, 6, 5);	//��s1[6]��ʼ����5���ַ�.	string Ҳ�������±���ʳ�Ա�ַ�!!!
	string s6(s1, 6);

	string s("hello world");
	string s21 = s.substr(6, 11);
	s.assign(cp, 7);
	s.insert(s.size(), cp + 7);

	//append��replace
	string so("C++ primer"), sp(s);
	so.append(" 4th Ed.");
	s2.replace(11, 3, "fifth");	//�ӵ�11���ַ���ʼ��3��ɾ��������fifth.
	
	//�ַ�����������
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