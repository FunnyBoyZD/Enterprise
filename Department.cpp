#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include "Department.h"
//#define DEBUG
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Department::Department()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Department - " << this << endl << endl;
#endif 
	_name = "Невідомо";
}

/*
Конструктор з параметрами
Вхід:
	workersAA - посилання на помічників адміністратора
	workersBA - посилання на бізнес-аналітиків
	workersMS - посилання на спеціалістів з маркетингу
	name - назва відділу
Вихід: відсутній
*/
Department::Department(vector<AdministrativeAssistant>& workersAA, vector<BusinessAnalyst>& workersBA, vector<MarketingSpecialist>& workersMS, string name)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор з параметрами класу Department - " << this << endl << endl;
#endif 
	Set(workersAA, workersBA, workersMS, name);
}

/*
Конструктор копіювання
Вхід:
	other - константне посилання на об'єкт класу Department
Вихід: відсутній
*/
Department::Department(const Department& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор копіювання класу Department - " << this << endl << endl;
#endif
	Set(other._workersAA, other._workersBA, other._workersMS, other._name);
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Department::~Department()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Department - " << this << endl << endl;
#endif 
}

/*
Геттер для назви відділу
Вхід: відсутній
Вихід:
	GetName = newName - назва відділу
*/
string Department::GetName()
{
	string newName = _name;
	return newName;
}

/*
Геттер для помічників адміністратора
Вхід: відсутній
Вихід:
	GetWorkersAA = vAA - помічники адміністратора
*/
vector<AdministrativeAssistant> Department::GetWorkersAA()
{
	vector<AdministrativeAssistant> vAA;
	for (auto item = _workersAA.begin(); item != _workersAA.end(); item++)
	{
		vAA.emplace_back(*item);
	}
	return vAA;
}

/*
Геттер для бізнес-аналітиків
Вхід: відсутній
Вихід:
	GetWorkersBA = vBA - бізнес-аналітики
*/
vector<BusinessAnalyst> Department::GetWorkersBA()
{
	vector<BusinessAnalyst> vBA;
	for (auto item = _workersBA.begin(); item != _workersBA.end(); item++)
	{
		vBA.emplace_back(*item);
	}
	return vBA;
}

/*
Геттер для спеціалістів з маркетингу
Вхід: відсутній
Вихід:
	GetWorkersMS = vMS - спеціалісти з маркетингу
*/
vector<MarketingSpecialist> Department::GetWorkersMS()
{
	vector<MarketingSpecialist> vMS;
	for (auto item = _workersMS.begin(); item != _workersMS.end(); item++)
	{
		vMS.emplace_back(*item);
	}
	return vMS;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
	workersAA - помічники адміністратора
	workersBA - бізнес-аналітики
	workersMS - спеціалісти з маркетингу
	name - назва відділу
Вихід: відсутній
*/
void Department::Set(vector<AdministrativeAssistant> workersAA, vector<BusinessAnalyst> workersBA, vector<MarketingSpecialist> workersMS, string name)
{
	SetWorkersAA(workersAA);
	SetWorkersBA(workersBA);
	SetWorkersMS(workersMS);
	SetName(name);
}

/*
Сеттер для помічників адміністратора
Вхід:
	workersAA - помічники адміністратора
Вихід: відсутній
*/
void Department::SetWorkersAA(vector<AdministrativeAssistant> workersAA)
{
	workersAA.at(0);
	_workersAA.clear();
	for (auto item = workersAA.begin(); item != workersAA.end(); item++)
	{
		_workersAA.emplace_back(*item);
	}
}

/*
Сеттер для бізнес-аналітиків
Вхід:
	workersBA - бізнес-аналітики
Вихід: відсутній
*/
void Department::SetWorkersBA(vector<BusinessAnalyst> workersBA)
{
	workersBA.at(0);
	_workersBA.clear();
	for (auto item = workersBA.begin(); item != workersBA.end(); item++)
	{
		_workersBA.emplace_back(*item);
	}
}

/*
Сеттер для спеціалістів з маркетингу
Вхід:
	workersMS - спеціалісти з маркетингу
Вихід: відсутній
*/
void Department::SetWorkersMS(vector<MarketingSpecialist> workersMS)
{
	workersMS.at(0);
	_workersMS.clear();
	for (auto item = workersMS.begin(); item != workersMS.end(); item++)
	{
		_workersMS.emplace_back(*item);
	}
}

/*
Сеттер для назви відділу
Вхід:
	name - назва відділу
Вихід: відсутній
*/
void Department::SetName(string name)
{
	_name = name;
}

/*
Метод додавання нового помічника адміністратора
Вхід:
	newWorker - новий помічник адміністратора
Вихід: відсутній
*/
void Department::InsertAnAA(const AdministrativeAssistant* newWorker)
{
	if (newWorker == NULL)
	{
		throw(exception("Ви не передали нового робітника!"));
	}
	_workersAA.push_back(*newWorker);
}

/*
Метод додавання нового бізнес-аналітика
Вхід:
	newWorker - новий бізнес-аналітик
Вихід: відсутній
*/
void Department::InsertABA(const BusinessAnalyst* newWorker)
{
	if (newWorker == NULL)
	{
		throw(exception("Ви не передали нового робітника!"));
	}
	_workersBA.push_back(*newWorker);
}

/*
Метод додавання нового спеціалісту з маркетингу
Вхід:
	newWorker - новий спеціаліст з маркетингу
Вихід: відсутній
*/
void Department::InsertAMS(const MarketingSpecialist* newWorker)
{
	if (newWorker == NULL)
	{
		throw(exception("Ви не передали нового робітника!"));
	}
	_workersMS.push_back(*newWorker);
}

/*
Метод виводу інформації про відділ
Вхід: відсутній
Вихід: відсутній
*/
void Department::Show()
{ 
	cout << "Назва: " << _name << endl;
	cout << "Працівники в цьому відділі:";
	int counter = 1;
	for (auto worker : _workersAA)
	{
		cout << "\nПрацівник №" << counter << ":";
		worker.Show();
		counter++;
	}
	for (auto worker : _workersBA)
	{
		cout << "\nПрацівник №" << counter << ":";
		worker.Show();
		counter++;
	}
	for (auto worker : _workersMS)
	{
		cout << "\nПрацівник №" << counter << ":";
		worker.Show();
		counter++;
	}
	cout << endl << endl;
}
