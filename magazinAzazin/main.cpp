#include "include.hpp"
#include "include_all_hpp.hpp"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	delete[]salseArr;
	delete[]userIdArr;

	if (isStorageCreate)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}

	return 0;
}
