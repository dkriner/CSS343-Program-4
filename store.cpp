#include "movie.h"
#include "customer.h"
#include "classicMovie.h"
#include "dramaMovie.h"
#include "comedyMovie.h"
#include "store.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
using namespace std;

Store::Store() {
	// size of inventory hash table
	inventory.resize(50);
}

Store::~Store() {
	customerBase.clear();
	inventory.clear();
}


//the idea is to parse each line from the file into pieces we can use as data to make the movie objects with (genre, num copies, director etc.)
//then stick them all straight into the constructors.
void Store::insertMovie(string& data) {
	vector<string> items;
	string delimiter = ", ";
	string delimiter2 = " ";
	string item;

	/*===============Movie Data Retrieval=============*/
	//Grab the first 4 pieces of Data because we know what they will be
	for(int i = 0; i < 4; i++){
		item = data.substr(0, data.find(delimiter));		//we grab the first set of data (the string up to the first ", "
		items.push_back(item);								//add it to the vector
		data.erase(0, item.length() + delimiter.length());			//erase what we just pulled out
	}


	//Now the next data could either be a year or an actor first name if the movie is a Classic
	//Either way, the delimiter is changed to " "
	//The only difference between the descriptions of movie genres is how many more pieces of data are left
	//so this loop works for all movie types
	while(data.length() > 0) {
		item = data.substr(0, data.find(delimiter2));		
		items.push_back(item);								
		data.erase(0, item.length() + delimiter2.length());			
	}

	char genre = items.front()[0];

	if (genre == 'C')
	{
		// put the items in the vector into their corresponding variables
		char* term;
		int copies = strtol(items[1].c_str(), &term, 10);
		string dir = items[2];
		string title = items[3];
		string firstName = items[4];
		string lastName = items[5];
		int year = strtol(items[7].c_str(), &term, 10);
		int month = strtol(items[6].c_str(), &term, 10);
		// get the hash index using the table size and title
		int hashIndex = getHash(inventory.size(), title);

		inventory[hashIndex].push_back(Classic(lastName, firstName, title, dir, month, year, copies));

	}
	else if (genre == 'D')
	{
		// put the items in the vector into corresponding variables
		char* term;
		int copies = strtol(items[1].c_str(), &term, 10);
		string dir = items[2];
		string title = items[3];
		int year = strtol(items[4].c_str(), &term, 10);
		// get the hash index for the movie
		int hashIndex = getHash(inventory.size(), title);

		inventory[hashIndex].push_back(Drama(dir, title, copies, year));
	}
	else if (genre == 'F')
	{
		// put the vector items in corresponding variables
		char* term;
		int copies = strtol(items[1].c_str(), &term, 10);
		string dir = items[2];
		string title = items[3];
		int year = strtol(items[4].c_str(), &term, 10);
		// get the hash index for the movie
		int hashIndex = getHash(inventory.size(), title);
		// place the movie inside of the chain
		inventory[hashIndex].push_back(Comedy(dir, title, copies, year));
	}
	else
	{
		cout << "Error inserting movie into inventory" << endl;
	}



}

// Provides a way to map the key to an index so we know what chain to put/retrive the movie,
// M is the size of the table, and the string of the title is used to determine which chain the movie
// is placed in. Chaining guarantees that movies with the same title will be in the same chain. When looking
// for a classic movie with a different lead actor, this makes it much simpler to find the movie.
int Store::getHash(int M, string title)
{
		int index = 0;
		// iterate through the title
		for (int i = 0; i < title.length(); i++)
		{
			// for each index in the string, convert to its integer counter part and add it to the index
			index += (int) title[i];
		}
		// divide the index (sum) by the size of the table to get the index to return
		index = index % M;
		// return the index
		return index;
		
}


void Store::insertCustomer(string& data) {
	vector<string> customerData;
	string delimiter = " ";
	string item;

	while (data.length() > 0) {
		item = data.substr(0, data.find(delimiter));
		customerData.push_back(item);
		data.erase(0, item.length() + delimiter.length());
	}
		/*
		customerData[0] = id
		customerData[1] = first name
		customerData[2] = last name
		*/
		string ln = customerData[1];
		string fn = customerData[2];
		char *term;
		int id = strtol(customerData[0].c_str(), &term, 10);
		customerBase.push_back(Customer(ln, fn, id));
}

void Store::printCustomers() {
	cout << "Customer List: " << endl;

	for (int i = 0; i < customerBase.size(); i++)
		customerBase[i].print();
	

}

void Store::printInventory() {
	cout << "Movie List: " << endl;

	// for each chain in the hash table
	for (int i = 0; i < inventory.size(); i++)
	{
		// check if the size is not equal to 0
		if (inventory[i].size() != 0)
		{
			// iterate through the whole chain
			for (int j = 0; j < inventory[i].size(); j++)
			{
				// ??
			}
		}
		// continue to the next chain
	}
}


