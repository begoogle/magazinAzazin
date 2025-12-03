#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>

//================= Учетные записи ================

size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin123", "user123" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* salseArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
unsigned int currentID = 0;
std::string currentStatus;

void ChangeUserAccounts();
void ShowUsers(int mode = 0);
void AddNewUser();
void ChangePass();
void DeleteUser();

//====================================================

//====================== Склад =========================

size_t storageSize = 0;
size_t maxItemSize = 299;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* countArr = nullptr;
bool isStorageCreate = false;

void CreateStorage();
void CreateNewStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChengePrice();

void ChangeStorage();
void AddNewItem();
void ChengeName();
void DeleteItem();

//=====================================================

//===================== Служебные ======================

std::unordered_set<char> spesialSymbols;
std::unordered_set<char> passSymbols;
bool isPassSetCreated = false;
bool isSetCreated = false;

void Start();
void CreateStorage();
void Getline(std::string& str);
void SwohSuperAgminMenu();
void SetSpesialSymbols();
void SetPassSymbols();
void ShowIncome();
void ShowAdminMenu();
void ShowUserMenu();
bool CheckPass(const std::string& str);
bool Login();
bool IsNumber(std::string& str);
bool CheckLogin(const std::string& str);
bool Logout();
inline void Getline(std::string& str);
inline void Err();

//======================================================

//====================== Продажа =======================

size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cashIncome = 0;
double bankIncome = 0.0;
double cash = 100000 + rand() % 100000;

void Selling();
void CheckArrPushback();
void PrintCheck(double& totalSum);
void StorageReturner();

//======================================================

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr, passArr, statusArr, salseArr, userIdArr;

	if (isStorageCreate)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}

	return 0;
}

template<typename ArrType>
void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize) {
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArr[i] = staticArr[i];
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

void Getline(std::string& str) {
	std::getline(std::cin, str, '\n');
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

void Err() {
	std::cout << "Неккоретный ввод!\n";
	Sleep(1500);
	system("cls");
}

void Selling() {
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0, index = -1;
	double money = 0.0, totalSum = 0.0;
	bool isFirst = false;
	checkSize = 0;

	while (true)
	{
		ShowStorage();

		std::cout << "\nВведите ID товара для покупки или \"exit\" завершения покупок -> ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			system("cls");

			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				system("cls");
				break;
			}

			PrintCheck(totalSum);

			std::cout << "\nПодтвердить покупку?\n1 - Да\t2 - Нет\t3 - Отмена\nВвод -> ";
			Getline(choose);

			if (choose == "1")
			{
				while (true)
				{
					system("cls");

					std::cout << "Выберите способ оплаты\n1 - Наличными\t2 - Безнал\nВвод -> ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "введите кол-во наличных -> ";
						Getline(chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stod(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Недостаточно денег!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "Нет возможности дать сдачи. Повторите попытку!\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши -> " << money << "\n";
								Sleep(1500);
								std::cout << "Оплата успешно. Сдача -> " << money - totalSum << "рублей\n";
								Sleep(1500);
								cash += totalSum;
								cash -= money - totalSum;
								cashIncome += totalSum;
								salseArr[currentID] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						std::cout << "Приложите карту\n\n";
						Sleep(1500);
						if (rand() % 10 + 1 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(500);
							}
							std::cout << "\nСоеденение не установленл. Повторите попытку\n";
							Sleep(1500);
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(500);
							}
							std::cout << "\nОплата прошла успешно!\nСпасиба за покупку!\n";
							bankIncome += totalSum;
							salseArr[currentID] += totalSum;
							Sleep(1500);
							break;
						}
					}
					else if (choose == "begoogle")
					{
						std::cout << "Спасиба за покупку!\n";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
						continue;
					}
				}
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";
				StorageReturner();
				Sleep(1500);
				system("cls");
				return;
			}
			else
			{
				Err();
				continue;
			}

			delete[]idArrCheck;
			delete[]nameArrCheck;
			delete[]countArrCheck;
			delete[]priceArrCheck;
			delete[]totalPriceArrCheck;

			idArrCheck = nullptr;
			nameArrCheck = nullptr;
			countArrCheck = nullptr;
			priceArrCheck = nullptr;
			totalPriceArrCheck = nullptr;

			system("cls");

			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара -> ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки товара -> " << nameArr[id] << "\n\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count < 1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва! Максимум: " << countArr[id] << "\n\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		CheckArrPushback();

		if (isFirst == false)
		{
			isFirst = true;
		}

		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар успешно добавлен в чек!\n\n";

		Sleep(1500);
	}
}

