#include "Books.h"
#include<fstream>
#include<string>

void Books::setName(string name){	this->name = name;}

string Books::getName()const{	return name;}

void Books::setPrice(int p){	this->price = price;}

int Books::getPrice()const{		return price;}

void Books::setAuthor(Author author){	this->author = author;}

Author Books::getAuthor()const{	return author;}

void Books::setStock(Stock stock){	this->stock = stock;}

Stock Books::getStock()const{	return stock;}

void Books::displayInfo() {
	cout << "                    Book Name: " << name << endl;
	cout << "                    Book Price: " << price << "tl" << endl;
	cout << "                    Author Name: " << author.getName() << endl;
	cout << "                    Author Birthday: " << author.getBirtday() << endl;
	cout << "                    Stock: " << stock.getAmount() << endl;
}
void Books::getInput()
{
	string a_n, a_b;
	Stock s;
	Author a;
	cout << "                    Price of the book: ";
	cin >> price;
	cin.ignore(256, '\n');
	cout << "                    Author name: ";
	getline(cin, a_n);
	cin.ignore(256, '\n');
	cout << "                    Author birthday(dd/mm/yy):";
	getline(cin, a_b);
	a.setName(a_n);
	a.setBirtday(a_b);
	setAuthor(a);
	int b_amount;
	cout << "                    How many books: ";
	cin >> b_amount;
	s.updateStock(b_amount);
	setStock(s);
}

Books::Books(){	name = "unkown";	price = 0;}
Books::~Books(){}
