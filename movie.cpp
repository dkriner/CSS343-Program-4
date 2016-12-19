#include "movie.h"
#include <fstream>


Movie::Movie()
{
}

Movie::Movie(string dir, string title, int year, int num_copies)
{
	m_director = dir;
	m_title = title;
	releaseYear = year;
	m_copies = num_copies;
}


Movie::~Movie()
{
}

//bool Movie::operator<(const Movie& rhs) const
//{
//	// comedy < drama and comedy < classic
//	if (m_type == 'F' && (rhs.m_type == 'D' || rhs.m_type == 'C'))
//		return true;
//	// drama < classic
//	else if (m_type == 'D' && rhs.m_type == 'C')
//		return true;
//
//	// this means the types are equal or the left hand side is greater than the right hand side
//	return false;
//}

ostream& operator<<(ostream& out, const Movie& m)
{
	out << m.m_type << "  " << m.m_title << "  " << m.m_director << endl;
	return out;
}

void Movie::print() {

}
