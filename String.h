#pragma once
#include <iostream>

class String {
public:
	String();

	void setString(const char* other_string);
	void setSize(int other_size);
	void setCapacity(int other_capacity);

	const char* getString() const;
	int getSize() const;
	int getCapacity() const;

	void add(char lastElement);
	void getLength(char* string);
	void insertAt(char* string, int index, char& symbol);
	void removeAt(char* string, int index);
	void trimStart(char* string);
	void trimEnd(char* string);

	void print() const;
	String& operator=(const String& other_string);
	~String() = default;
	


private:
	char* string;
	size_t size;
	size_t capacity;

	void copy(const String& other);
	void erase();
	void resize();
};