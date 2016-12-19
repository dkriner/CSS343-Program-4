#pragma once
#include "movie.h"
#include <vector>
class Customer
{
public:
	Customer();
	~Customer();
	Customer(string&, string&, int);

	void displayHistory();
	void print();
	bool borrow(Movie&);
	bool returnMovie(Movie&);

private:
	int id;
	string lastName;
	string firstName;
	vector<Movie> rentals;
	//vector<Movie> history;

};

