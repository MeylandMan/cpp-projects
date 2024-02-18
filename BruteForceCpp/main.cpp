#include <iostream>
#include <string>

const char LettersNnumbers[36] =
{
	'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u',
	'v', 'w', 'x', 'y', 'z', '0', '1',
	'2', '3', '4', '5', '6', '7', '8',
	'9'
};

bool found = false;
std::string password;
std::string pwd;

void FindPassword(unsigned int length, std::string character)
{
	if (found == false) {
		std::cout << "Attempting to find the password... please wait... \n";

		if (length == 0)
		{
			std::cout << character << "\n";
			return;
		}

		for (unsigned int i = 0; i < 36; i++)
		{
			std::string NewPwd = character + LettersNnumbers[i];
			pwd = NewPwd;
			if (pwd == password) {
				found = true;
				i = 9999;
				std::cout << "Your password is : " << pwd << std::endl;
				return;
			}
			FindPassword(length - 1, NewPwd);
		}
	}
	
	
}


int main()
{
	std::cout << "Enter a password : ";
	std::cin >> password;

	while (found == false)
	{
		static unsigned int stringlength = 1;
		FindPassword(stringlength, "");
		stringlength++;
	}
	return 0;
}