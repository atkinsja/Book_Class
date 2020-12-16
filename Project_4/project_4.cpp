//************************************************************************
//	Jeremy Atkins
//	Professor Mackay
//	CS 121
//	5/15/2018
//	Program name:	Project_4
//	Program files:	project_4.cpp
//					bookTypeimp.cpp
//					bookType.h
//	Input Files:	bookInfo.txt
//	Output Files:	none
//	Included Files:	project_4.cpp
//					bookTypeimp.cpp
//					bookType.h
//	Purpose:		Populates a "bookshelf" with book objects
//					allowing a user to search for books by title,
//					author, isbn, price, and number of copies.
//					Also allows a user to display the information
//					for every book in the shelf.
//************************************************************************
#include <iostream>
#include <fstream>
#include "bookType.h"

using namespace std;
const int SIZE = 5;

void populate(bookType [SIZE]);
void menu(bookType [SIZE]);

//main driver for program
int main()
{
	bookType book_shelf[SIZE];
	populate(book_shelf);
	menu(book_shelf);
	return 0;
}

/*
	populate
	Opens input file and creates an array of bookType objects
*/
void populate(bookType shelf[SIZE])
{
	ifstream inFile;
	string filename = "bookInfo.txt";
	string title;
	string author;
	string isbn;
	double price;
	int num_copies;

	inFile.open(filename);
	if (!inFile)
	{
		cout << "Error opening input file " << filename << endl;
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		getline(inFile, title);
		getline(inFile, author);
		getline(inFile, isbn);
		inFile >> price;
		inFile >> num_copies;
		inFile.ignore();
		inFile.ignore();
		shelf[i].set_title(title);
		shelf[i].set_author(author);
		shelf[i].set_isbn(isbn);
		shelf[i].set_price(price);
		shelf[i].set_num_copies(num_copies);
	}
}

/*
	menu
	Creates a menu of options to allow the user to search for books
*/
void menu(bookType book_shelf[SIZE])
{
	int input;
	string query_title;
	string query_author;
	string query_isbn;
	double query_price;
	int query_num_copies;
	do
	{
		bool found = false;
		cout << "\nSearch for books by:" << endl;
		cout << "1. Title" << endl;
		cout << "2. Author" << endl;
		cout << "3. ISBN" << endl;
		cout << "4. Price" << endl;
		cout << "5. Number of copies in stock" << endl;
		cout << "6. Display information for all books" << endl;
		cout << "7. Exit" << endl;

		cout << "Enter the number of your selection:";
		cin >> input;

		switch (input)
		{

		//search by title
		case 1:
		{
			system("cls");
			cout << "Enter the title of the book to search for: ";
			cin.ignore();
			getline(cin, query_title);
			for (int i = 0; i < SIZE; i++)
			{
				if (book_shelf[i].title_exists(query_title))
				{
					found = true;
					cout << endl;
					book_shelf[i].print_book();
					break;
				}
			}
			if (!found)
			{
				cout << "\n" << query_title << " not found." << endl;
				break;
			}
			break;
		}

		//search by author
		case 2:
		{
			system("cls");
			cout << "Enter the author of the book to search for: ";
			cin.ignore();
			getline(cin, query_author);
			for (int i = 0; i < SIZE; i++)
			{
				if (book_shelf[i].author_exists(query_author))
				{
					found = true;
					cout << endl;
					book_shelf[i].print_book();
					break;
				}
			}
			if (!found)
			{
				cout << "\n" << query_author << " not found." << endl;
				break;
			}
			break;
		}

		//search by isbn
		case 3:
		{
			system("cls");
			cout << "Enter the ISBN of the book to search for: ";
			cin.ignore();
			getline(cin, query_isbn);
			for (int i = 0; i < SIZE; i++)
			{
				if (book_shelf[i].isbn_exists(query_isbn))
				{
					found = true;
					cout << endl;
					book_shelf[i].print_book();
					break;
				}
			}
			if (!found)
			{
				cout << "\n" << query_isbn << " not found." << endl;
				break;
			}
			break;
		}

		//search by price
		case 4:
		{
			system("cls");
			cout << "Enter the price to display all books that cost less than that price: ";
			cin.ignore();
			cin >> query_price;
			for (int i = 0; i < SIZE; i++)
			{
				if (book_shelf[i].get_price() <= query_price)
				{
					found = true;
					cout << endl;
					book_shelf[i].print_book();
					cout << endl;
				}
			}
			if (!found)
			{
				cout << "No books found  $" << query_price << " or less available." << endl;
				break;
			}
			break;
		}

		//search by number of copies
		case 5:
		{
			system("cls");
			cout << "Enter the number of copies to display all books with more than that number of copies in stock: ";
			cin.ignore();
			cin >> query_num_copies;
			for (int i = 0; i < SIZE; i++)
			{
				if (book_shelf[i].get_num_copies() >= query_num_copies)
				{
					found = true;
					cout << endl;
					book_shelf[i].print_book();
					cout << endl;
				}
				
			}
			if (!found)
			{
				cout << "No books found with " << query_num_copies << " copies or more available." << endl;
				break;
			}
			break;
		}

		//displays all information about all of the books
		case 6:
		{
			for (int i = 0; i < SIZE; i++)
			{
				cout << endl;
				book_shelf[i].print_book();
				cout << endl;
			}

			break;
		}

		//exit
		case 7:
		{
			cout << "Exitting" << endl;
			return;
		}
		default:
			cout << "Invalid input. Please enter a correct option." << endl;
		}

	} while (input != 7);
}