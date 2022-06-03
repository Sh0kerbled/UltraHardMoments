#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//task 1
void insert_sort() {
	vector<int> v = { 4, 2, 3, 1, 5 };
	generate(v.begin(), v.end(), []() {return (rand() % 100); });
	for (int n : v) {
		cout << n << " ";
	}
}

//task 2
void SecondCode()
{
    vector<double> a(100);

    double error = 0;
    generate(a.begin(), a.end(), [](int i) { return ++i; });

    copy(a.begin(), a.end(), ostream_iterator<int> { cout, " " });

    for_each(a.begin(), a.end(), [&](const double& i)
        {
            error += pow(i - static_cast<int>(i), 2);
        });
}
int main()
{
	insert_sort();
    SecondCode();
}
