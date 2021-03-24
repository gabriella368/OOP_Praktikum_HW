#include <iostream>
#include "String.h"

String::String() {
	this->size = 0;
	this->capacity = 10;
	this->string = new char[1];

}

void String::resize() {
	this->capacity *= 2;
	char* biggerString = new char[this->capacity];

	for (size_t i = 0; i < size; ++i)
	{
		biggerString[i] = this->string[i];
	}

	delete[] string;
	this->string = biggerString;
}

void String::copy(const String& other) {
	this->string = new char[strlen(other.string) + 1];
	this->size = other.size;
	this->capacity = other.capacity;

	for (size_t i = 0; i < size; ++i)
	{
		this->string[i] = other.string[i];
	}
}

String &String::operator=(const String& other_string) {
	if (this != &other_string) {
		this->erase();
		this->copy(other_string);
	}
	return *this;
}

void String::erase() {
	delete[] this->string;
}

void String::print() const {
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << this->string[i] << std::endl;
	}
}

void String::setString(const char* other_string) {
	strcpy_s(this->string, strlen(other_string) + 1, other_string);
}

void String::setSize(int other_size) {
	this->size = other_size;
}

void String::setCapacity(int other_capacity) {
	this->capacity = other_capacity;
}

static const char* getString(char* string){
	return string;
}

static int getSize(int size){
	return size;
}

static int getCapacity(int capacity) {
	return capacity;
}

void String::add(char lastElement) {
	if (size >= capacity) {
		this->resize();
	}

	this->string[size] = lastElement;
	size++;
}

void String::getLength(char* string) {
	std::cout << "The length of string is: " << strlen(string);
}

void String::insertAt(char* string, int index, char& symbol) {
	int length = strlen(string);
	
	std::cout << "Enter an index to add the element: ";
	std::cin >> index;
	std::cout << "Enter the symbol that you want to add: ";
	std::cin >> symbol;

	if (index > 0 && index <= length)
	{
		for (int i = length; i > index - 1; i--)
		{
			string[i] = string[i - 1];
		}
		string[index - 1] = symbol;
		string[length] = 0;
	}
	else
	{
		std::cout << "Invalid index!" << std::endl;
	}
	std::cout << string << std::endl;
}

void removeAt(char* string, int index) {
	int length = strlen(string);

	std::cout << "Enter the index of the symbol you want to remove: ";
	std::cin >> index;

	if (index > 0 && index <= length)
	{
		for (int i = index; i < length; ++i)
		{
			string[i] = string[i + 1];
		}
	}
	else
	{
		std::cout << "Invalid index!" << std::endl;
	}
	std::cout << string << std::endl;
}

void String::trimStart(char* string) {
	int length = strlen(string);

	for (int i = 0; i < length; ++i)
	{
		string[i] = string[i + 1];
	}
}

void String::trimEnd(char* string) {
	int length = strlen(string);

	string[length - 1] = '/0';
}