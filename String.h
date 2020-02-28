#pragma once
#include <string>

class String
{
public:
	String() { string = NULL; size = 0; }
	String(const String &other) { copy(other); }
	String(const std::string &other) { copy(other); }
	String(const char *other) { copy(other); }
	~String() { delete string; }

	void operator=(const String &other) { delete string; copy(other); }
	void operator=(const std::string &other) { delete string; copy(other); }
	void operator=(const char *other) { delete string; copy(other); }
	
	String operator-=(const char *toDelete);
	String operator+(const String &other) { return concatenate(string, other.string, size, other.size); }
	String operator+(const std::string &other) { return concatenate(string, other.data(), size, other.size()); }
	friend String operator+(const char *charsToAdd, String &myStr) { return String::concatenate(charsToAdd, myStr.string, strlen(charsToAdd), myStr.size); }
	friend String operator+(String &myStr, const char*charsToAdd) { return String::concatenate(myStr.string, charsToAdd, myStr.size, strlen(charsToAdd)); }
	void operator+=(const String &other);
	void operator+=(const std::string &other);
	void operator+=(const char *other);
	operator bool() const { return size != 0; }

	std::string toStandard() { return std::string(string, size); }
	int getSize() { return size; }
private:
	String(int size) { string = new char[size]; this->size = size; }
	void copy(const String &other);
	void copy(const std::string &other);
	void copy(const char *other);
	static String concatenate(const char *current, const char *other, int currentSize, int otherSize);

	int size;
	char *string;
};
