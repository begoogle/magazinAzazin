#include "global.hpp"

//============ accounts ===============

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

//=====================================

//=========== official ================

std::unordered_set<char> spesialSymbols;
std::unordered_set<char> passSymbols;
bool isPassSetCreated = false;
bool isSetCreated = false;

//=====================================

//=============== Warehouse ===========

size_t storageSize = 0;
size_t maxItemSize = 299;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* countArr = nullptr;
bool isStorageCreate = false;

//=====================================

//============ Sale ===================

size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
unsigned int vinPhoneNum;
double* priceArrCheck;
double* totalPriceArrCheck;
bool discountPhone = false;
bool vinPhone = false;

double cashIncome = 0;
double bankIncome = 0.0;
double cash = 100000 + rand() % 100000;