void CheckArrPushback() {
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	FillArr(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArr(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[]idArrCheckTemp;
	delete[]nameArrCheckTemp;
	delete[]countArrCheckTemp;
	delete[]priceArrCheckTemp;
	delete[]totalPriceArrCheckTemp;
}

void PrintCheck(double& totalSum) {
	std::cout << "№\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена за ед\t" << "Кол - во\t" << "Итого\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "\nИтого к оплате -> " << totalSum << "\n\n";
}

void StorageReturner() {
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}

	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[]countArrCheck;
	delete[]priceArrCheck;
	delete[]totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;

	checkSize = 0;
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

void ChangeUserAccounts() {
	std::string choose;
	if (isSetCreated == false)
	{
		SetSpesialSymbols();
	}
	if (isPassSetCreated == false)
	{
		SetPassSymbols();
	}

	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователю\n";
		std::cout << "4 - Удаление учетной записи\n";
		std::cout << "0 - Выход из редактора аккунтов\n";
		std::cout << "Ввод -> ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewUser();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			if (userSize < 1)
			{
				std::cout << "Нет доступных пользователей\n";
			}
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}
}

void ShowUsers(int mode) {
	if (mode == 0)
	{
		system("cls");
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";

		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";

		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
		Sleep(2000);
	}
}

void AddNewUser() {
	std::string newLogin, newPass, newRole, choose;
	bool exit = true;

	while (exit)
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите логин нового пользователя или \"exit\" для выхода -> ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Отмена добавления нового пользователя!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы: a-z, A-Z, 0-9\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls"); 
			std::cout << "Введите пароль нового пользователя или \"exit\" для выхода -> ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Отмена добавления нового пользователя!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы: a-z, A-Z, 0-9 + символы\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Выберите роль для нового пользователя или \"exit\" для выхода:\n";
			std::cout << "1 - Администратор\n2 - Сотрудник\nВвод -> ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "Отмена добавления нового пользователя!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}

		}

		while (exit)
		{
			system("cls");
			std::cout << "Пользователь -> " << newLogin << "\n";
			std::cout << "Пароль -> " << newPass << "\n";
			std::cout << "Роль -> " << newRole << "\n";

			std::cout << "Подтвердить?\n1 - Да\t2 - Нет\nВвод -> ";
			Getline(choose);
			if (choose == "1")
			{
				userSize++;
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				double* salseArrTemp = new double[userSize];
				unsigned int* userIDTemp = new unsigned int[userSize];

				FillArr(loginArrTemp, loginArr, userSize - 1);
				FillArr(passArrTemp, passArr, userSize - 1);
				FillArr(statusArrTemp, statusArr, userSize - 1);
				FillArr(salseArrTemp, salseArr, userSize - 1);
				FillArr(userIDTemp, userIdArr, userSize - 1);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				salseArrTemp[userSize - 1] = 0.0;
				userIDTemp[userSize - 1] = userSize;

				std::swap(loginArrTemp, loginArr);
				std::swap(passArrTemp, passArr);
				std::swap(statusArrTemp, statusArr);
				std::swap(salseArrTemp, salseArr);
				std::swap(userIDTemp, userIdArr);

				delete[]loginArrTemp, passArrTemp, statusArrTemp, salseArrTemp, userIDTemp;
				std::cout << "Идет подготовка...";
				Sleep(1500);
				std::cout << "Пользователь успешно добавлен!";
				exit = false;
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
	}
}

void ChangePass() {
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	int isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		system("cls"); std::cout << "Выберите номер пользователя или \"exit\" для выхода -> ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена изменения пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1])
			{
				std::cout << "Нельяз менять пароль администраторам\n";
				Sleep(1500);
				break;
			}

			for (size_t i = isAdmin; i < userSize; i++)
			{
				if (i == userNumber)
				{
					system("cls");
					std::cout << "Введите новый пароль для пользвоателя -> " << loginArr[i] << " -> ";
					Getline(newPass1);
					std::cout << "Подтвердить пароль для пользваотеля " << loginArr[i] << " -> ";
					Getline(newPass2);
					if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
					{
						passArr[i] = newPass1;
						std::cout << "Успешно\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Повторите попытку\n";
						Sleep(1500);
						i--;
					}
				}
			}
		}
		else
		{
			Err();
		}
	}
}

