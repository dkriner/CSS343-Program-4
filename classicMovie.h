#pragma once
#include "movie.h"

class Classic: public Movie
{
	//friend ostream& operator<<(ostream&, const Classic&);
public:
	Classic();
	~Classic();
	Classic(string&, string&, string&, string&, int, int, int);

	void print(ostream&);

	bool operator< (const Classic&) const;

private:
	string actorFirstName;
	string actorLastName;
	int month;
};

