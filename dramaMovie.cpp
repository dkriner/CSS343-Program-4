#include "dramaMovie.h"


Drama::Drama()
{
}

Drama::~Drama()
{
}

Drama::Drama(string& dir, string& t, int c, int yr) {
	m_director = dir;
	m_title = t;
	m_copies = c;
	releaseYear = yr;
	m_type = 'D';
}

bool Drama::operator<(const Drama& rhs) const
{
	if (m_director < rhs.m_director)
		return true;

	if (m_director == rhs.m_director)
	{
		if (m_title < rhs.m_title)
			return true;
	}

	return false;
}
