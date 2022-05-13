#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include "Enterprise.h"

int main(void)
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	AdministrativeAssistant AA1, AA2;
	MarketingSpecialist MS1, MS2;
	BusinessAnalyst BA1, BA2;
	AA1.Set("Georgiy", 30, 10, 3400, false);
	AA2.Set("Vitaliy", 40, 15, 6000, false);
	BA1.Set("Georgiy", 30, 10, 3400, false);
	BA2.Set("Vitaliy", 40, 15, 6000, false);
	MS1.Set("Georgiy", 30, 10, 3400, false);
	MS2.Set("Vitaliy", 40, 15, 6000, false);
	vector<AdministrativeAssistant> vAA;
	vAA.emplace_back(AA1);
	vAA.emplace_back(AA2);
	vector<BusinessAnalyst> vBA;
	vBA.emplace_back(BA1);
	vBA.emplace_back(BA2);
	vector<MarketingSpecialist> vMS;
	vMS.emplace_back(MS1);
	vMS.emplace_back(MS2);
	Department dep;
	vector<Department> items;
	dep.Set(vAA, vBA, vMS, "Virginia");
	items.push_back(dep);
	Date createdAt;
	createdAt.Set("2020", "10", 10);
	string name = "bla";
	string owner = "blabla";
	double proceeds = 200;
	try
	{
		Enterprise enterprise(items,&createdAt,name,owner,proceeds);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	_getch();
	return 0;
}