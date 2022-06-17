#pragma once
#define PhoneNumber_h

#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>

using namespace std;

struct PhoneNumber {
	uint16_t countryCode;
	uint16_t cityCode;
	std::string number;
	optional<uint16_t> additional;
};
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.country_code, p1.city_code, p1.number, p1.additional_number) < tie(p2.country_code, p2.city_code, p2.number, p2.additional_number);
}
optional<int> getOptInt(string& s)
{
	if (s == "")
	{
		return nullopt;
	}
	return stoi(s);
}
ostream& operator<<(ostream& out, const PhoneNumber& p)
{
	out << '+' << p.country_code << '(' << p.city_code << ')' << p.number;
	if (p.additional_number.has_value())
	{
		out << ' ' << p.additional_number.value();
	}
	return out;
}
int main()
{
	Person people_list;
	bool success;
	string surname;
	tie(success, surname) = people_list.FindPerson("Nurgaziev");
	cout << success << " " << surname << endl;
	tie(success, surname) = people_list.FindPerson("Taganov");
	cout << success << " " << surname << endl;
}