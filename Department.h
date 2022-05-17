#pragma once
#include "Professions.h"

class Department
{
public: //компоненти класу, до яких наданий публічний доступ
	Department(); //конструктор без параметрів
	Department(vector<Employee*> workers, string name); //конструктор з параметрами
	Department(const Department& other); //конструктор копіювання
	string GetName(); //геттер для назви відділу без зазначеної кількості елементів для запису
	vector<Employee*> GetWorkers(); //геттер для всіх робітників відділу
	vector<AdministrativeAssistant> GetWorkersAA();  //геттер для помічників адміністратора
	vector<BusinessAnalyst> GetWorkersBA(); //геттер для бізнес-аналітиків
	vector<MarketingSpecialist> GetWorkersMS(); //геттер для спеціалістів з маркетингу
	void Set(vector<Employee*> workers, string name); //сеттер для всіх полів
	void SetWorkers(vector<Employee*> workers); //сеттер для всіх робітників відділу
	void SetWorkersAA(vector<AdministrativeAssistant*> workersAA); //сеттер для помічників адміністратора
	void SetWorkersBA(vector<BusinessAnalyst*> workersBA); //сеттер для бізнес-аналітиків
	void SetWorkersMS(vector<MarketingSpecialist*> workersMS); //сеттер для спеціалістів з маркетингу
	void SetName(string name); //сеттер для назви
	void Insert(Employee* newWorker, string profession); //додати нового робітника у відділ
	void Show(); //вивід даних про відділ до консолі
	~Department(); //деструктор
protected: //компоненти класу, до яких захищений доступ
	vector<Employee*> _workers; //робітники відділу
	string _name; //назва

	template <typename T>
	vector<T> GetWorkersByProf(vector<T>& vector, string profession); //геттер для робітників за їхньою професією
	
};
