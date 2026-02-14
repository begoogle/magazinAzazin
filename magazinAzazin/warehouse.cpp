#include "include_all_hpp.hpp"

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

				delete[]idArrTemp;
				delete[]nameArrTemp;
				delete[]priceArrTemp;
				delete[]countArrTemp;
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

					delete[]idArrTemp;
					delete[]nameArrTemp;
					delete[]priceArrTemp;
					delete[]countArrTemp;
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
