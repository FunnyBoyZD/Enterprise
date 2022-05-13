#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include "Employee.h"
#define DEBUG 
using namespace std;

Employee::Employee()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Employee - " << this << endl << endl;
#endif 
	_name = "Невідомо";
	_age = 0;
	_workExperience = 0;
	_payment = 0;
	_workingPlace = 0;
}

Employee::Employee(string name, int age, int work_experience, double payment, bool workingPlace)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	cout << "Викликався конструктор з параметрами класу Employee - " << this << endl << endl;
#endif
	_name = name;
	if (age < 18 || age > 65)
		throw(exception("Ви передали некоректне значення віку робітника!"));
	else
		_age = age;
	if (work_experience < 0 || work_experience > 46)
		throw(exception("Ви передали некоректне значення стажу робітника!"));
	else
		_workExperience = work_experience;
	if (payment >= 0)
	{
		_payment = payment;
	}
	else
	{
		throw(exception("Ви задали некоректне значення зарплатні!"));
	}
	_workingPlace = workingPlace;
}

Employee::Employee(const Employee& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Викликався конструктор копіювання класу Employee - " << this << endl << endl;
#endif 
	_name = other._name;
	_age = other._age;
	_workExperience = other._workExperience;
	_payment = other._payment;
	_workingPlace = other._workingPlace;
}

string Employee::GetName()
{
	string newname = _name;
	return newname;
}

int Employee::GetAge()
{
	return _age;
}

int Employee::GetExperience()
{
	return _workExperience;
}

double Employee::GetPayment()
{
	return _payment;
}

bool Employee::GetWorkingPlace()
{
	return _workingPlace;
}

void Employee::Set(string name, int age, int work_experience, double payment, bool workingPlace)
{
	_name = name;
	if (age < 18 || age > 65)
		throw(exception("Ви передали некоректне значення віку робітника!"));
	else
		_age = age;
	if (work_experience < 0 || work_experience > 46)
		throw(exception("Ви передали некоректне значення стажу робітника!"));
	else
		_workExperience = work_experience;
	if (payment >= 0)
	{
		_payment = payment;
	}
	else
	{
		throw(exception("Ви задали некоректне значення зарплатні!"));
	}
	_workingPlace = workingPlace;
}

void Employee::SetName(string name)
{
	_name = name;
}

void Employee::SetAge(int age)
{
	if (age < 18 || age > 65)
		throw(exception("Ви передали некоректне значення віку робітника!"));
	else
		_age = age;
}

void Employee::SetExperience(int work_experience)
{
	if (work_experience < 0 || work_experience > 46)
		throw(exception("Ви передали некоректне значення стажу робітника!"));
	else
		_workExperience = work_experience;
}

void Employee::SetPayment(double payment)
{
	if (payment >= 0)
	{
		_payment = payment;
	}
	else
	{
		throw(exception("Ви задали некоректне значення зарплатні!"));
	}
}

void Employee::SetWorkingPlace(bool workingPlace)
{
	_workingPlace = workingPlace;
}

Employee::~Employee()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Employee - " << this << endl << endl;
#endif 
}