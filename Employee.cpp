#define _CRT_SECURE_NO_WARNINGS
#include "string.h" 
#include <iostream>
#include "Employee.h"
//#define DEBUG 
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Employee::Employee()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Employee - " << this << endl << endl;
#endif 
	_name = "Невідомо";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
}

/*
Конструктор з параметрами
Вхід:
	name - ім'я робітника
	age - вік робітника
	work_experience - стаж робітника
	payment - зарплатня робітника
	workingPlace - місце роботи робітника
Вихід: відсутній
*/
Employee::Employee(string name, int age, int workExperience, double payment, bool workingPlace)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	cout << "Викликався конструктор з параметрами класу Employee - " << this << endl << endl;
#endif
	Set(name, age, workExperience, payment, workingPlace);
}

/*
Конструктор копіювання
Вхід:
	other - константне посилання на об'єкт класу Employee
Вихід: відсутній
*/
Employee::Employee(const Employee& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Викликався конструктор копіювання класу Employee - " << this << endl << endl;
#endif 
	Set(other._name, other._age, other._workExperience, other._payment, other._workingPlace);
}

/*
Геттер для імені робітника
Вхід: відсутній
Вихід:
	GetName = newName - ім'я робітника
*/
string Employee::GetName()
{
	string newName = _name;
	return newName;
}

/*
Геттер для віку робітника
Вхід: відсутній
Вихід:
	GetAge = _age - вік робітника
*/
int Employee::GetAge()
{
	return _age;
}

/*
Геттер для стажу робітника
Вхід: відсутній
Вихід:
	GetExperience = _workExperience - стаж робітника
*/
int Employee::GetExperience()
{
	return _workExperience;
}

/*
Геттер для зарплатні робітника
Вхід: відсутній
Вихід:
	GetPayment = _payment - зарплатня робітника
*/
double Employee::GetPayment()
{
	return _payment;
}

/*
Геттер для місця роботи робітника
Вхід: відсутній
Вихід:
	GetWorkingPlace = _workingPlace - місце роботи робітника
*/
bool Employee::GetWorkingPlace()
{
	return _workingPlace;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
	name - ім'я робітника
	age - вік робітника
	work_experience - стаж робітника
	payment - зарплатня робітника
	workingPlace - місце роботи робітника
Вихід: відсутній
*/
void Employee::Set(string name, int age, int workExperience, double payment, bool workingPlace)
{
	SetName(name);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
}

/*
Сеттер для імені робітника
Вхід:
	name - ім'я робітника
Вихід: відсутній
*/
void Employee::SetName(string name)
{
	_name = name;
}

/*
Сеттер для віку робітника
Вхід:
	age - вік робітника
Вихід: відсутній
*/
void Employee::SetAge(int age)
{
	if (age < 18 || age > 65)
		throw(exception("Ви передали некоректне значення віку робітника!"));
	else
		_age = age;
}

/*
Сеттер для стажу робітника
Вхід:
	work_experience - стаж робітника
Вихід: відсутній
*/
void Employee::SetExperience(int work_experience)
{
	if (work_experience < 0 || work_experience > 46)
		throw(exception("Ви передали некоректне значення стажу робітника!"));
	else
		_workExperience = work_experience;
}

/*
Сеттер для зарплатні робітника
Вхід:
	payment - зарплатня робітника
Вихід: відсутній
*/
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

/*
Сеттер для місця роботи робітника
Вхід:
	workingPlace - місце роботи робітника
Вихід: відсутній
*/
void Employee::SetWorkingPlace(bool workingPlace)
{
	_workingPlace = workingPlace;
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Employee::~Employee()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Employee - " << this << endl << endl;
#endif 
}
