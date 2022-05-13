#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include "Professions.h"
#define DEBUG 
using namespace std;

void AdministrativeAssistant::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж:" << _workExperience << endl;
	cout << "Посада: помічник адміністратора" << endl;
	cout << "Зарплатня: " << _payment << "грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

void BusinessAnalyst::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж:" << _workExperience << endl;
	cout << "Посада: бізнес-аналітик" << endl;
	cout << "Зарплатня: " << _payment << "грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

void MarketingSpecialist::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж:" << _workExperience << endl;
	cout << "Посада: спеціаліст з маркетингу" << endl;
	cout << "Зарплатня: " << _payment << "грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}