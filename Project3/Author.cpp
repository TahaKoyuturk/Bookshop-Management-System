#include "Author.h"
void Author::setName(string n)
{
	name = n;
}

string Author::getName()
{
	return name;
}

void Author::setBirtday(string b)
{
	birtday = b;
}

string Author::getBirtday()
{
	return birtday;
}

Author::Author()
{
	name = "unknown";
	birtday = "unknown";
}

Author::~Author()
{
}
