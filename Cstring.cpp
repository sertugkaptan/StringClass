#include "Cstring.h"

//default constructor
Cstring::Cstring()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
}

//parameterized constructor
Cstring::Cstring(char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
		size++;
	str = new char[size + 1];
	int j = 0;
	while (string[j] != '\0')
	{
		str[j] = string[j];
		j++;
	}
	str[j] = '\0';

}

//parametrized constructor
Cstring::Cstring(const char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
		size++;
	str = new char[size + 1];
	int j = 0;
	while (arr[j] != '\0')
	{
		str[j] = arr[j];
		j++;
	}
	str[j] = '\0';
}

Cstring::Cstring(Cstring& string)
{

	str = new char[string.strlen() + 1];
	int i = 0;
	while (string.str[i] != '\0')
	{
		str[i] = string.str[i];
		i++;
	}
}

//destructor
Cstring::~Cstring()
{
	
}

int Cstring::strlen()
{
	int strleng = 0;
	//iterates until the end
	for (int i = 0; str[i] != '\0'; i++)
		strleng++;
	//returns the size
	return strleng;
}

//does the same thing but for a constant character array
int Cstring::strlen(const char* arr)
{
	int strleng = 0;
	for (int i = 0; arr[i] != '\0'; i++)
		strleng++;
	return strleng;
}

Cstring& Cstring::strcpy(const char* arr)
{
	// allocate memory as big as the string size
	str = new char[strlen(arr) + 1];
	int j = 0;
	//iterate and copy the string until the end
	while (j < strlen(arr))
	{
		str[j] = arr[j];
		j++;
	}
	//add a null character at the end
	str[j] = '\0';

	return *this;
}

//does the same thing but for a Cstring
Cstring& Cstring::strcpy(Cstring& string)
{
	return this->strcpy(string.str);
}

Cstring& Cstring::strncpy(const char* arr, int dist)
{
	//allocate memory as big as the distance to be copied
	str = new char[dist + 1];
	int i = 0;
	//iterate and copy until the end
	while (i < dist)
	{
		str[i] = arr[i];
		i++;
	}
	//add a null character at the end
	str[i] = '\0';

	return *this;
}

//does the same thing but for a cstirng
Cstring& Cstring::strncpy(Cstring& string, int dist)
{
	return this -> strncpy(string.str, dist);
}

Cstring& Cstring::strcat(const char* string)
{
	int tempsize;
	//we check if the string is empty
	if (string == NULL)
		//if it is we make it only the size of our string
		tempsize = this->strlen();
	else
		//if it is not we add two string sizes together
		tempsize = (this->strlen() + strlen(string));
	//then we alocate memory as big as the size of both
	char* temp = new char[tempsize + 1];
	int i = 0;
	//we iterate until the end of our string
	while (i < this->strlen())
	{
		//alocate it it the temporary string
		temp[i] = this->str[i];
		i++;
	}

	int j = 0;
	//we start iterating until the end of the second string
	while (j < strlen(string))
	{
		//allocate the second string to our temporary as well
		temp[i] = string[j];
		i++;
		j++;
	}
	//add a null character at the end of the string
	temp[i] = '\0';
	// delete the old string
	delete(str);
	//make temp our new string
	str = temp;
	// return the object
	return *this;
}

//does the same thing but for a cstring
Cstring& Cstring::strcat(Cstring& string)
{
	return this->strcat(string.str);
}

Cstring& Cstring::strncat(const char* string, int dist)
{
	//allocate memory as big as the how far we are gonna copy and the size of our old memory
	char* temp = new char[this->strlen() + dist + 1];
	int i = 0;
	//length of our string
	int n = this->strlen();
	int j = 0;
	while (i < n)
	{
		//alocate it it the temporary string
		temp[i] = this->str[i];
		j++;
		i++;
	}

	i = 0;
	//iterate the distance to be coppied
	while (i < dist)
	{
		//allocate it to our string
		temp[j] = string[i];
		i++;
		j++;
	}
	// add a null character at the end
	temp[j] = '\0';
	str = temp;
	return *this;
}

