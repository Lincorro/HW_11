#include <iostream>
#include <string>

bool corectSumbol(char  symbol) {// проверяем на запретные символы
	if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' || symbol >= '!' && symbol <= '/' || symbol >= '0' && symbol <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool corectSumbolRight(char  symbol) {//проверяем на запретные символы с правой стороны
	if (symbol >= '!' && symbol <= ',' || symbol == '/')
	{
		return false;
	}
	else
	{
		return true;
	}
}

int emailCheck() {
	std::string email;
	std::cout << "Input your email: ";
	std::cin >> email;
	bool corect = true;
	bool dog = false;
	int positionDog = 0;
	bool previousSymbolIsPoint = false;

	if (email[0] == '.' || email[(email.length() - 1)] == '.') // проверяем наличие точек в конце и начале
	{
		std::cout << "NO";
		return 1;
	}


	for (size_t i = 0; i < email.length(); i++)
	{
		if ( email[i] == '@' && !dog )
		{
			positionDog = i ;
			dog = true;

		}
		else if (email[i] == '@' && dog)
		{
			std::cout << "NO";
			return 1;
		}
		else
		{
			if (!corectSumbol(email[i])) {
				std::cout << "NO";
				return 1;
			}


		}
		if (positionDog != 0)
		{
			if (!corectSumbolRight(email[i])) {
				std::cout << "NO";
				return 1;
			}
		}

		if (email[i] == '.' && previousSymbolIsPoint) // проверка на точки идущие подряд
		{
			std::cout << "NO";
			return 1;
		}
		else if (email[i] == '.')
		{
			previousSymbolIsPoint = true;
		}
		else
		{
			previousSymbolIsPoint = false;
		}

	}
	if (positionDog < 1 || positionDog > 64 || (email.length() - positionDog) < 1 || (email.length() - positionDog) > 63) // проверяем длину правой и левой части
	{
		std::cout << "NO";
		return 1;
	}
	
	std::cout << "Yes";
	return 0;
}