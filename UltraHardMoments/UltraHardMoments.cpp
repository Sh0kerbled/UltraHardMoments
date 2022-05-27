#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//task 1
template <typename N>
void swap(N* a, N* b)
{
	N temp = *a;
	*a = *b;
	*b = temp;
}

//task 2
template <typename T>
void SortPointer(vector<T>& sorti)
{
	for (const auto& item : sorti) {
		cout << "{" << item.first << "," << item.second << "}" << "; ";
	}
	cout << endl;
}

int main()
{
	//task 1
	setlocale(LC_ALL, "ru");
	int a(10);
	int b(15);

	swap(&a, &b);
	cout << a << b << endl;

	//task 2
	vector<pair<int, string>> sortirovka = { {3,"c"},
										 {4,"d"},
										 {1,"a"},
										 {2,"b"} };

	sort(sortirovka.begin(), sortirovka.end());

	cout << "Сортировка: ";
	SortPointer(sortirovka);
}
