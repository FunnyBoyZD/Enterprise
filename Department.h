#pragma once
#include "Professions.h"

class Department
{
public: //компоненти класу, до яких наданий публічний доступ
	Department(); //конструктор без параметрів
	Department(vector<AdministrativeAssistant>& workersAA, vector<BusinessAnalyst>& workersBA, vector<MarketingSpecialist>& workersMS, string name); //конструктор з параметрами
	Department(const Department& other); //конструктор копіювання
	string GetName(); //геттер для назви відділу без зазначеної кількості елементів для запису
	vector<AdministrativeAssistant> GetWorkersAA();  //геттер для помічників адміністратора
	vector<BusinessAnalyst> GetWorkersBA(); //геттер для бізнес-аналітиків
	vector<MarketingSpecialist> GetWorkersMS(); //геттер для спеціалістів з маркетингу
	void Set(vector<AdministrativeAssistant> workersAA, vector<BusinessAnalyst> workersBA, vector<MarketingSpecialist> workersMS, string name); //сеттер для всіх полів
	void SetWorkersAA(vector<AdministrativeAssistant> workersAA); //сеттер для помічників адміністратора
	void SetWorkersBA(vector<BusinessAnalyst> workersBA); //сеттер для бізнес-аналітиків
	void SetWorkersMS(vector<MarketingSpecialist> workersMS); //сеттер для спеціалістів з маркетингу
	void SetName(string name); //сеттер для назви
	void InsertAnAA(const AdministrativeAssistant* newWorker); //додати нового помічника адміністратора
	void InsertABA(const BusinessAnalyst* newWorker); //додати нового бізнес-аналітика
	void InsertAMS(const MarketingSpecialist* newWorker); //додати нового спеціаліста з маркетингу
	virtual void Show(); //вивід даних про відділ до консолі
	~Department(); //деструктор
protected: //компоненти класу, до яких захищений доступ
	vector<AdministrativeAssistant> _workersAA; //помічники адміністратора
	vector<BusinessAnalyst> _workersBA; //бізнес-аналітики
	vector<MarketingSpecialist> _workersMS; //спеціалісти з маркетингу
	string _name; //назва
};
