#include "classicMovie.h"



Classic::Classic()
{
}


Classic::~Classic()
{
}

Classic::Classic(string& ln, string& fn, string& t, string& dir, int mon, int yr, int cop)
{
	actorLastName = ln;
	actorFirstName = fn;
	m_director = dir;
	releaseYear = yr;
	m_copies = cop;
	m_title = t;
	month = mon;
	m_type = 'C';
}

bool Classic::operator<(const Classic & rhs) const
{
	// if lhs release year < rhs release year, return true
	if (releaseYear < rhs.releaseYear)
		return true;

	// if return years are equal
	if (releaseYear == rhs.releaseYear)
	{
		// check if the months are equal
		if (month < rhs.month)
			return true;
		// if the months are equal 
		if (month == rhs.month)
		{
			// check actor's last names, if lhs < rhs, return true
			if (actorLastName < rhs.actorLastName)
				return true;
		}
	}
	// return false 
	return false;
}