void DeleteUser() {
	std::string chooseId, choose, checkPass;
	int userNumber = 0;
	int isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			if (userSize < 2)
			{
				std::cout << "Нет доступных пользователей для удаления\n";
				Sleep(1500);
				break;
			}
			ShowUsers();
			isAdmin = 1;
		}
		else if(currentStatus == userStatus[1])
		{
			if (staffCount < 1)
			{
				std::cout << "Нет доступных пользователей для удаления\n";
				Sleep(1500);
				break;
			}
		}
		ShowUsers();
		isAdmin = 1;
		std::cout << "Введите номер пользвоателя для удаления -> ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена изменения пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
			}
			for (size_t i = isAdmin; i < userSize; i++)
			{
				if (i == userNumber)
				{
					system("cls");

					if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
					{
						std::cout << "Нельзя удалять администраторов\n";
						Sleep(1500);
						break;
					}

					std::cout << "Удаление пользователя -> " << loginArr[i] << "\n\n";
					std::cout << "Для потдверждения введите пароль супер администратора или \"exit\" для выхода ->";
					Getline(checkPass);
					if (checkPass == "exit")
					{
						std::cout << "Отмена удаления пользователя -> " << loginArr[i] << "\n\n";
						Sleep(1500);
						break;
					}
					else if (checkPass == passArr[0])
					{
						userSize--;
						if (statusArr[userNumber] == userStatus[2])
						{
							staffCount--;
						}
						std::string* loginArrTemp = new std::string[userSize];
						std::string* passArrTemp = new std::string[userSize];
						std::string* statusArrTemp = new std::string[userSize];
						double* salseArrTemp = new double[userSize];
						unsigned int* userIDTemp = new unsigned int[userSize];

						for (size_t i = 0, c = 0; i < userSize; i++, c++)
						{
							if (userNumber == c)
							{
								c++;
							}
							loginArrTemp[i] = loginArr[c];
							passArrTemp[i] = passArr[c];
							statusArrTemp[i] = statusArr[c];
							salseArrTemp[i] = salseArr[c];
							userIDTemp[i] = userIdArr[c];
						}

						std::swap(loginArrTemp, loginArr);
						std::swap(passArrTemp, passArr);
						std::swap(statusArrTemp, statusArr);
						std::swap(salseArrTemp, salseArr);
						std::swap(userIDTemp, userIdArr);

						delete[]loginArrTemp, passArrTemp, statusArrTemp, salseArrTemp, userIDTemp;
						std::cout << "Идет подготовка...";
						Sleep(1500);
						std::cout << "Пользователь успешно удален!";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Неккоретный пароль\n";
						Sleep(1500);
						i--;
					}
				}
			}
		}
		else
		{
			Err();
		}
	}
}

void CreateStorage() {
	const size_t staticSize = 10;

	unsigned int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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

	if (isStorageCreate)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreate = true;

	FillArr(idArr, id, storageSize);
	FillArr(nameArr, name, storageSize);
	FillArr(countArr, count, storageSize);
	FillArr(priceArr, price, storageSize);

}

void CreateNewStorage() {
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

void ShowStorage(int mode) {
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\n.";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
	}

	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
	}
}

