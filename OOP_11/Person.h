#pragma once
#include <string>
#include <iostream>
class IPerson
{
public:
	virtual const std::string& getName() = 0;
	virtual void fight() = 0;
	virtual ~IPerson(){}
};

class Person : public IPerson
{
public:
	Person(const std::string& name);
	void fight() override;
	const std::string& getName() override;

private:
	std::string _name;
};