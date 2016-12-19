#include "comedyMovie.h"

Comedy::Comedy()
{
}

Comedy::~Comedy()
{
}

Comedy::Comedy(string& dir, string& t, int c, int yr) {
	m_title = t;
	m_copies = c;
	m_director = dir;
	releaseYear = yr;
	m_type = 'F';
}

bool Comedy::operator<(const Comedy &rhs) const
{
	// sort by title first

	// if lhs < rhs, return true
	if (m_title < rhs.m_title)
		return true;

	// if titles are equal
	if (m_title == rhs.m_title)
	{
		// if release year if lhs < rhs release year, return true
		if (releaseYear < rhs.releaseYear)
			return true;
	}
	// either the title is greater
	// or they have the same title, and the same release year, or lhs has a greater release year
	// either way, return false
	return false;
}
