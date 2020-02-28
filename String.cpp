#include "String.h"
#include <iostream>

String String::operator-=(const char* substrToDelete)
{
	int substrFound;
	int startIndex = 0;
	do
	{
		substrFound = 0;
		int currIndex = startIndex;
		for (int i = 0; (currIndex < size) && (i < strlen(substrToDelete)); i++)
		{
			if (string[currIndex++] == substrToDelete[i])
				substrFound++;
		}
		startIndex++;
	} while (substrFound < strlen(substrToDelete) && startIndex < size);
	startIndex--;

	String resultStr;
	if (substrFound == strlen(substrToDelete)) resultStr = String(size - strlen(substrToDelete));
	else return;

	int ii = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != startIndex)
		{
			resultStr.string[ii] = string[i];
			ii++;
		}
		else if (i == startIndex)
			i += strlen(substrToDelete) - 1;
	}

	copy(resultStr);
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
