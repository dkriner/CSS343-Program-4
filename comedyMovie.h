#pragma once
#include "movie.h"
class Comedy : public Movie
{
	friend ostream& operator<<(ostream&, const Comedy&);
public:
	Comedy();
	~Comedy();
	Comedy(string&, string&, int, int);

	void print(ostream&);

	bool operator< (const Comedy&) const;
};

