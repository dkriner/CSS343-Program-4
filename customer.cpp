#include "customer.h"
#include <iostream>
#include <string>


Customer::Customer()
{
}


Customer::~Customer()
{
}

Customer::Customer(string&last, string& first, int i) {
	lastName = last;
	firstName = first;
	id = i;
}

void Customer::print() {
	cout << id << " " << firstName << " " << lastName << endl;
}
