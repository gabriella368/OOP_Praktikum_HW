#include <iostream>
#include "String.h"

int main()
{
	String string1;
    string1.setString("This is an example");

	string1.add('!');
	string1.getLength();
	string1.insertAt();
	string1.removeAt();

	return 0;
}