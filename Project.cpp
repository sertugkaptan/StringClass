#include "Cstring.h"

int main()
{

	char string[] = "simon,says-hello.says";
	char strin[] = "says";
	char stri[] = "tells";
	Cstring s1(string);
	Cstring s2;

	//we copy entire s1 to s2
	s2.strcpy(s1);
	std::cout << s2 << std::endl;

	//we copy s1 until third character
	s2.strncpy(s1, 3);
	std::cout << s2 << std::endl;

	//we append the strings together
	s2.strcat(s1);
	std::cout << s2 << std::endl;
	
	// we append string to s2 until fourth character
	s2.strncat(s1, 4);
	std::cout << s2 << std::endl;

	//we copy strings and check if they are the same
	s2.strcpy(s1);
	std::cout << (s2.strcmp(s1)) << std::endl;

	//we append to the first string again
	s2.strcat(s1);
	//we check if they are the same until the fourth character
	std::cout << (s2.strncmp(s1, 4)) << std::endl;

	//we print the string after the first m
	std::cout << s2.strchr('m') << std::endl;

	//we print the string after the last m
	std::cout << s2.strrchr('m') << std::endl;

	//we print the string untill there are no more tokens
	char* tokenized = s1.strtok(true, "-.,");
	while (tokenized != NULL)
	{
		puts(tokenized);
		tokenized = s1.strtok(false, "-.,");
	}

	//we change the says with tells
	s2.strstr(strin, stri);
	s2.print();

	//we check if they are equal
	std::cout << (s2 == s1) << std::endl;

	//we check if they are not equal
	std::cout << (s2 != s1) << std::endl;
	
	//we assign s1 to s2 so they are equal
	s2 = s1;
	std::cout << s2 << std::endl;

	//we add s2 and s1 together and assign it to s2
	s2 += s1;
	std::cout << s2 << std::endl;

	s2 = "ahmet";
	s1 = "ali";

	// we check which if s2 comes earlier than s1
	std::cout << (s2 < s1) << std::endl;

	// we check which if s1 comes earlier than s1
	std::cout << (s2 > s1) << std::endl;

	// we check which if s2 comes earlier than s1
	std::cout << (s2 >= s1) << std::endl;

	// we check which if s2 comes earlier than s1
	std::cout << (s2 <= s1) << std::endl;
}