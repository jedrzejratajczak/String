#include "String.h"
#include <iostream>

String String::operator-=(const char *toDelete)
{
	int *checker = new int[size];
	for (int i = 0; i < size; i++) checker[i] = 0;
	for (int startIndex = 0; startIndex < size; startIndex++)
	{
		int currIndex = startIndex;
		for (int i = 0; (currIndex < size) && (i < strlen(toDelete)); i++)
		{
			if (string[currIndex] == toDelete[i])
				checker[startIndex]++;
			currIndex++;
		}
	}
	int largestStringIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (checker[largestStringIndex] < checker[i]) largestStringIndex = i;
	}

	String resultStr;
	if(checker[largestStringIndex] == strlen(toDelete)) resultStr = String(size - checker[largestStringIndex]);
	else
	{
		delete checker;
		return *this;
	}

	int ii = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != largestStringIndex)
		{
			resultStr.string[ii] = string[i];
			ii++;
		}
		else if (i == largestStringIndex)
			i += checker[largestStringIndex] - 1;
	}

	copy(resultStr);
	delete checker;
	return resultStr;
}

void String::operator+=(const String &other)
{
	String myStr;
	myStr = *this + other;
	copy(myStr);
}

void String::operator+=(const std::string &other)
{
	String myStr;
	myStr = *this + other;
	copy(myStr);
}

void String::operator+=(const char *other)
{
	String myStr;
	myStr = *this + other;
	copy(myStr);
}

void String::copy(const String &other)
{
	size = other.size;
	string = new char[size];
	for (int i = 0; i < size; i++)
		string[i] = other.string[i];
}

void String::copy(const std::string &other)
{
	size = other.size();
	string = new char[size];
	for (int i = 0; i < size; i++)
		string[i] = other.at(i);
}

void String::copy(const char *other)
{
	size = strlen(other);
	string = new char[size];
	for (int i = 0; i < size; i++)
		string[i] = other[i];
}

String String::concatenate(const char *current, const char *other, int currentSize, int otherSize)
{
	String myStr(currentSize + otherSize);
	for (int i = 0; i < currentSize; i++)
		myStr.string[i] = current[i];
	for (int i = 0; i < otherSize; i++)
		myStr.string[currentSize + i] = other[i];
	return myStr;
}