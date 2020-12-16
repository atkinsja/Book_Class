/*
	Header file for the bookType class
*/
#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include <string>
class bookType
{
public:
	//constructor
	bookType::bookType();

	//getters
	std::string bookType::get_title() const;
	std::string bookType::get_author() const;
	std::string bookType::get_isbn() const;
	double bookType::get_price() const;
	int bookType::get_num_copies() const;

	//setters
	void bookType::set_title(std::string);
	void bookType::set_author(std::string);
	void bookType::set_isbn(std::string);
	void bookType::set_price(double);
	void bookType::set_num_copies(int);

	//display
	void print_book() const;

	//checks for a given value
	bool bookType::title_exists(std::string) const;
	bool bookType::author_exists(std::string) const;
	bool bookType::isbn_exists(std::string) const;
	bool bookType::price_exists(double) const;
	bool bookType::num_copies_exists(int) const;
private:
	std::string title;
	std::string author;
	std::string isbn;
	double price;
	int num_copies;

};
#endif // !BOOKTYPE_H