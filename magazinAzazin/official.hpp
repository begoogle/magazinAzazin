#pragma once

#ifndef _OFFICIAL_HPP_
#define _OFFICIAL_HPP_

#include "include.hpp"
#include "global.hpp"

void Start();
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


#endif // !_OFFICIAL_HPP_
