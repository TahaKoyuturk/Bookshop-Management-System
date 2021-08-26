#pragma once
#include<string>
using namespace std;
class Author
{
private:
	string name;
	string birtday;
public:
	void setName(string n);
	string getName();
	void setBirtday(string b);
	string getBirtday();
	Author();
	~Author();
};

