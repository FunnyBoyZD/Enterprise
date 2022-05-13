#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public: //компоненти класу, до яких наданий публічний доступ	
	Employee(); //конструктор без параметрів
	Employee(string name, int age, int work_experience, double payment, bool workingPlace); //конструктор з параметрами
	Employee(const Employee& other); //конструктор копіювання
	Employee(Employee&&) noexcept = default;
	Employee& operator=(Employee&&) = default;
	Employee& operator=(const Employee&) = default; //копіювання за допомогою оператора присвоювання за замовчуванням
	string GetName(); //геттер для імені без зазначеної кількості елементів для запису
	int GetAge(); //геттер для віку
	int GetExperience(); //геттер для стажу роботи
	double GetPayment(); //геттер для зарплатні
	bool GetWorkingPlace(); //геттер для місця роботи
	void Set(string name, int age, int work_experience, double payment, bool workingPlace); //сеттер для всіх полів
	void SetName(string name); //геттер для імені
	void SetAge(int age); //геттер для віку
	void SetExperience(int work_experience); //сеттер для стажу роботи
	void SetPayment(double payment); //сеттер для зарплатні
	void SetWorkingPlace(bool workingPlace); //сеттер для місця роботи
	~Employee(); //деструктор за замовчуванням
protected: //компоненти класу, до яких захищений доступ
	string _name; //ім'я робітника
	int _age; //вік робітника
	int _workExperience; //стаж роботи робітника
	double _payment; //зарплатня
	bool _workingPlace; //місце роботи(вдома чи в офісі)
};