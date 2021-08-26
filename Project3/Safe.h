#pragma once
#include<iostream>
#include<vector>
#include"Employee.h"
using namespace std;
class Safe {
private:
	double totalMoney;
	double empWages;
public:
	void calculateEmpwages(vector <Employee> emp);
	void addMoney(double m);
	void decMoney(double m);
	void display();
	int getTotalMoney();
	Safe();
	~Safe();
};