// does the same but for a Cstring
Cstring& Cstring::strncat(Cstring& string, int dist)
{
	return this->strncat(string.str, dist);
}

bool Cstring::strcmp(const char* string)
{
	//compare the sizes of them both if not equal return
	if (this->strlen() != strlen(string))
		return false;
	//then check if there is any different character if there is strings are not equal
	for (int i = 0; i < strlen(string); i++)
		if (this->str[i] != string[i])
			return false;
	//if no problem found return true
	return true;
}

//does the same thing but for a Cstring
bool Cstring::strcmp(Cstring& string)
{
	return this->strcmp(string.str);
}

bool Cstring::strncmp(const char* string, int dist)
{
	//check if the distance is bigger than the string size
	if (dist > strlen(string))
	{
		std::cout << "Please enter a valid distance!!!" << std::endl;
		return 0;
	}
	//check if the distance is bigger than our string size
	else if (dist > strlen())
	{
		std::cout << "Please enter a valid distance!!!" << std::endl;
		return 0;
	}
	// check if there is a different letter
	for (int i = 0; i < dist; i++)
		if (this->str[i] != string[i])
			return false;
	return true;
}
//does the same thing but for a cstring
bool Cstring::strncmp(Cstring& string, int dist)
{
	return this->strncmp(string.str, dist);
}

Cstring& Cstring::strchr(char key)
{
	//finds the key character
	while (*str != key)
	{
		//iterates the pointer to the key character
		str++;
	}
	//returns the rest of the string
	return *this;
}

Cstring& Cstring::strrchr(char key)
{
	char* temp = str;
	while (*str != '\0')
	{
		if (*str == key)
			temp = str;
		str++;
	}
	str = temp;
	return *this;
}



