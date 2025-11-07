#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

//======================учетные записи================

size_t userSize = 2;
std::string userStatus[3]{"Супер администратор", "Администратор", "Сотрудник"};
std::string* loginArr = new std::string[userSize]{"admin", "user"};
std::string* passArr = new std::string[userSize]{"admin123", "user123"};
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2]};
std::string currentStatus;

//====================================================

//======================Склад=========================

size_t storageSize = 10;
int* idArr = new int[storageSize];
std::string* nameArr = new std::string[storageSize] {};
double* priceArr = new double[storageSize];
unsigned int* count = new unsigned int[storageSize] {};

//====================================================

void Start();

bool Login();

void CreateStorage();

void Getline(std::string& str);

void Err();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr, passArr, statusArr;

	return 0;
}

void Getline(std::string &str) {
	std::getline(std::cin, str, '\n');
}

void Start() {
	std::cout << "\n\n\n\t\t\t===| Добро пожаловать в технический магазин Azazin! |===\n\n\n";

	std::string choose;

	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите тип склада..\n1 - Готовый\n2 - Новый\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					// готовый склад
					break;
				}
				else if (choose == "2")
				{
					// создание нового склада
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else if (currentStatus == userStatus[1])
		{
			// готовый склад
		}
		else if (currentStatus == userStatus[2])
		{
			// готовый склад
		}
	}
	else
	{
		system("cls");
		std::cout << "\n\n\nЗавершение работы\n";
		Sleep(2000);
		system("cls");
	}
}

void Err() {
	std::cout << "Неккоретный ввод!\n";
	Sleep(1500);
	system("cls");
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

void CreateStorage() {
	const size_t staticSize = 10;

	int id[staticSize]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string name[staticSize]
	{
		"PokoMacdonalds",
		"PokoRostics",
		"SamsugXSsamsa",
		"XXSPoko17",
		"iPhone28ULTRA",
		"GooglePXL",
		"GoogleHD",
		"CleshRoyle",
		"Brawlsung",
		"MagmaCUB"
	};
	double price[staticSize]
	{
		14500, 14550, 23900, 15000, 300000, 10000, 10100, 12040, 16250, 25090
	};
	unsigned int count[staticSize]{ 23, 24, 10, 30, 2, 15, 14, 26, 18, 8 };

}
