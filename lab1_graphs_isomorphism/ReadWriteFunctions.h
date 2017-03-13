#pragma once

void FillBoolVectorFromLine(std::string & line, std::vector<bool> & vect, char ifTrue, char ifFalse);

template <typename T>
void PrintVectorToStream(const std::vector<T>& vect, std::ostream& strm)
{
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<size_t>(strm, " "));
	strm << std::endl;
}