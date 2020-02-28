#include "String.h"
#include <iostream>

int main()
{
	String str;
	str = "ma ";
	str += "kota ";
	str = str + "i psa";
	str = "ala " + str;
	std::cout << str.toStandard() << '\n';

	str -= "maa";
	std::cout << str.toStandard();
}