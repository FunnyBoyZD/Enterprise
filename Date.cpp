#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include "Date.h" 
#define DEBUG
using namespace std;

Date::Date()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Date - " << this << endl << endl;
#endif 
	_year = "Невідомо";
	_month = "Невідомо";
	_day = 0;
}

Date::Date(string year, string month, const int day)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	cout << "Викликався конструктор з параметрами класу Date - " << this << endl << endl;
#endif 
	_year = year;
	_month = month;
	if (day < 0 || day > 30)
		throw(exception("Ви передали некоректне значення дня!"));
	else
		_day = day;
}

Date::Date(const Date& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Викликався конструктор копіювання класу Date - " << this << endl << endl;
#endif 
	_year = other._year;
	_month = other._month;
	_day = other._day;
}

string Date::GetYear()
{
	string newYear = _year;
	return newYear;
}

string Date::GetMonth()
{
	string newMonth = _month;
	return newMonth;
}

int Date::GetDay()
{
	return _day;
}

void Date::Set(string year, string month, const int day)
{
	_year = year;
	_month = month;
	if (day < 0 || day > 30)
		throw(exception("Ви передали некоректне значення дня!"));
	else
		_day = day;
}

void Date::SetYear(string year)
{
	_year = year;
}

void Date::SetMonth(string month)
{
	_month = month;
}

void Date::SetDay(const int day)
{
	if (day < 0 || day > 30)
		throw(exception("Ви передали некоректне значення дня!"));
	else
		_day = day;
}

void Date::Show()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Рік: " << _year << endl;
	cout << "Місяць: " << _month << endl;
	cout << "День: " << _day << endl << endl;
#endif 
}

Date::~Date()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Date - " << this << endl << endl;
#endif 
}