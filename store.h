#pragma once
class Store {
	

public:
	Store();
	~Store();

	void insertMovie(string&);
	void insertCustomer(string&);

	void printCustomers();
	void printInventory();
	// hash the movie based on the title
	int getHash(int M, string title);
	

private:
	vector< vector<Movie> > inventory;
	vector<Customer> customerBase;

};