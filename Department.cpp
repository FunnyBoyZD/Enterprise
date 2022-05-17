#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include <algorithm>
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
  workers - робітники для задання
  name - назва відділу
Вихід: відсутній
*/
Department::Department(vector<Employee*> workers, string name)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
    cout << "Викликався конструктор з параметрами класу Department - " << this << endl << endl;
#endif 
    Set(workers, name);
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
    Set(other._workers, other._name);
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
Геттер для всіх робітників відділу
Вхід: відсутній
Вихід:
  GetWorkers = newWorkers - всі робітники відділу
*/
vector<Employee*> Department::GetWorkers()
{
    vector<Employee*> newWorkers;
    for (auto worker : _workers)
    {
        newWorkers.emplace_back(worker);
    }
    return newWorkers;
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
    return GetWorkersByProf(vAA, "Помічник адміністратора");
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
    return GetWorkersByProf(vBA, "Бізнес-аналітик");
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
    return GetWorkersByProf(vMS, "Спеціаліст з маркетингу");
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
  workers - робітники для задання
  name - назва відділу
Вихід: відсутній
*/
void Department::Set(vector<Employee*> workers, string name)
{
    SetWorkers(workers);
    SetName(name);
}

/*
Сеттер для всіх робітників відділу
Вхід:
    workers - робітники для задання
Вихід: відсутній
*/
void Department::SetWorkers(vector<Employee*> workers)
{
    static_cast<void>(workers.at(0));
    _workers.clear();
    for (auto worker : workers)
    {
        _workers.emplace_back(worker);
    }
}

/*
Сеттер для помічників адміністратора
Вхід:
    workersAA - помічники адміністратора для задання
Вихід: відсутній
*/
void Department::SetWorkersAA(vector<AdministrativeAssistant*> workersAA)
{
    vector<Employee*> newWorkers;
    for (auto worker : workersAA)
    {
        newWorkers.emplace_back(worker);
    }
    for (auto workerBA : _workers)
    {
        if (workerBA->GetProfession() == "Бізнес-аналітик")
        {
            newWorkers.emplace_back(workerBA);
        }
    }
    for (auto workerMS : _workers)
    {
        if (workerMS->GetProfession() == "Спеціаліст з маркетингу")
        {
            newWorkers.emplace_back(workerMS);
        }
    }

    _workers.clear();
    for (auto worker : newWorkers)
    {
        _workers.emplace_back(worker);
    }
}

/*
Сеттер для бізнес-аналітиків
Вхід:
    workersAA - бізнес-аналітики для задання
Вихід: відсутній
*/
void Department::SetWorkersBA(vector<BusinessAnalyst*> workersBA)
{
    vector<Employee*> newWorkers;
    for (auto workerAA : _workers)
    {
        if (workerAA->GetProfession() == "Помічник адміністратора")
        {
            newWorkers.emplace_back(workerAA);
        }
    }
    for (auto worker : workersBA)
    {
        newWorkers.emplace_back(worker);
    }
    for (auto workerMS : _workers)
    {
        if (workerMS->GetProfession() == "Спеціаліст з маркетингу")
        {
            newWorkers.emplace_back(workerMS);
        }
    }

    _workers.clear();
    for (auto worker : newWorkers)
    {
        _workers.emplace_back(worker);
    }
}

/*
Сеттер для спеціалістів з маркетингу
Вхід:
    workersAA - спеціалісти з маркетингу для задання
Вихід: відсутній
*/
void Department::SetWorkersMS(vector<MarketingSpecialist*> workersMS)
{
    vector<Employee*> newWorkers;
    for (auto workerAA : _workers)
    {
        if (workerAA->GetProfession() == "Помічник адміністратора")
        {
            newWorkers.emplace_back(workerAA);
        }
    }
    for (auto workerBA : _workers)
    {
        if (workerBA->GetProfession() == "Бізнес-аналітик")
        {
            newWorkers.emplace_back(workerBA);
        }
    }
    for (auto worker : workersMS)
    {
        newWorkers.emplace_back(worker);
    }

    _workers.clear();
    for (auto worker : newWorkers)
    {
        _workers.emplace_back(worker);
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
Метод додавання нового робітника у відділ
Вхід:
    newWorker - новий робітник, передача за посиланням
    profession - посада нового робітника
Вихід: відсутній
*/
void Department::Insert(Employee* newWorker, string profession)
{
    if (newWorker == NULL)
    {
        throw(exception("Ви не передали нового робітника!"));
    }
    auto iterator = _workers.begin();
    int iCurrent = 0,
        iPrevious = 0;
    for (auto worker : _workers)
    {
        if (worker->GetProfession() == profession)
        {
            advance(iterator, iCurrent - iPrevious);
            iPrevious = iCurrent;
        }
        iCurrent++;
    }
    _workers.insert(iterator, newWorker);
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
    for (auto worker : _workers)
    {
        cout << "\nПрацівник №" << counter << ":";
        worker->Show();
        counter++;
    }
    cout << endl << endl;
}

template <typename T>
/*
Геттер для робітників за їхньою професією
Вхід:
    vector - контейнер для робітників із заданою професією, передача за посиланням
    profession - професія робітників
Вихід:
    GetWorkersByProf = vector - контейнер із робітниками з заданою професією
*/
vector<T> Department::GetWorkersByProf(vector<T>& vector, string profession)
{
    int j = 0;
    for (auto i = _workers.begin(); i != _workers.end(); i++, j++)
    {
        if (_workers.at(j)->GetProfession() == profession)
        {
            T AA;
            AA.Set(_workers.at(j)->GetName(), _workers.at(j)->GetProfession(), _workers.at(j)->GetAge(), _workers.at(j)->GetExperience(), _workers.at(j)->GetPayment(), _workers.at(j)->GetWorkingPlace());
            vector.emplace_back(AA);
        }
    }
    return vector;
}
