#pragma once
#include<string>
using namespace std;
class Employee
{
private:
	string name;
	string password;
	string p_num;
	double wage;
public:
	void setName(string n);
	string getName();
	void setPassword(string p);
	string getPassword();
	void setP_num(string p);
	string getP_num();
	void setWage(double w);
	double getWage();
	Employee();
	~Employee();
};

