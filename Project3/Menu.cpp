#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<conio.h>
#include<locale.h> 
#include<fstream>
#include "Safe.h"
#include "Author.h"
#include"Books.h"
#include"Employee.h"
#include"Stock.h"
#include"Translation.h"
using namespace std;

string boss_p = "0000";


ifstream infile("magazines.txt");


void addFrom_file(vector <Books*> book) {


	string book_name, author_name;
	string line;
	string delimiter = "/";


	int  start_index = 0, finish_index;
	int  book_stock = 0;

	Author author;
	Stock stock;
	Books *add_book = new Books;
	
	while (!infile.eof()) {
		getline(infile, line);
		book_stock++;
		
	}
	infile.seekg(0);

	string token;

	stock.updateStock(book_stock);

	while (!infile.eof()) {
		getline(infile, line);
		
		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		add_book->setName(token);
		line.erase(start_index, finish_index + 1);

		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		author.setName(token);
		add_book->setAuthor(author);
		line.erase(start_index, finish_index + 1);

		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		line.erase(start_index, finish_index + 1);

		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		line.erase(start_index, finish_index + 1);

		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		line.erase(start_index, finish_index + 1);

		finish_index = line.find(delimiter);
		token = line.substr(start_index, finish_index);
		add_book->setPrice(stoi(token));
		line.erase(start_index, finish_index + 1);
		book.push_back(add_book);

	}

	infile.close();
}

void displayBookList(vector <Books*> book) {  //function for print booklist.
	if (book.size() > 0) {
		cout << endl << "           --------------BOOK LIST---------------" << endl;
		cout << left << setw(20) << "Book Name" << setw(20) << "Author Name" << setw(20) << "Price" << setw(20) << "Stock Amount" << endl;
		for (int i = 0; i < book.size(); i++) {
			cout << left << setw(20) << book[i]->getName() << setw(20) << book[i]->getAuthor().getName() << setw(20) << book[i]->getPrice() << setw(20) << book[i]->getStock().getAmount() << endl;
		}
	}
	else {
		cout << "                          No Avaliable Book" << endl;
	}
}

