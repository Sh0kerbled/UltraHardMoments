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
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <execution>
#include <future>
#include <iomanip>
#include <windows.h>


using namespace std;



class FullName
{
	string name = 1;
	string surname = 2;
	optional string patronymic = 3;
}

class Student
{
	FullName name = 1;
	uint32_t ball = 5;
	uint32_t score = 4
};

class StudentGroup
{
	Student student = 1
};

class IRepository {
	virtual void Open() = 0;
};
class IMethods {
	virtual double GetAverageScore(const FullName& name) = 0;
	virtual string GetAllInfo(const FullName& name) = 0;
	virtual string GetAllInfo() = 0;
};

//task 3 провальная

//class FullName {
//private:
//	vector<tuple<string, string, string>> people;
//public:
//	FullName() {
//		people = {
//		{"Nurgaziev", "Dauren", "Kairatovich"},
//		};
//	}
//	pair<bool, int> FindPoet(string find_patronymic) {
//		for (const auto& [surname, name, patronymic] : people) {
//			if (name == find_patronymic) {
//				return { true, patronymic };
//			}
//		}
//		return { false, 0 };
//	}
//};
//
//class Student : FullName {
//	FullName HumanList;
//	bool success;
//	string surname;
//	tie(success, surname) = HumanList.FindPoet("Nurgaziev");
//	cout << success << " " << surname << " ";
//	cout << "Успеваемость -> " << rand() % 5 << endl;
//};

int main()
{
	FullName fullname;
	fullname.name("Dauren");
	fullname.surname("Nurgaziev");
	fullname.patronymic("kairatovich");
	Student score;
	score.ball(5);
	score.ball(5);
	score.ball(5);
	score.ball(5);
	score.ball(5);
	score.ball(5);
	score.ball(5);
	score.ball(4);
	score.ball(4);
	score.ball(4);
	score.ball(4);

	score.average_score(score.ball().begin(), score.ball().end(), 0) / score.ball().size());
}