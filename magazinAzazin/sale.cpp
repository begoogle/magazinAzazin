#include "include_all_hpp.hpp"

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

			if (totalSum >= 50000)
			{
				DiscountCheckSum(totalSum);
			}

			if (discountPhone)
			{
				DiscountPhonePlus();
				Ticket(totalSum);
			}

			if (vinPhone)
			{
				CheckArrPushback();

				index++;
				idArrCheck[index] = idArr[vinPhoneNum];
				nameArrCheck[index] = nameArr[vinPhoneNum];
				priceArrCheck[index] = 0;
				countArrCheck[index] = 1;
				totalPriceArrCheck[index] = priceArr[vinPhoneNum];
				countArr[vinPhoneNum] -= 1;
				totalSum += 0;
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

		if (countArrCheck[index] >= 2)
		{
			discountPhone = true;
		}

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
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "\nИтого к оплате -> " << totalSum << "\n";
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

void DiscountCheckSum(double& sum) {
	std::cout << "Активирована скидка!\n\n";
	std::cout << "-20% при 50000 или более суммы чека\n\n";

	std::cout << sum << " ------> " << sum - (sum * 20 / 100) << "\n";

	sum = sum - (sum * 20 / 100);

	system("pause");
	system("cls");
}

void DiscountPhonePlus() {
	std::cout << "Активирована скидка!\n\n";
	std::cout << "Лотерейный билет в подарок при покупки от 2 телефонов!\n\n";

	system("pause");
	system("cls");
}

void Ticket(double& sum) {
	char arr[9];
	int ticket[9];
	int sumPlus = 0;
	std::string choose;

	for (size_t i = 0; i < 9; i++)
	{
		arr[i] = '#';
		ticket[i] = rand() % 2;
	}

	std::cout << "Что можно выиграть:\n1) Скидку (в зависимости от плюсов, каждый плюс дает 5% скидки)\n2) Телефон (нужно выбить 3 плюса)";

	system("pause");
	system("cls");

	for (size_t i = 0; i < 3; i++)
	{
		int cell = 0;
		for (size_t i = 0, j = 1; i < 9; i++, j++)
		{
			std::cout << i + 1 << " " << arr[i] << " "; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ДЛЯ ПРОВЕРКИ РАБОТЫ ВЫИГРАША ТЕЛЕФОНА ПОМЕНЯТЬ "i + 1" НА "ticket[i]" !!!!!!!!!!!!!!!!!!!!!!
			if (j == 3)
			{
				std::cout << "\n";
				j = 0;
			}
		}

		std::cout << "Введите номер ячейки " << "попытка (" << i + 1 << ")" << " -> ";
		Getline(choose);

		if (IsNumber(choose))
		{
			cell = std::stoi(choose);

			if (cell < 1 || cell > 9)
			{
				Err();
				continue;
			}
		}
		else
		{
			continue;
		}

		if (ticket[cell - 1] == 0)
		{
			arr[cell - 1] = '-';
		}
		else
		{
			arr[cell - 1] = '+';
			sumPlus++;
		}

		system("cls");
	}

	std::cout << "Итог:\n";

	for (size_t i = 0, j = 1; i < 9; i++, j++)
	{
		std::cout << i + 1 << " " << arr[i] << " ";
		if (j == 3)
		{
			std::cout << "\n";
			j = 0;
		}
	}

	std::cout << "Собрано плюсов -> " << sumPlus << "\n";
	std::cout << "Выиграна скидка:\n";

	std::cout << sum << " ------> " << sum - (sum * (sumPlus * 5) / 100) << "\n\n";

	sum = sum - (sum * (sumPlus * 5) / 100);

	if (sumPlus > 2)
	{
		vinPhoneNum = rand() % 10;
		std::cout << "Вы выиграли телефон " << nameArr[vinPhoneNum] << " !\n";

		vinPhone = true;
	}

	system("pause");
	system("cls");
}
