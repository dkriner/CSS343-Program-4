#include "movie.h"
#include "customer.h"
#include "store.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>

void ProcessLine(string line, Store& store, int mode)
{
	// inserting movies
	if (mode == 0)
	{
		store.insertMovie(line);
	}
	// inserting customers
	else if (mode == 1)
	{
		store.insertCustomer(line);
	}
	// processing commands
	else
	{

	}
}

int main(int argc, char* argv[]) {
	
	Store movieStore;
	if (argc > 3)
	{
		
		for (int i = 0; i < 3; i++)
		{
			cout << "Reading file " << argv[i+1] << endl;
			ifstream infile;
			infile.open(argv[i+1], ifstream::in);
	
			string line;
			while (true)
			{
				getline(infile, line);
				ProcessLine(line, movieStore, i);
				if (line.empty() || infile.eof())
					break;
			}
			cout << "Closing file " << argv[i+1] << endl;
			infile.close();
			//movieStore.printInventory(); /* used for testing */

		}
		cout << "Done" << endl;
		return 0;
	}

	cout << "Missing input file" << endl;
	return -1;

}