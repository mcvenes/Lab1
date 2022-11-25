#pragma once

#include <string>


// класс для хранения ФИО персон
class Person
{
private:
	std::string last_name;
	std::string middle_name;
	std::string first_name;

public:
	Person();
	Person(const Person& p);

	const std::string& getLastName() const;
	const std::string& getMiddleName() const;
	const std::string& getFirstName() const;

	void setLastName(const std::string& ln);
	void setMiddleName(const std::string& mn);
	void setFirstName(const std::string& fn);
};

