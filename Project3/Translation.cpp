#include "Translation.h"
void Translation::setTarnslang(string t)
{
	Translang = t;
}

void Translation::setOrjlang(string o)
{
	orjLang = o;
}

void Translation::setInterpeter(string i)
{
	interpreter = i;
}
void Translation::getInput()
{
	string a_n, a_b;
	int p;
	Stock s;
	Author a;
	cout << "                    Price of the book: ";
	cin >> p;
	setPrice(p);
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
	cin.ignore(256, '\n');
	cout << "                    Name of the Interpreter: ";
	getline(cin, interpreter);
	cout << "                    What language is the book translated into? : ";
	cin >> Translang;
	cout << "                    Which language was the book translated from? : ";
	cin >> orjLang;
}
void Translation::displayInfo()
{
	cout << "                    Book Name: " << getName() << endl;
	cout << "                    Book Price: " << getPrice() << "tl" << endl;
	cout << "                    This book has been translated from" << orjLang << "to" << Translang << "by" << interpreter << endl;
	cout << "                    Author Name: " << getAuthor().getName() << endl;
	cout << "                    Author Birthday: " << getAuthor().getBirtday() << endl;
	cout << "                    Stock: " << getStock().getAmount() << endl;
}

Translation::Translation()
{
	Translang = "unknown";
	orjLang = "unknown";
	interpreter = "unknown";
}

Translation::~Translation()
{
}