void menu() {


	setlocale(LC_ALL, "Turkish"); //Displaying turkish characters on console application


	
	int choose, ch;


	vector <Books*> book;     // vector for Book ' s informations. 
	vector <Employee> emp;  // vector for Employee's  informations.
	Safe s;

	addFrom_file(book);
	do { //loop for bookshop management system menu

		cout << endl << endl <<endl << endl ;
		cout << "                          ~~BOOKSHOP~~ " << endl;
		cout << "                          1.BOSS" << endl;
		cout << "                          2.EMPLOYEE" << endl;
		cout << "                          3.COSTUMER" << endl;
		cout << "                          4.EXIT" << endl;
		cout << "                          Choose your role: ";
		cin >> ch;
		system("cls");

		if (ch == 1) {
			cin.ignore(256, '\n');
			cout << endl << endl << endl << endl << endl << endl << endl;
			string pass = "";
			char ch;
			cout << "                          Enter Boss Password: ";
			ch = _getch();

			while (ch != 13) {  // Hiding password when is inputing

				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			if (pass == boss_p) { //BOOS
				do { // Loop for boss.

					cout << endl << endl;
					cout << "                  ********** WELCOME BOSS ***********" << endl;;
					cout << "                          1. ADD EMPLOYEE" << endl;
					cout << "                          2. DELETE EMPLOYEE" << endl;
					cout << "                          3. CHANGE YOUR PASSWORD " << endl;
					cout << "                          4. CHECK THE SAFE " << endl;
					cout << "                          5. EXIT BOSS SCREEN " << endl;
					cout << "                          Choose your action: ";
					cin >> choose;
					system("cls");

					if (choose == 1) { // Add employee.
						Employee employee;
						string p, e_n, p_n;
						double wage;

						cin.ignore(256, '\n');
						cout << "                          Enter employee name: ";
						getline(cin, e_n);
						employee.setName(e_n);

						cin.ignore(256, '\n');
						cout << "                          Enter employee password: ";
						getline(cin, p);
						employee.setPassword(p);

						cin.ignore(256, '\n');
						cout << "                          Enter employee phone number: ";
						getline(cin, p_n);

						cout << "                          Enter employee's Wage:";
						cin >> wage;

						employee.setWage(wage);
						employee.setP_num(p_n);
						emp.push_back(employee);

						cout <<endl<< "                          Employee added !";

					}
					else if (choose == 2) {  // Delete employee.

						string d_name;
						int control = 1;

						cout << endl << "             -------EMPLOYEE LIST--------" << endl;
						cout << left << setw(20) << "Employee Name" << setw(20) << "Password" << setw(20) << "Phone Number" << setw(20) << "Wage" << endl;
						for (int i = 0; i < emp.size(); i++) {
							cout << left << setw(25) << emp[i].getName() << setw(20) << emp[i].getPassword() << setw(20) << emp[i].getP_num() << setw(20) << emp[i].getWage() << endl;
						}
						cin.ignore(256, '\n');
						cout << "                          Enter the name of the person to be dismissed: ";
						getline(cin, d_name);

						for (int i = 0; i < emp.size(); i++) {
							if (emp[i].getName() == d_name) {
								emp[i] = move(emp.back());
								emp.pop_back();
								cout << "                          Employee deleted !" << endl;
								control = 0;
							}
						}
						if (control) {
							cout << "                          The employee's name was not found !\a";
						}
					}
					else if (choose == 3) {		//CHANGE BOSS'S PASSWORD

						string oldpass = "";
						char ch;
						cout << endl<<"                          Enter old password: ";
						ch = _getch();

						while (ch != 13) {  // Hiding password when is inputing

							oldpass.push_back(ch);
							cout << '*';
							ch = _getch();
						}

						if (oldpass == boss_p) {
							cin.ignore(256, '\n');
							cout<<endl << "                          Enter new password: ";
							getline(cin, boss_p);
							cout << endl<<"                          Your password has been changed !" << endl;
						}
						else {
							cout << endl<<"                          Old password is wrong! Try again." << endl;
						}
					}
					else if (choose == 4) {			//checking the safe
						do {
							cout << endl << endl;
							cout << "                          $$ SAFE OF BOOKSHOP $$" << endl;
							cout << "                          1. DISPLAY SAFE " << endl;
							cout << "                          2. WITHDRAW MONEY TO THE SAFE" << endl;
							cout << "                          3. DEPOSIT MONEY INTO THE SAFE" << endl;
							cout << "                          4. EXIT THE SAFE" << endl;
							cout << "			               Choose your action: ";
							cin >> choose;
							system("cls");
							if (choose == 1) {   //Display Safe
								cout << endl << endl;
								cout << "_____________________SAFE_____________________" << endl;
								s.calculateEmpwages(emp);
								s.display();
							}
							else if (choose == 2) { //Withdraw money from the safe
								double w_money;
								cout << "                          Enter the amount you want to withdraw from the safe: ";
								cin >> w_money;
								if (w_money <= s.getTotalMoney()) { //control
									s.decMoney(w_money);
									cout << "                          The amount you requested was taken from the safe !" << endl;
								}
								else
									cout << "                          The money in the safe is insufficient !\a" << endl;
							}
							else if (choose == 3) { //3.Deposit money into the safe.
								double d_money;
								cout << "                          Enter the amount you want to deposit into the safe: ";
								cin >> d_money;
								s.addMoney(d_money);
								cout << "                          The amount you requested has been deposited in the safe !" << endl;
							}
						} while (choose != 4);
					}
				} while (choose != 5);
			} //Ending of the Boss Selection
			else
				cout << "                          Wrong Password !!!\a" << endl;
		}
		else if (ch == 2) { //EMPLOYEE
			string p, name;
			int  c, control = 0;
			cin.ignore(256, '\n');
			cout << "                          Enter your Employee name: ";
			getline(cin, name);
			for (int i = 0; i < emp.size(); i++) {
				if (emp[i].getName() == name) {
					c = i;
					control = 1;
				}
			}
			if (control == 0) {
				cout << "                          Your name was not found !!! \a" << endl;
			}
			if (control) {

				string password = "";
				char ch;
				cout << "                          Enter your Employee password: ";
				ch = _getch();

				while (ch != 13) {  // Hiding password when is inputing

					password.push_back(ch);
					cout << '*';
					ch = _getch();
				}
				if (emp[c].getPassword() == password) {
					do { // loop for employee screen.
						cout << endl;
						cout << "-----------------------------EMPLOYEE SCREEN--------------------" << endl;
						cout << "                          1. ADD BOOK" << endl;;
						cout << "                          2. UPDATE STOCK" << endl;
						cout << "                          3. CHANGE PRICE OF BOOK" << endl;
						cout << "                          4. SHOW BOOK LIST" << endl;
						cout << "                          5. SALE BOOK" << endl;
						cout << "                          6. CHANGE YOUR PASSWORD" << endl;
						cout << "                          7. EXIT EMPLOYEE SCREEN " << endl;
						cout << "                          Choose your action: ";
						cin >> choose;
						system("cls");
						if (choose == 1) { // add book.
							string ans;
							cout << "                          Is the book a translated book?(yes/no): ";
							cin >> ans;
							if (ans == "no") {
								string  a_b, n_b, a_n;
								int  p_b, control = 1;
								cin.ignore(256, '\n');
								cout << "                          The name of the book: ";
								getline(cin, n_b);
								for (int i = 0; i < book.size(); i++) {
									if (book[i]->getName() == n_b) {
										cout << "                          The book you want to add is already in the list !!!  You can update stock and information from other options." << endl;
										control = 0;
									}
								}
								if (control) {
									Books* b = new Books;
									b->getInput();
									b->setName(n_b);
									book.push_back(b);
									cout << "                          Book added !";
								}
							}
							else {
								string a_b, n_b, a_n;
								int  p_b, control = 1;
								cin.ignore(256, '\n');
								cout << "                          The name of the book: ";
								getline(cin, n_b);

								for (int i = 0; i < book.size(); i++) {
									if (book[i]->getName() == n_b) {
										cout << "                          The book you want to add is already in the list !!! You can update stock and information from other options. " << endl;
										control = 0;
									}
								}
								if (control) {
									Translation* t = new Translation;
									t->setName(n_b);
									t->getInput();
									book.push_back(t);
									cout << "                          Book added !";
								}
							}
						}
						else if (choose == 2) { //update stock option
							string b_name;
							int c_amount, control = 1;
							displayBookList(book);
							cin.ignore(256, '\n');
							cout << endl << "                          Enter the name of the book for which you will change the stock amount: ";
							getline(cin, b_name);

							for (int i = 0; i < book.size(); i++) {
								if (book[i]->getName() == b_name) {
									book[i]->displayInfo();
									cout << "                          Enter new stock amount: ";
									cin >> c_amount;
									Stock s;
									s.updateStock(c_amount);
									book[i]->setStock(s);
									cout << "                          Stock amount has been changed !" << endl;
									control = 0;
								}
							}
							if (control) {
								cout << "                          No book with this name was found !!! \a You can try adding a book using option 1." << endl;
							}
						}
						else if (choose == 3) { // update price option.
							string b_name;
							int n_price, control = 1;
							displayBookList(book);
							cin.ignore(256, '\n');
							cout << endl << "                          Enter the name of the book for which you will change the price: ";
							getline(cin, b_name);
							for (int i = 0; i < book.size(); i++) {
								if (book[i]->getName() == b_name) {
									book[i]->displayInfo();
									cout << "                          Enter new price of book: ";
									cin >> n_price;
									book[i]->setPrice(n_price);
									cout << "                          Price has been changed !" << endl;
									control = 0;
								}
							}
							if (control) 
								cout << "                          No book with this name was found!!! \a You can try to add a book using option 1." << endl;
							
						}
						else if (choose == 4) { //show book list option
							displayBookList(book);
						}
						else if (choose == 5) { //sale book list option
							displayBookList(book);
							int  numberOfbook, control = 1;
							string n_book;

							cin.ignore(256, '\n');
							cout << "                          Enter the name of the book to be sold: ";
							getline(cin, n_book);

							for (int i = 0; i < book.size(); i++) {
								if (book[i]->getName() == n_book) {
									book[i]->displayInfo();
									cout << "                          Enter the amount to sell: ";
									cin >> numberOfbook;
									if (book[i]->getStock().getAmount() >= numberOfbook) {
										Stock st;
										st.updateStock(((book[i]->getStock()).getAmount() - numberOfbook));
										book[i]->setStock(st);
										s.addMoney(book[i]->getPrice() * numberOfbook);
										cout << "                          The sale is complete !";
									}
									else
										cout << "                          There is not enough stock !!!\a";
									control = 0;
								}
							}
							if (control) {
								cout << "                          No book with this name was found. You can try adding a book using option 1." << endl;
							}

						}
						else if (choose == 6) { //change password option
							string n_p;
							string oldpass;
							cin.ignore(256, '\n');
							cout << "                          Enter old password: ";
							cin >> oldpass;
							if (oldpass == boss_p) {
								cout << "                          Enter new password: ";
								getline(cin, n_p);
								emp[c].setPassword(n_p);
								cout << "                          Your password has been changed !" << endl;
							}
							else {
								cout << "                          Old password is wrong!! Try again later." << endl;
							}
							
						}
					} while (choose != 7);
				}
				else
					cout << "                          Wrong password !!!\a" << endl;
			}
		}

		else if (ch == 3) { //CUSTOMER
			do { // loop for customer screen.
				cout << endl << endl;
				cout << "                          ## WELCOME BOOKSHOP ## " << endl;
				cout << "                          1. BUY BOOK" << endl;
				cout << "                          2. RETURN THE BOOK" << endl;
				cout << "                          3. BOOK LIST " << endl;
				cout << "                          4. EXIT COSTUMER SCREEN" << endl;
				cout << "                          Choose your action: ";
				cin >> choose;
				system("cls");
				if (choose == 1) { //buy book.
					displayBookList(book);
					string buy_book_name;
					string answer_payment;

					cin.ignore(256, '\n');
					cout << "                          Enter the name of the book you want to buy:";
					getline(cin, buy_book_name);

					int numberOfbook, control = 1;

					for (int i = 0; i < book.size(); i++) {
						if (book[i]->getName() == buy_book_name) {
							book[i]->displayInfo();
							cout << "                          Enter the amount to buy: ";
							cin >> numberOfbook;
							if (book[i]->getStock().getAmount() >= numberOfbook) {
								cout << "                          Total price : " << book[i]->getPrice() * numberOfbook << endl;
								cout << "                          Do you confirm the payment? (yes or no):";
								cin >> answer_payment;
								if (answer_payment == "yes") {
									Stock st;
									st.updateStock(((book[i]->getStock()).getAmount() - numberOfbook));
									book[i]->setStock(st);
									s.addMoney(book[i]->getPrice() * numberOfbook);
									cout << "                          Payment complete. !" << endl;
								}
								else
									cout << "                          Payment could not be completed !!!\a" << endl;
							}
							else
								cout << "                          There is not enough stock !!!\a";
							control = 0;
						}
					}
					if (control) { // control find or not find name of book.
						cout << "                          Book not found.Please check the list!!! \a " << endl;
					}
				}
				else if (choose == 2) {// return the book.
					string return_book_name, answer_payment;
					int numberOfbook, control = 1;
					cin.ignore(256, '\n');
					cout << "                          Enter the name of the book you want to return: ";
					getline(cin, return_book_name);
					
					for (int i = 0; i < book.size(); i++) {
						if (book[i]->getName() == return_book_name) {
							book[i]->displayInfo();
							cout << "                          Enter the amount to return: ";
							cin >> numberOfbook;
							int temp;
							cout << "                          How many days ago you bought?: ";
							cin >> temp;
							if (temp >= 7) {	//Controlling refund for if receipt day(s) is greater than a week
								cout << "                          You cannot return your book due to your receipt passed a week. " << endl;
								control = 0;
								break;
							}
							cout << "                          Total amount to be refunded: " << book[i]->getPrice() * numberOfbook << endl;
							cout << "                          Do you confirm the payment? (yes or no):";
							cin >> answer_payment;
							if (answer_payment == "yes") {
								Stock st;
								st.updateStock(((book[i]->getStock()).getAmount() + numberOfbook));
								book[i]->setStock(st);
								s.decMoney(book[i]->getPrice() * numberOfbook);
								cout << "                          Payment complete. !" << endl;
							}
							else
								cout << "                          Payment could not be completed!!! \a" << endl;
							control = 0;
						}
					}
					if (control) { // control find or not find name of book.
						cout << "                          Book not found.Please check the name of book!!!\a " << endl;
					}
				}
				else if (choose == 3) {
					displayBookList(book);
				}
			} while (choose != 4);
		}

	} while (ch != 4);
	
}