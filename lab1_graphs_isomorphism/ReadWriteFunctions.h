#pragma once

bool IsValidArgumentsCount(int argumensCount, int expectedCount);

void FillBoolVectorFromLine(std::string & line, std::vector<bool> & vect, char ifTrue, char ifFalse);

template <typename Container, typename T>
void PrintVectorToStream(const std::vector<T>& vect, std::ostream& strm)
{
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<size_t>(strm, " "));
	strm << std::endl;
}

template <typename A, typename B>
std::ostream& operator <<(std::ostream& strm, const std::pair<A,B> pair)
{
	strm << pair.first << ":" << pair.second;
	return strm;
}

template <typename A, typename B>
void PrintMapToStream(const std::map<A, B>& map, std::ostream& strm)
{
	for (auto pair : map)
	{
		strm << pair << " ";
	}
	strm << std::endl;
}