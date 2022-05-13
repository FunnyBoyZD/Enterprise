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
#include "Department.h"
#define DEBUG
using namespace std;

Department::Department()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Department - " << this << endl << endl;
#endif 
	_name = "Невідомо";
}

Department::Department(vector<AdministrativeAssistant>& workersAA, vector<BusinessAnalyst>& workersBA, vector<MarketingSpecialist>& workersMS, string name)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор з параметрами класу Department - " << this << endl << endl;
#endif 
	for (auto item = _workersAA.begin(); item != _workersAA.end(); item++)
	{
		_workersAA.emplace_back(*item);
	}
	for (auto item = _workersBA.begin(); item != _workersBA.end(); item++)
	{
		_workersBA.emplace_back(*item);
	}
	for (auto item = _workersMS.begin(); item != _workersMS.end(); item++)
	{
		_workersMS.emplace_back(*item);
	}
	_name = name;
}

Department::Department(const Department& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор копіювання класу Department - " << this << endl << endl;
#endif
	for (auto item = other._workersAA.begin(); item != other._workersAA.end(); item++)
	{
		_workersAA.emplace_back(*item);
	}
	for (auto item = other._workersBA.begin(); item != other._workersBA.end(); item++)
	{
		_workersBA.emplace_back(*item);
	}
	for (auto item = other._workersMS.begin(); item != other._workersMS.end(); item++)
	{
		_workersMS.emplace_back(*item);
	}
	_name = other._name;
}

Department::~Department()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Department - " << this << endl << endl;
#endif 
}

string Department::GetName()
{
	string newName = _name;
	return newName;
}

vector<AdministrativeAssistant> Department::GetWorkersAA()
{
	vector<AdministrativeAssistant> vAA;
	AdministrativeAssistant firstAA;
	vAA.push_back(firstAA);
	vAA[vAA.size() - 1].Set(_workersAA[0].GetName(), _workersAA[0].GetAge(), _workersAA[0].GetExperience(), _workersAA[0].GetPayment(), _workersAA[0].GetWorkingPlace());
	for (auto item = _workersAA.begin() + 1; item != _workersAA.end(); item++)
	{
		vAA.emplace_back(*item);
	}
	return vAA;
}

vector<BusinessAnalyst> Department::GetWorkersBA()
{
	vector<BusinessAnalyst> vBA;
	BusinessAnalyst firstBA;
	vBA.push_back(firstBA);
	vBA[vBA.size() - 1].Set(_workersBA[0].GetName(), _workersBA[0].GetAge(), _workersBA[0].GetExperience(), _workersBA[0].GetPayment(), _workersBA[0].GetWorkingPlace());
	for (auto item = _workersBA.begin() + 1; item != _workersBA.end(); item++)
	{
		vBA.emplace_back(*item);
	}
	return vBA;
}

vector<MarketingSpecialist> Department::GetWorkersMS()
{
	vector<MarketingSpecialist> vMS;
	MarketingSpecialist firstMS;
	vMS.push_back(firstMS);
	vMS[vMS.size() - 1].Set(_workersMS[0].GetName(), _workersMS[0].GetAge(), _workersMS[0].GetExperience(), _workersMS[0].GetPayment(), _workersMS[0].GetWorkingPlace());
	for (auto item = _workersMS.begin() + 1; item != _workersMS.end(); item++)
	{
		vMS.emplace_back(*item);
	}
	return vMS;
}

void Department::Set(vector<AdministrativeAssistant> workersAA, vector<BusinessAnalyst> workersBA, vector<MarketingSpecialist> workersMS, string name)
{
	for (auto item = workersAA.begin(); item != workersAA.end(); item++)
	{
		_workersAA.emplace_back(*item);
	}
	for (auto item = workersBA.begin(); item != workersBA.end(); item++)
	{
		_workersBA.emplace_back(*item);
	}
	for (auto item = workersMS.begin(); item != workersMS.end(); item++)
	{
		_workersMS.emplace_back(*item);
	}
	_name = name;
}

void Department::SetWorkersAA(vector<AdministrativeAssistant> workersAA)
{
	_workersAA.empty();
	for (auto item = workersAA.begin(); item != workersAA.end(); item++)
	{
		_workersAA.emplace_back(*item);
	}
}

void Department::SetWorkersBA(vector<BusinessAnalyst> workersBA)
{
	_workersBA.empty();
	for (auto item = workersBA.begin(); item != workersBA.end(); item++)
	{
		_workersBA.emplace_back(*item);
	}
}

void Department::SetWorkersMS(vector<MarketingSpecialist> workersMS)
{
	_workersMS.empty();
	for (auto item = workersMS.begin(); item != workersMS.end(); item++)
	{
		_workersMS.emplace_back(*item);
	}
}

void Department::SetName(string name)
{
	_name = name;
}

void Department::InsertAnAA(const AdministrativeAssistant* newWorker)
{
	_workersAA.push_back(*newWorker);
}

void Department::InsertABA(const BusinessAnalyst* newWorker)
{
	_workersBA.push_back(*newWorker);
}

void Department::InsertAMS(const MarketingSpecialist* newWorker)
{
	_workersMS.push_back(*newWorker);
}

void Department::Show()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Назва: " << _name << endl;
	cout << "Працівники в цьому відділі:";
	int counter = 1;
	for (auto worker : _workersAA)
	{
		cout << "Працівник №" << counter << ":";
		worker.Show();
		counter++;
	}
	for (auto worker : _workersBA)
	{
		cout << "Працівник №" << counter << ":";
		worker.Show();
		counter++;
	}
	for (auto worker : _workersMS)
	{
		cout << "Працівник №" << counter << ":";
		worker.Show();
		counter++;
	}
#endif 
}