#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
#include <ostream>
#include <istream>

using namespace std;

//task 1
void ex1() {
	double n, sum = 0, num, a;
	for (n = 1; n <= 3; n++) {
		cin >> num;
		sum += num;
	}
	a = sum / 3;
	cout << endl << a << endl;
}

//task 2
template <typename T>
class Matrix
{

    T* data;
    unsigned int i;
    unsigned int j;
	double A[2][2];
	double det;
public:
    Matrix(unsigned int _i, unsigned int _j){
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cin >> A[i][j];
		det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	}
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);

    T determinant() const;
};

//task 3
class OwnIterator
{
public:;
	std::vector<int> v = { 1, 2, 3, 4, 5 };

};

int main()
{
	//task 1
	ex1();
	//task 3
	OwnIterator it;
	auto iter = it.v.begin();
	while (iter != it.v.end())
	{
		std::cout << *iter << std::endl;
		++iter;             
	}
	
	
	 

	
	
}
