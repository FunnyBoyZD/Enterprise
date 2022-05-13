#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include <vector>
#include "Enterprise.h"
#define DEBUG
using namespace std;

Enterprise::Enterprise()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Enterprice - " << this << endl << endl;
#endif 
	_createdAt = NULL;
	_proceeds = 0;
}

Enterprise::Enterprise(vector<Department> items, Date* createdAt, string name, string owner, double proceeds)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор з параметрами класу Enterprice - " << this << endl << endl;
#endif 
	if (&items == NULL)
	{
		throw(exception("Ви не передали відділи для задання!"));
	}
	if (createdAt == NULL)
	{
		throw(exception("Ви не передали дату створення!"));
	}
	for(auto item=items.begin(); item!=items.end(); item++)
	{
		_items.emplace_back(*item);
	}
	_createdAt = createdAt;
	_name += name;
	_chiefExecutiveOfficer += owner;
	_proceeds = proceeds;
}

Enterprise::Enterprise(const Enterprise& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор копіювання класу Enterprice - " << this << endl << endl;
#endif
	if (&other == NULL)
	{
		throw(exception("Ви не передали об'єкту класу для копіювання!"));
	}
	for (auto item = other._items.begin(); item != other._items.end(); item++)
	{
		_items.emplace_back(*item);
	}
	_createdAt = other._createdAt;
	_name = _name + other._name;
	_chiefExecutiveOfficer = _chiefExecutiveOfficer + other._chiefExecutiveOfficer;
	_proceeds = other._proceeds;
}

vector<Department> Enterprise::GetItems()
{
	vector<Department> items;
	for (auto item = _items.begin(); item != _items.end(); item++)
	{
		items.emplace_back(*item);
	}
	return items;
}

string Enterprise::GetCreationDate()
{
	string day = "";
	if (_createdAt->GetDay() < 10)
	{
		day = "0";
		day += _createdAt->GetDay();
	}
	else
	{
		day = _createdAt->GetDay();
	}
	string creationDate;
	creationDate = _createdAt->GetYear();
	creationDate += ".";
	creationDate += _createdAt->GetMonth();
	creationDate += ".";
	creationDate += day;
	return creationDate;
}

string Enterprise::GetName()
{
	return _name;
}

string Enterprise::GetCEO()
{
	return _chiefExecutiveOfficer;
}

double Enterprise::GetProceeds()
{
	return _proceeds;
}

void Enterprise::Set(vector<Department> items, Date* createdAt, string name, string owner, double proceeds)
{
	if (&items == NULL)
	{
		throw(exception("Ви не передали відділи для задання!"));
	}
	if (createdAt == NULL)
	{
		throw(exception("Ви не передали дату створення!"));
	}
	for (auto item = items.begin(); item != items.end(); item++)
	{
		_items.emplace_back(*item);
	}
	_createdAt = createdAt;
	_name = name;
	_chiefExecutiveOfficer = _chiefExecutiveOfficer + owner;
	_proceeds = proceeds;
}

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

void Enterprise::SetCreationDate(Date& createdAt)
{
	if (&createdAt == NULL)
	{
		throw("Ви не передали дату створення!");
	}
	_createdAt = &createdAt;
}

void Enterprise::SetName(string name)
{
	_name = name;
}

void Enterprise::SetCEO(string chiefExecutiveOfficer)
{
	_chiefExecutiveOfficer = chiefExecutiveOfficer;
}

void Enterprise::SetProceeds(double proceeds)
{
	_proceeds = proceeds;
}

void Enterprise::Insert(const Department* newDepartment)
{
	if (newDepartment == NULL)
	{
		throw(exception("Ви не передали новий відділ!"));
	}
	_items.push_back(*newDepartment);
}

void Enterprise::Show()
{
	if (_createdAt->GetDay() < 10)
	{
		cout << "Дата створення корпорації: 0" << _createdAt->GetDay() << "." << _createdAt->GetMonth() << "." << _createdAt->GetYear() << endl;
	}
	else
	{
		cout << "Дата створення корпорації: " << _createdAt->GetDay() << "." << _createdAt->GetMonth() << "." << _createdAt->GetYear() << endl;
	}
	cout << "Назва корпорації: " << _name << endl;
	cout << "CEO корпорації: " << _chiefExecutiveOfficer << endl;
	cout << "Відділи корпорації:";
	int counter = 1;
	for (auto item : _items)
	{
		cout << "\nВідділ №" << counter << ":" << endl;
		item.Show();
	}
}

Enterprise::~Enterprise()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	printf("Викликався деструктор класу Enterprice - %p\n\n ", this);
#endif 
}
