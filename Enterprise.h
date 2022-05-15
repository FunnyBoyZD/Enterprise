#pragma once
#include "Date.h"
#include "Department.h"
using namespace std;

class Enterprise
{
public: //компоненти класу, до яких наданий публічний доступ
	Enterprise(); //конструктор без параметрів
	Enterprise(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds); //конструктор з параметрами
	Enterprise(const Enterprise& other); //конструктор копіювання
	Enterprise(Enterprise&&) noexcept = delete; //заборона конструктора переміщення
	Enterprise& operator=(Enterprise&&) = delete; //заборона переміщення за допомогою оператора присвоювання
	Enterprise& operator=(const Enterprise&) = default; //копіювання за допомогою оператора присвоювання за замовчуванням
	Department* GetDepartment(size_t numOfDep); //геттер адреси конкретного відділу
	int GetNumberOfDepartments(); //геттер для отримання кількості відділів корпорації
	vector<Department> GetItems(); //геттер для відділів
	string GetCreationDate(); //геттер для дати створення
	string GetName(); //геттер для імені
	string GetCEO(); //геттер для СЕО
	double GetProceeds(); //геттер для прибутку
	void Set(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds); //сеттер для усіх полів
	void SetItems(vector<Department> items); //сеттер для відділів
	void SetCreationDate(Date& createdAt); //сеттер для дати створення
	void SetName(string name); //сеттер для назви
	void SetCEO(string chiefExecutiveOfficer); //сеттер для СЕО
	void SetProceeds(double proceeds); //сеттер для прибутку
	void Insert(const Department* newDepartment); //вставлення нового відділу
	void Show(); //вивід даних про корпорацію до консолі
	~Enterprise(); //деструктор
protected: //компоненти класу, до яких захищений доступ
	vector<Department> _items; //відділи
	Date _createdAt; //дата створення
	string _name; //назва
	string _chiefExecutiveOfficer; //СЕО
	double _proceeds; //прибуток
};
