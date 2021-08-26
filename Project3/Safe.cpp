#include "Safe.h"
void Safe::calculateEmpwages(vector<Employee> emp)
{
	int sum = 0;
	for (int i = 0; i < emp.size(); i++) {
		sum += emp[i].getWage();
	}
	empWages = sum;
}

void Safe::addMoney(double m)
{
	totalMoney += m;
}

void Safe::decMoney(double m)
{
	totalMoney -= m;
}

void Safe::display()
{
	cout << "Total Money: " << totalMoney << " $" << endl;
	cout << "Total Employee Wages: " << empWages << " $" << endl;
}

int Safe::getTotalMoney()
{
	return totalMoney;
}

Safe::Safe()
{
	totalMoney = 0;
	empWages = 0;
}

Safe::~Safe()
{
}
