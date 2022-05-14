#define _CRT_SECURE_NO_WARNINGS 
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

	AdministrativeAssistant AA1_1, AA1_2, AA2_1, AA2_2;
	MarketingSpecialist MS1_1, MS1_2, MS2_1, MS2_2;
	BusinessAnalyst BA1_1, BA1_2, BA2_1, BA2_2;

	AA1_1.Set("Anastasia", 30, 10, 30000, true);
	AA1_2.Set("Elisaveta", 40, 15, 32000, true);
	BA1_1.Set("Galina", 20, 2, 31000, false);
	BA1_2.Set("Stephania", 36, 18, 48000, false);
	MS1_1.Set("Elvira", 28, 10, 37000, true);
	MS1_2.Set("Veronika", 25, 5, 34000, false);

	AA2_1.Set("Georgiy", 40, 20, 50000, true);
	AA2_2.Set("Vitaliy", 20, 1, 32000, true);
	BA2_1.Set("Oleksii", 24, 3, 45000, false);
	BA2_2.Set("Oleksandr", 38, 19, 65000, false);
	MS2_1.Set("Serhiy", 19, 1, 20000, false);
	MS2_2.Set("Svyatoslav", 26, 7, 34000, true);

	vector<AdministrativeAssistant> vAA1;
	vAA1.emplace_back(AA1_1);
	vAA1.emplace_back(AA1_2);
	vector<BusinessAnalyst> vBA1;
	vBA1.emplace_back(BA1_1);
	vBA1.emplace_back(BA1_2);
	vector<MarketingSpecialist> vMS1;
	vMS1.emplace_back(MS1_1);
	vMS1.emplace_back(MS1_2);

	vector<AdministrativeAssistant> vAA2;
	vAA2.emplace_back(AA2_1);
	vAA2.emplace_back(AA2_2);
	vector<BusinessAnalyst> vBA2;
	vBA2.emplace_back(BA2_1);
	vBA2.emplace_back(BA2_2);
	vector<MarketingSpecialist> vMS2;
	vMS2.emplace_back(MS2_1);
	vMS2.emplace_back(MS2_2);

	Department dep1, dep2;
	vector<Department> items;
	dep1.Set(vAA1, vBA1, vMS1, "Marketing");
	dep2.Set(vAA2, vBA2, vMS2, "Finance");
	items.push_back(dep1);
	items.push_back(dep2);
	Date createdAt;
	createdAt.Set("2000", "10", 10);
	string name = "NVIDIA Corp.";
	string owner = "Jen-Hsun Huang";
	double proceeds = 7640000000;
	try
	{
		Enterprise enterprise(items, createdAt,name,owner,proceeds);
		enterprise.Show();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	_getch();
	return 0;
}
