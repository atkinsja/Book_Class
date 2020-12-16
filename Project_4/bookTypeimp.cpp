/*
	bookTypeimp.cpp
	Implementation for all of the functions of the bookType class
*/
#include <string>
#include <iostream>
#include "bookType.h"

using namespace std;

//default constructor 
bookType::bookType()
{
	title = "default_title";
	author = "default_author";
	isbn = "default_isbn";
	price = -1;
	num_copies = -1;
}

//getters
std::string bookType::get_title() const
{
	return title;
}

std::string bookType::get_author() const
{
	return author;
}

std::string bookType::get_isbn() const
{
	return isbn;
}

double bookType::get_price() const
{
	return price;
}

int bookType::get_num_copies() const
{
	return num_copies;
}

//setters
void bookType::set_title(std::string m_title)
{
	title = m_title;
}

void bookType::set_author(std::string m_author)
{
	author = m_author;
}

void bookType::set_isbn(std::string m_isbn)
{
	isbn = m_isbn;
}

void bookType::set_price(double m_price)
{
	price = m_price;
}

void bookType::set_num_copies(int m_num_copies)
{
	num_copies = m_num_copies;
}


//check whether a given value exists
bool bookType::title_exists(std::string possible_title) const
{
	if (possible_title == title)
		return true;
	else
		return false;
}
bool bookType::author_exists(std::string possible_author) const
{
	if (possible_author == author)
		return true;
	else
		return false;
}
bool bookType::isbn_exists(std::string possible_isbn) const
{
	if (possible_isbn == isbn)
		return true;
	else
		return false;
}
bool bookType::price_exists(double possible_price) const
{
	if (possible_price == price)
		return true;
	else
		return false;
}
bool bookType::num_copies_exists(int possible_num_copies) const
{
	if (possible_num_copies == num_copies)
		return true;
	else
		return false;
}

//displays the information about a book
void bookType::print_book() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Price: $" << price << endl;
	cout << "Number of copies: " << num_copies << endl;
}