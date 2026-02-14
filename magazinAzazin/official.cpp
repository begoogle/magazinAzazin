#include "include_all_hpp.hpp"

void Start() {
	std::cout << "\n\n\n\t\t\t===| Добро пожаловать в технический магазин Azazin! |===\n\n\n";

	std::string choose;

	while (true)
	{
		if (Login())
		{
			system("cls");
			if (currentStatus == userStatus[0])
			{
				std::cout << "Выберите тип склада..\n1 - Готовый\n2 - Новый\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					if (isStorageCreate == false)
					{
						CreateStorage();
					}
					system("cls");
					SwohSuperAgminMenu();
					break;
				}
				else if (choose == "2")
				{
					if (isStorageCreate == false)
					{
						CreateNewStorage();
					}
					system("cls");
					SwohSuperAgminMenu();
					break;
				}
				else
				{
					Err();
				}
			}
			else if (currentStatus == userStatus[1])
			{
				if (isStorageCreate == false)
				{
					CreateStorage();
				}
				ShowAdminMenu();
			}
			else if (currentStatus == userStatus[2])
			{
				if (isStorageCreate == false)
				{
					CreateStorage();
				}
				ShowUserMenu();
			}
		}
		else if (currentStatus == userStatus[0] && currentStatus == userStatus[1])
		{
			system("cls");
			std::cout << "Прибыль за смену -> " << cashIncome + bankIncome;
			std::cout << "\n\n\nЗавершение работы\n";
			Sleep(2000);
			system("cls");
			break;
		}
	}
}

void SwohSuperAgminMenu() {
	system("cls");

	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Измнить цену\n";
		std::cout << "6 - Редактиривать склад\n";
		std::cout << "7 - Редактиривать персонал\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод -> ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChengePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUserAccounts();
		}
		else if (choose == "8")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout() == true)
			{
				break;
			}
			system("cls");
		}
		else
		{
			Err();
		}
	}
}

void SetSpesialSymbols() {
	for (char i = '0'; i <= '9'; i++)
	{
		spesialSymbols.insert(i);
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		spesialSymbols.insert(i);
	}

	for (char i = 'a'; i <= 'z'; i++)
	{
		spesialSymbols.insert(i);
	}
	isSetCreated = true;
}

void SetPassSymbols() {
	for (char i = '!'; i <= '&'; i++)
	{
		passSymbols.insert(i);
	}

	for (char i = '('; i <= '+'; i++)
	{
		passSymbols.insert(i);
	}

	for (char i = '.'; i <= '~'; i++)
	{
		passSymbols.insert(i);
	}
	isPassSetCreated = true;
}

void ShowIncome() {
	system("cls");
	std::cout << "Текущаф прибыль за смену:\n\n";
	std::cout << "Наличный счет -> " << cashIncome;
	std::cout << "Безналичный счет -> " << bankIncome;
	std::cout << "Итого -> " << cashIncome + bankIncome;
	std::cout << "Сумма ваших продаж -> " << salseArr[currentID] << "\n\n";

	system("pause");
	system("cls");
}

void ShowAdminMenu() {
	system("cls");

	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Редактиривать склад\n";
		std::cout << "6 - Редактиривать персонал\n";
		std::cout << "7 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод -> ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangeStorage();
		}
		else if (choose == "6")
		{
			ChangeUserAccounts();
		}
		else if (choose == "7")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout() == true)
			{
				break;
			}
			system("cls");
		}
		else
		{
			Err();
		}
	}
}

void ShowUserMenu()
{
	system("cls");

	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод -> ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "0")
		{
			if (Logout() == true)
			{
				break;
			}
			system("cls");
		}
		else
		{
			Err();
		}
	}
}

bool CheckPass(const std::string& str) {
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Ошибка длины пароля\n";
		Sleep(1500);
		return false;
	}

	int numCount = 0, sumCount = 0;

	std::unordered_set<char> specialPassSym{ '!', '@', '#', '%', '$', '^', '&', '*', '(', ')', '_', '-', '=',
	'+', '/', '?', '|', '\\', '\"', '\'', ',', '.', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']' };

	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Неккоретный ввод\n";
			Sleep(1500);
			return false;
		}

		if (std::isdigit(sym))
		{
			numCount++;
		}

		if (specialPassSym.count(sym))
		{
			sumCount++;
		}
	}

	if (numCount > 2 && sumCount > 2)
	{
		return true;
	}
	else
	{
		std::cout << "Минимум 3 символа и 3 цифры";
		return false;
	}
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

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Добро пожаловать, " << loginArr[i] << "\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentID = userIdArr[i];
				return true;
			}
		}
		Err();
	}
}

bool IsNumber(std::string& str) {
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Неккорекный ввод\n";
		std::cout << "Ошибка размера числа: от 1 до 9 символов включительно\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Неккорекный ввод\n";
			std::cout << "Ошибка размера числа: введенные данные не являются числом\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool CheckLogin(const std::string& str) {
	if (str.size() < 5 || str.size() >= 20)
	{
		std::cout << "Недопустимая длина логина! От 5 до 20\n";
		Sleep(1500);
		return false;
	}

	for (char sym : str)
	{
		if (!spesialSymbols.count(sym))
		{
			std::cout << "Неккоретный символ в логине!\n";
			Sleep(1500);
			return false;
		}
	}

	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "Имя уже занято!\n\n";
			Sleep(1500);
			return false;
		}
	}

	return true;
}

bool Logout() {
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "Для подтверждения выхода введите ваш пароль или \"exit\" для возрата -> ";
		Getline(choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentID - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err();
		}
	}
}

inline void Getline(std::string& str) {
	std::getline(std::cin, str, '\n');
}

void Err() {
	std::cout << "Неккоретный ввод!\n";
	Sleep(1500);
	system("cls");
}