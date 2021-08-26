#pragma once
#include<string>
#include<iostream>
#include"Author.h"
#include"Stock.h"
using namespace std;
class Books
{
private:
	string name;
	int price;
	Author author;
	Stock stock;
public:

	void setName(string);
	string getName()const;
	void setPrice(int p);
	int getPrice()const;
	void setAuthor(Author author);
	Author getAuthor()const;
	void setStock(Stock stock);
	Stock getStock()const;

	virtual void getInput();
	virtual void displayInfo();

	Books();
	virtual ~Books();
};

