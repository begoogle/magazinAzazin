#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

// учетные записи

size_t userSize = 2;
std::string userStatus[3]{"Супер администратор", "Администратор", "Сотрудник"};
std::string* loginArr = new std::string[userSize]{"admin", "user"};
std::string* passArr = new std::string[userSize]{"admin123", "user123"};
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2]};
std::string currentStatus;

void Start();

bool Login();

void Err();

void Getline();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	return 0;
}

void Start() {
	std::cout << "\n\n\n\t\t\t===| Добро пожаловать в технический магазин Azazin! |===\n\n\n";

	if (Login())
	{
		if (currentStatus == userStatus[0])
		{

		}
		else if (currentStatus == userStatus[1])
		{

		}
		else if (currentStatus == userStatus[2])
		{

		}
	}
}

void Err() {
	std::cout << "Неккоретный ввод!\n";
	Sleep(1500);
	Getline();
}


bool Login() {
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин -> ";
		Getline(login);
		std::cout << "Введите пароль -> ";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}

		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "Добро пожаловать, " << loginArr[0] << "\n\n";
			std::cout << "Ваш статус: " << statusArr[0] << "\n\n";
			currentStatus = statusArr[0];
			return true;
		}
		
		for (size_t i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Добро пожаловать, " << loginArr[i] << "\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();
	}
}

void Getline(std::string &str) {
	std::getline(std::cin, str, '\n');
}