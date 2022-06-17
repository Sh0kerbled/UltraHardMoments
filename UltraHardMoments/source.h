#pragma once
#include <iostream>
#include "gtest/gtest.h"
#include "Phonenumber.h"
class TestBook : public testing::Test {
protected:
	Phonenumber* testB;

	void SetUp() override {
		std::stringstream tstStr;
		tstStr << "a 8643563423\n"
			<< "b 865367323\n"
			<< "c 86372546\n"
			<< "d 863572536\n";
		testB = new Phonenumber(tstStr);
	}
	void TearDown() override {
		delete testB;
	}
};

TEST_F(TestBook, GetPhoneNumberNF) {
	std::string lastName = "Andreev";
	auto temp = testB->GetPhoneNumber(lastName);
	EXPECT_EQ(std::get<0>(temp), "not found");
}
TEST_F(TestBook, GetPhoneNumber) {
	std::string lastName = "Ivanov";
	auto temp = testB->GetPhoneNumber(lastName);
	EXPECT_EQ(std::get<0>(temp), "");
}
TEST_F(TestBook, ChangeNumber) {
	std::string lastName = "Petrov";
	ASSERT_EQ(std::get<0>(testB->GetPhoneNumber(lastName)).empty(), true);

	PhoneNumber temp = std::get<1>(testB->GetPhoneNumber(lastName))[0];
	EXPECT_EQ(temp.number, "3421532");

	testB->ChangePhoneNumber(Person{ "Petrov", "Petr", "Petrovich" }, PhoneNumber{ 7, 322, "18534323", std::nullopt });

	temp = std::get<1>(testB->GetPhoneNumber(lastName))[0];
	EXPECT_EQ(temp.countryCode, 7);
	EXPECT_EQ(temp.cityCode, 322);
	EXPECT_EQ(temp.number, "18534323");
	EXPECT_EQ(temp.additional, std::nullopt);
}