// finds the tokens and breaks the string into parts
char* Cstring::strtok(bool create, const char* token)
{
	int strsize = strlen();
	//we create two temporary memory
	char* temp = new char[strsize + 1];
	char* temp2;
	int i = 0, j;
	static char* ptr;
	int flag;
	//we copy our string into a new temporary memory
	while (i < strsize)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	i = 0;

	// new str, new search
	if (create == true)
	{
		ptr = temp;
	}

	//goes until the end of string
	while (ptr[i] != '\0') 
	{
		flag = 1;
		//checks each letter with each token
		for (j = 0; token[j] != '\0'; j++)
		{
			//checks if it is token then stops checking the same letter
			if (ptr[i] == token[j])
			{
				flag = 0;
				break;
			}
		}
		//if a normal letter is found gets out of the loop
		if (flag)
		{
			break;
		}
		i++;
	}

	//if no token is found delete the temporary memory and return null
	if (ptr[i] == '\0')
	{
		delete(temp);
		return NULL;
	}

	//skips the token/tokens
	else
	{
		ptr += i;
	}

	// find next token
	flag = 0;
	while (ptr[i] != '\0')
	{
		//controls each letter with each token
		for (j = 0; token[j] != '\0'; j++)
		{
			if (ptr[i] == token[j])
			{
				ptr[i] = '\0';
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			break;
		}

		i++;
	}

	// record the start of our pointer
	temp2 = ptr;
	//iterate and skip the token
	ptr += i;

	//skip the token so we can start from token (index+1)
	if (flag)
	{
		ptr++;
	}
	return temp2;
}

char* Cstring::strtok(bool create, Cstring& token)
{
	return this->strtok(create, token.str);
}



Cstring& Cstring::strstr(const char* replace, const char* newstr)
{
	//checks whether the word wanted to be changed and the new word are same
	if (replace == newstr)
	{
		std::cout << "Please enter different strings" << std::endl;
		return *this;
	}
	int strsize = strlen(replace);
	int i = 0;
	int index;
	int flag;
	//iterates the string until the end
	while (str[i] != '\0')
	{
		//checks if string character is equal to the first character of the word
		if (str[i] == replace[0])
		{
			//checks if the word that was going to be changed are equal to each other
			//so we check if we found the right word
			for (int j = 0; j < strsize; j++)
			{
				if (str[i + j] != replace[j])
					flag = 0;
				else
					flag = 1;
			}
			//if they are equal it saves the index of the word 
			if (flag == 1)
			{
				index = i;
				break;
			}
		}
		i++;
	}
	//if word is not in the string it returns  and changes nothing
	if (flag == 0)
		return *this;
	//then we allocate memory as big as the string with the word in it
	int templen = this->strlen() - strlen(replace) + strlen(newstr) + 1;
	char* temp = new char[templen];
	int dex = 0;
	i = 0;
	//then it iterates until the end of the string
	while (dex < (templen - 1))
	{
		//checks if the index of the word is reached
		if (dex == index)
		{

			int j = 0;
			//we enter the new word
			while (j < strlen(newstr))
			{
				temp[dex] = newstr[j];
				j++;
				dex++;
			}
			//we add the number of character that was placed in there
			i += strlen(replace);
		}
		//we start entering the rest of the string
		temp[dex] = str[i];
		dex++;
		i++;
	}
	temp[dex] = '\0';
	//we point to the start of the temp
	str = temp;
	//then we use recursion to change the same words in the string
	if (flag == 1)
		strstr(replace, newstr);
	return *this;
}

Cstring& Cstring::strstr(Cstring& replace,Cstring& newstr)
{
	return this->strstr(replace.str, newstr.str);
}

std::ostream& operator<<(std::ostream& out, Cstring& right)
{
	int i = 0;
	while (i < right.strlen())
	{
		out << right.str[i];
		i++;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Cstring& right)
{
	int i = 0;
	while (i < right.strlen())
	{
		in >> right.str[i];
	}
	return in;
}

bool Cstring::operator==(Cstring& right)
{
	//compares two strings
	return strcmp(right);
}

bool Cstring::operator==(const char* arr)
{
	//compares two strings
	return strcmp(arr);
}

bool Cstring::operator!=(Cstring& right)
{
	//check is they are not equal
	return !(strcmp(right));
}

bool Cstring::operator!=(const char* right)
{
	//check is they are not equal
	return !(strcmp(right));
}

Cstring& Cstring::operator=(Cstring& right)
{
	//assigns the string to another string
	return strcpy(right);
}

Cstring& Cstring::operator=(const char* right)
{
	//assigns the string to another string
	return strcpy(right);
}

Cstring& Cstring::operator+(Cstring& right)
{
	//adds two strings to each other
	return this->strcat(right);
}

Cstring& Cstring::operator+(const char* right)
{
	//adds two strings to each other
	return this->strcat(right);
}

Cstring& Cstring::operator+=(Cstring& right)
{
	//adds a new string to our string
	this->strcat(right);
	return *this;
}

Cstring& Cstring::operator+=(const char* right)
{
	//adds a new string to our string
	this->strcat(right);
	return *this;
}

//checks if their size is smaller 
bool Cstring::operator<(Cstring& right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] < right.str[i])
			return false;
		else
			return true;

}

//checks if their size is smaller 
bool Cstring::operator<(const char* right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] < right[i])
			return false;
		else
			return true;
}

//checks if their size is smaller or equal
bool Cstring::operator<=(Cstring& right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] < right.str[i] || str[i] == right.str[i])
			return true;
		else
			return false;
}

//checks if their size is smaller or equal
bool Cstring::operator<=(const char* right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] < right[i] || str[i] == right[i])
			return true;
		else
			return false;
}

//checks if their size is bigger or equal
bool Cstring::operator>=(Cstring& right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] > right.str[i] || str[i] == right.str[i])
			return false;
		else
			return true;
}

//checks if their size is bigger or equal
bool Cstring::operator>=(const char* right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] > right[i] || str[i] == right[i])
			return false;
		else
			return true;
}

//checks if their size is bigger or not
bool Cstring::operator>(Cstring& right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] > right.str[i])
			return true;
		else
			return false;

}

//checks if their size is bigger or not
bool Cstring::operator>(const char* right)
{
	int i = 0;
	while (str[i] != '\0')
		if (str[i] > right[i])
			return true;
		else
			return false;

}

void Cstring::print()
{
	int i = 0;
	while (str[i] != '\0')
	{
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}