#pragma once

#ifndef _QWERTY_HPP_
#define _QWERTY_HPP_
#include "include.hpp"

//============ accounts ===============

extern size_t userSize;
extern size_t staffCount;
extern std::string userStatus[3];
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;
extern double* salseArr;
extern unsigned int* userIdArr;
extern unsigned int currentID;
extern std::string currentStatus;

//=====================================

//=========== official ================

extern std::unordered_set<char> spesialSymbols;
extern std::unordered_set<char> passSymbols;
extern bool isPassSetCreated;
extern bool isSetCreated;

//=====================================

//=============== Warehouse ===========

extern size_t storageSize;
extern size_t maxItemSize;
extern unsigned int* idArr;
extern std::string* nameArr;
extern double* priceArr;
extern unsigned int* countArr;
extern bool isStorageCreate;

//=====================================

//============ Sale ===================

extern size_t checkSize;
extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern unsigned int vinPhoneNum;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern bool discountPhone;
extern bool vinPhone;

extern double cashIncome;
extern double bankIncome;
extern double cash;

//=====================================

#endif // !_QWERTY_HPP_
