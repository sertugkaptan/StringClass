#pragma once
#include<iostream>
#include<cstring>
#ifndef CSTRING_H
#define CSTRING_H

class Cstring
{
	friend std::ostream& operator<<(std::ostream&, Cstring&);
	friend std::istream& operator>>(std::istream&, Cstring&);
public:
	//defauult constructor
	Cstring();
	//prameterized constructor
	Cstring(char*);
	Cstring(const char*);
	//copy constructor
	Cstring(Cstring&);
	//destructor
	~Cstring();

	//finds the length of the string
	int strlen();
	int strlen(const char*);

	//copies the first string to the second one
	Cstring& strcpy(Cstring&);
	Cstring& strcpy(const char*);
 
	//coppies the string until the number n
	Cstring& strncpy(Cstring& , int);
	Cstring& strncpy(const char* , int);

	//Appends the string to the first one
	Cstring& strcat(Cstring&);
	Cstring& strcat(const char*);

	//Appends the second string to first one
	Cstring& strncat(Cstring& ,int);
	Cstring& strncat(const char*, int);

	//Compares two strings
	bool strcmp(Cstring&);
	bool strcmp(const char*);

	//Compares two strings up to the integer
	bool strncmp(Cstring&,int);
	bool strncmp(const char*, int);

	//Searches for the character in the string and returns the rest
	Cstring& strchr(char);

	//searches for the last character and returns the rest
	Cstring& strrchr(char);

	//finds the key character and breaks the string
	char* strtok(bool, Cstring&);
	char* strtok(bool, const char*);

	//finds the substring of the object
	Cstring& strstr(Cstring&,Cstring&);
	Cstring& strstr(const char*, const char*);
	
	//prints the string in the object
	void print();
	
	//adds 2 strings together
	Cstring& operator+(Cstring&);
	Cstring& operator+(const char*);

	//checks if they are equal
	bool operator==(Cstring&);
	bool operator==(const char*);

	//checks if they are not equal
	bool operator!=(Cstring&);
	bool operator!=(const char*);

	//sets a string to another string
	Cstring& operator=(Cstring&);
	Cstring& operator=(const char*);

	// adds a new string to a string
	Cstring& operator+=(Cstring&);
	Cstring& operator+=(const char*);

	//we compare which comes first in all greater or least operators
	bool operator<(Cstring&);
	bool operator<(const char*);

	bool operator>(Cstring&);
	bool operator>(const char*);

	bool operator<=(Cstring&);
	bool operator<=(const char*);

	bool operator>=(Cstring&);
	bool operator>=(const char*);

private:
	int size;
	char* str;

};

#endif // !CSTRING_H