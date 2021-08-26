#include "Employee.h"
void Employee::setName(string n)
{
	name = n;
}

string Employee::getName()
{
	return name;
}

void Employee::setPassword(string p)
{
	password = p;
}

string Employee::getPassword()
{
	return password;
}

void Employee::setP_num(string p)
{
	p_num = p;
}

string Employee::getP_num()
{
	return p_num;
}

void Employee::setWage(double w)
{
	wage = w;
}

double Employee::getWage()
{
	return wage;
}


Employee::Employee()
{
	name = "unkown";
	password = "unkown";
	p_num = "0";
}

Employee::~Employee()
{
}