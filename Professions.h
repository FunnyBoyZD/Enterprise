#pragma once
#include "Employee.h"

class MarketingSpecialist : public Employee //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	MarketingSpecialist() = default; //конструктор без параметрів за замовчуванням
	virtual void Show(); //функція для виводу інформації до консолі
	~MarketingSpecialist() = default; //деструктор за замовчуванням
};

class BusinessAnalyst : public Employee //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	BusinessAnalyst() = default; //конструктор без параметрів за замовчуванням
	virtual void Show(); //вивід даних про бізнес-аналітика до консолі
	~BusinessAnalyst() = default; //деструктор за замовчуванням
};

class AdministrativeAssistant : public Employee //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	AdministrativeAssistant() = default; //конструктор без параметрів за замовчуванням
	virtual void Show(); //вивід даних про помічника адміністратора до консолі
	~AdministrativeAssistant() = default; //деструктор за замовчуванням
};