#include "stdafx.h"
#include "ReadWriteFunctions.h"

using namespace std;

void FillBoolVectorFromLine(std::string & line, std::vector<bool> & vect, char ifTrue, char ifFalse)
{
	stringstream stream;
	stream << line;
	char elem;
	while (stream >> elem)
	{
		vect.push_back(elem == ifTrue);
	}
}