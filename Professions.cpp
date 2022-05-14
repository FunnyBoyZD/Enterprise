#define _CRT_SECURE_NO_WARNINGS 
#include "Professions.h"
using namespace std;

/*
Функція виводу до консолі інформації про помічника адміністратора
Вхід: відсутній
Вихід: відсутній
*/
void AdministrativeAssistant::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: помічник адміністратора" << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

/*
Функція виводу до консолі інформації про бізнес-аналітика
Вхід: відсутній
Вихід: відсутній
*/
void BusinessAnalyst::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: бізнес-аналітик" << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

/*
Функція виводу до консолі інформації про спеціаліста з маркетингу
Вхід: відсутній
Вихід: відсутній
*/
void MarketingSpecialist::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: спеціаліст з маркетингу" << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}
