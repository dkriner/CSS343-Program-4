#pragma once
#include "movie.h"
class Drama : public Movie
{
	friend ostream& operator<<(ostream&, const Drama&);
public:
	Drama();
	~Drama();
	Drama(string&, string&, int, int);

	void print(ostream&);

	bool operator< (const Drama&) const;
};

