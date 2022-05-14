#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include "Enterprise.h"
//#define DEBUG
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Enterprise::Enterprise()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Enterprice - " << this << endl << endl;
#endif 
	_proceeds = 0;
}

/*
Конструктор з параметрами
Вхід:
	items - відділи корпорації
	createdAt - дата заснування
	name - назва корпорації
	chiefExecutiveOfficer - CEO корпорації
	proceeds - прибуток корпорації
Вихід: відсутній
*/
Enterprise::Enterprise(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор з параметрами класу Enterprice - " << this << endl << endl;
#endif 
	Set(items, createdAt, name, chiefExecutiveOfficer, proceeds);
}

/*
Конструктор копіювання
Вхід:
	other - константне посилання на об'єкт класу Enterprise
Вихід: відсутній
*/
Enterprise::Enterprise(const Enterprise& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор копіювання класу Enterprice - " << this << endl << endl;
#endif
	if (&other == NULL)
	{
		throw(exception("Ви не передали об'єкту класу для копіювання!"));
	}
	Set(other._items, *const_cast<Date*>(&other._createdAt), other._name, other._chiefExecutiveOfficer, other._proceeds);
}

/*
Геттер для відділів корпорації
Вхід: відсутній
Вихід:
	GetItems = items - відділи корпорації
*/
vector<Department> Enterprise::GetItems()
{
	vector<Department> items;
	for (auto item = _items.begin(); item != _items.end(); item++)
	{
		items.emplace_back(*item);
	}
	return items;
}

/*
Геттер для дати заснування корпорації
Вхід: відсутній
Вихід:
	GetCreationDate = creationDate - дата заснування корпорації
*/
string Enterprise::GetCreationDate()
{
	string day = "";
	if (_createdAt.GetDay() < 10)
	{
		day = "0";
		day += _createdAt.GetDay();
	}
	else
	{
		day = _createdAt.GetDay();
	}
	string creationDate;
	creationDate = _createdAt.GetYear();
	creationDate += ".";
	creationDate += _createdAt.GetMonth();
	creationDate += ".";
	creationDate += day;
	return creationDate;
}

/*
Геттер для назви корпорації
Вхід: відсутній
Вихід:
	GetName = _name - назва корпорації
*/
string Enterprise::GetName()
{
	return _name;
}

/*
Геттер для СЕО корпорації
Вхід: відсутній
Вихід:
	GetCEO = _chiefExecutiveOfficer - СЕО корпорації
*/
string Enterprise::GetCEO()
{
	return _chiefExecutiveOfficer;
}

/*
Геттер для прибутку корпорації
Вхід: відсутній
Вихід:
	GetProceeds = _proceeds - прибуток корпорації
*/
double Enterprise::GetProceeds()
{
	return _proceeds;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
	items - відділи корпорації
	createdAt - дата заснування корпорації
	name - назва корпорації
	chiefExecutiveOfficer - СЕО корпорації
	proceeds - прибуток корпорації
Вихід: відсутній
*/
void Enterprise::Set(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
	SetItems(items);
	SetCreationDate(createdAt);
	SetName(name);
	SetCEO(chiefExecutiveOfficer);
	SetProceeds(proceeds);
}

/*
Сеттер для відділів корпорації
Вхід:
	items - посилання на відділи корпорації
Вихід: відсутній
*/
void Enterprise::SetItems(vector<Department>& items)
{
	if (&items == NULL)
	{
		throw("Ви не передали відділи для задання!");
	}
	for (auto item = items.begin(); item != items.end(); item++)
	{
		_items.emplace_back(*item);
	}
}

/*
Сеттер для дати заснування корпорації
Вхід:
	createdAt - дата заснування корпорації
Вихід: відсутній
*/
void Enterprise::SetCreationDate(Date& createdAt)
{
	if (&createdAt == NULL)
	{
		throw("Ви не передали дату створення!");
	}
	_createdAt = createdAt;
}

/*
Сеттер для назви корпорації
Вхід:
	name - назва корпорації
Вихід: відсутній
*/
void Enterprise::SetName(string name)
{
	_name = name;
}

/*
Сеттер для СЕО корпорації
Вхід:
	chiefExecutiveOfficer - СЕО корпорації
Вихід: відсутній
*/
void Enterprise::SetCEO(string chiefExecutiveOfficer)
{
	_chiefExecutiveOfficer = chiefExecutiveOfficer;
}

/*
Сеттер для прибутку корпорації
Вхід:
	proceeds - прибуток корпорації
Вихід: відсутній
*/
void Enterprise::SetProceeds(double proceeds)
{
	_proceeds = proceeds;
}

/*
Метод для додавання нового відділу корпорації
Вхід:
	newDepartment - константна адреса нового відділу
Вихід: відсутній
*/
void Enterprise::Insert(const Department* newDepartment)
{
	if (newDepartment == NULL)
	{
		throw(exception("Ви не передали новий відділ!"));
	}
	_items.push_back(*newDepartment);
}

/*
Функція виводу до консолі інформації про корпорацію
Вхід: відсутній
Вихід: відсутній
*/
void Enterprise::Show()
{
	if (_createdAt.GetDay() < 10)
	{
		cout << "Дата створення корпорації: 0" << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	else
	{
		cout << "Дата створення корпорації: " << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	cout << "Назва корпорації: " << _name << endl;
	cout << "CEO корпорації: " << _chiefExecutiveOfficer << endl;
	cout << "Відділи корпорації:" << endl;
	int counter = 1;
	for (auto item : _items)
	{
		cout << "\nВідділ №" << counter << ":" << endl;
		item.Show();
		counter++;
	}
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Enterprise::~Enterprise()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Enterprice - " << this << endl << endl;
#endif 
}
