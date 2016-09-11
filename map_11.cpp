#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<list>
#include<utility>
using namespace std;
using std::string;
pair<string, int> process(vector<string> &v)	//没有对v进行更改，因此也可以copy传值？
{
	if (!v.empty())
		return{ v.back(), v.back().size() };//列表初始化.
	else
		return pair<string, int>();
}
int map11_main(void)
{
	map<string, size_t> word_count;
	set<string> exclude = { "a", "an", "the", "THE" };
	string word;
	while (cin >> word){
		if (exclude.find(word)==exclude.end())
			++word_count[word];	//下标为关键字.
	}
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times " : " time ") << endl;
	//定义一个map，将单词与一个行号的list关联
	map<string, size_t> words;
	vector<string> lstring{ "my", "your", "he", "she" };
	list<size_t> lsize{ 2, 4, 6, 5 };
	size_t i = 0;
	auto iter_str = lstring.cbegin();
	for (auto iter = lsize.cbegin(); iter != lsize.cend()&&i!=4; ++iter,++i)
		words[*(iter_str+i)] = *iter;
	for (const auto &rw : words)
		cout << rw.first << " " << rw.second << endl;
	/***************************************************************************/
	multimap < string, string> authors = { { "Alen miller", "moon" }, { "Alen miller", "sun" }, { "Alen miller", "break"}};
	string search_item("Alen miller");
	auto entries = authors.count("Alen miller");
	auto iter = authors.find("Alen miller");
	while (entries){		//记住这种循环方式,while(k){--k};
		cout << iter->second << endl;
		++iter;
		--entries;
	}
	for (auto pos = authors.equal_range(search_item); 
		pos.first != pos.second; ++pos.first){
		cout << pos.first->second << endl;		//这样最方便.
	}
	return 0;
}