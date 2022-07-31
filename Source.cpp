#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
#include <ctype.h>

typedef std::string string;

namespace GenerateName
{
	std::array<string, 10>FirstNames = { "Alex", "Brooklynn", "Cadyn", "Dan", "Eustice", "Finn", "Grace", "Henry", "Isaac", "Joshua" };
	std::array<string, 10>LastNames = { "Anzalone", "Peterson", "Rosenkrantz", "Beane", "Dapice", "Moura", "Grigoletto", "Philbert", "Dowling", "Taber" };


	namespace functions
	{
		string Name()
		{
			srand(time(NULL));
			string FirstName = FirstNames[rand() % 9 + 0];
			string LastName = LastNames[rand() % 9 + 0];
			string FullName = FirstName + " " + LastName;

			std::cout << "Your name is " << FullName << std::endl;
			std::cout << "Do you like this name? Y/N\n";

			string Input;
			std::cin >> Input;

			if (Input == "y" || Input == "Y") {
				std::cout << "Name chosen!\n";
				return FullName;
			}
			else if (Input == "n" || Input == "N") {
				std::cout << "Regenerating...\n";
				return Name();
			}
			else {
				std::cout << "Invalid Input: Auto defaulting to new username...";
				return Name();
			}
		}
	}
}

int main()
{
	using namespace GenerateName::functions;
	string FullName = Name();

	std::cout << "Hello " + FullName + "!" << std::endl;
}
