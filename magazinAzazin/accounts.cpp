#include "include_all_hpp.hpp"

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

				delete[]loginArrTemp;
				delete[]passArrTemp;
				delete[]statusArrTemp;
				delete[]salseArrTemp;
				delete[]userIDTemp;
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
		else if (currentStatus == userStatus[1])
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

						delete[]loginArrTemp;
						delete[]passArrTemp;
						delete[]statusArrTemp;
						delete[]salseArrTemp;
						delete[]userIDTemp;
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