void AddStorageItem() {
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода -> ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена перации пополнения склада!\n";
			Sleep(1500);
			system("cls");
			break;
		}

		std::cout << "Введите кол-во товара для пополнения -> ";
		Getline(chooseCount);


		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > maxItemSize)
			{
				std::cout << "Неккоретный ID или кол-во\nМаксвимальное кол-во - " << maxItemSize;
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " -----> " << countArr[id] + count << "\n\n";
				std::cout << "Подтверить?\n Да - 1\t Нет - 2\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно поплнен!\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void RemoveStorageItem() {
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода -> ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена перации списания склада!\n";
			Sleep(1500);
			system("cls");
			break;
		}

		std::cout << "Введите кол-во товара для списания -> ";
		Getline(chooseCount);


		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Неккоретный ID или кол-во\nМаксвимальное кол-во - " << maxItemSize;
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " -----> " << countArr[id] - count << "\n\n";
				std::cout << "Подтверить?\n Да - 1\t Нет - 2\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списанан!\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChengePrice() {
	std::string chooseId, choosePrice, choose;
	unsigned int id = 0;
	double newPrice;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода -> ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена перации изменения цены!\n";
			Sleep(1500);
			system("cls");
			break;
		}

		std::cout << "Введите новую цену для товара -> ";
		Getline(choosePrice);


		if (IsNumber(chooseId) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseId) - 1;
			newPrice = std::stod(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0 || newPrice > 499999)
			{
				std::cout << "Неккоретный ID или цена\nМаксвимальное цена - " << 499999;
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << priceArr[id] << " -----> " << newPrice << "\n\n";
				std::cout << "Подтверить?\n Да - 1\t Нет - 2\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = newPrice;
					std::cout << "Цена успешно изменена!\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorage() {
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить новый товар\n";
		std::cout << "2 - Изменить название товара\n";
		std::cout << "3 - Удалить товар\n";
		std::cout << "0 - Выход из редактора склада\n";
		std::cout << "Ввод -> ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ChengeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}
}

void AddNewItem() {
	std::string newName, newPrice, newCount, choose;
	double price = 0.0, count = 0.0;
	bool exit = true;


	while (true)
	{
		while (true)
		{
			system("cls");

			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращении операции\n\n";

			std::cout << "Введите название нового товара -> ";

			Getline(newName);

			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}

			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Ошибка: Максимальная длина названия 60 символов\n";
				Sleep(1500);
				system("cls");
			}
			else
			{
				break;
			}
		}

		while (exit)
		{
			std::cout << "Введите кол-во нового товара -> ";
			Getline(newCount);

			if (newCount == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > maxItemSize)
				{
					std::cout << "Ошибка максимального размера товаара! Не более " << maxItemSize << " ед.\n\n";
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			std::cout << "Введите цену нового товара -> ";
			Getline(newPrice);

			if (newPrice == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newPrice))
			{
				price = std::stoi(newPrice);
				if (price > 499999)
				{
					std::cout << "Ошибка максимального размера цены товаара! Не более " << 499999 << " ед.\n\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}

		}

		system("cls");

		if (exit)
		{
			std::cout << "Новый товар: " << newName << "\nКол-во: " << newCount << "\nЦена: " << price << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\t2 - Нет\nВвод -> ";
			Getline(choose);

			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				FillArr(idArrTemp, idArr, storageSize - 1);
				FillArr(nameArrTemp, nameArr, storageSize - 1);
				FillArr(countArrTemp, countArr, storageSize - 1);
				FillArr(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				priceArrTemp[storageSize - 1] = price;
				countArrTemp[storageSize - 1] = count;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp, nameArrTemp, priceArrTemp, countArrTemp;
				std::cout << "Идет подготовка...";
				Sleep(2000);
				std::cout << "Товар успешно добавлен!\n\n";
				Sleep(1500);
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}

		if (!exit == false)
		{
			break;
		}
	}
}

void ChengeName() {
	std::string newName, choose, chooseId;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "Введите ID товара или \"exit\" для выхода -> ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Операция смены названия прервана!\n\n";
			Sleep(1500);
			break;
		}

		std::cout << "Введите название нового товара -> ";
		Getline(newName);

		if (newName.size() <= 0 || newName.size() >= 60 || newName == "exit")
		{
			std::cout << "Ошибка: Максимальная длина названия 60 символов\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << newName[id] << " -----> " << newName << "\n\n";
				std::cout << "Подтверить?\n Да - 1\t Нет - 2\nВвод -> ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Изменение названия успешно завершено\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void DeleteItem() {
	std::string chooseId, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаление или \"exit\" для выхода";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Операция удаления товара прервана!\n\n";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Удаляемый товар -> " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\t2 - Нет\nВвод -> ";
				Getline(choose);

				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];

					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, priceArrTemp, countArrTemp;
					std::cout << "Идет подготовка...";
					Sleep(2000);
					std::cout << "Товар успешно удален!\n\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена удаления товара!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
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