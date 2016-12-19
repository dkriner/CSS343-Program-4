#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
Abstract class for creating movies that can be rented
CLASSIC (C), COMEDY (F), DRAMA (D)



NOTE: Virtual functions are commented out because they give errors



*/
class Movie
{

	 friend ostream& operator<<(ostream&, const Movie&);

public:
	Movie();
	Movie(string dir, string title, int year, int num_copies);
	~Movie();

	//virtual void print(ostream&) = 0;					
	//virtual bool operator<(const Movie&) const;
	void print();

	char getType()
	{
		return m_type;
	}

	string getDirector()
	{
		return m_director;
	}

	string getTitle()
	{
		return m_title;
	}


private:

protected:
	string m_director;
	string m_title;
	int releaseYear;
	int m_copies;
	char m_type;



	//need this?

	//enum category {
	//	classic, 
	//	drama,
	//	comedy
	//};
};

