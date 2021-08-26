#pragma once
#include<string>
#include<iostream>
#include"Books.h"
using namespace std;
class Translation : public Books {
private:
	string Translang;
	string orjLang;
	string interpreter;
public:
	void setTarnslang(string t);
	void setOrjlang(string o);
	void setInterpeter(string i);
	void displayInfo();
	void getInput();
	Translation();
	virtual ~Translation();
};
