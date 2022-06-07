#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
using namespace std;

//task 1
void DeleteIt()
{
	set <string> first;
	first.insert("one");
	first.insert("two");
	first.insert("one");

	copy(first.begin(), first.end(), ostream_iterator<string>(cout, " "));
	cout << endl << endl;

	set <int> second;
	second.insert(1);
	second.insert(2);
	second.insert(1);

	copy(second.begin(), second.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	set <bool> third;
	third.insert(true);
	third.insert(false);
	third.insert(true);

	copy(third.begin(), third.end(), ostream_iterator<bool>(cout, " "));
	cout << endl << endl;
}

//task 2

void text()
{
	multimap<int, string> the;
	string jtext;
	const string suggest_end = ".!?";

	getline(cin, jtext);
	jtext.push_back('.');
	cout << jtext;
	while (!jtext.empty()) {}

	//for_each(the.begin(), the.end(), [](pair<int, string> item) {
	//	jtext.find();
	//	});
}

int main()
{
	DeleteIt();
	text();
}
