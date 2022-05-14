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

	cout << "===Перша частина демонстрації роботи програми:===" << endl;
	AdministrativeAssistant AA1_1, AA1_2, AA2_1, AA2_2;
	MarketingSpecialist MS1_1, MS1_2, MS2_1, MS2_2;
	BusinessAnalyst BA1_1, BA1_2, BA2_1, BA2_2;

	AA1_1.Set("Анастасія", 30, 10, 30000, true);
	AA1_2.Set("Єлизавета", 40, 15, 32000, true);
	BA1_1.Set("Галина", 20, 2, 31000, false);
	BA1_2.Set("Стефанія", 36, 18, 48000, false);
	MS1_1.Set("Ельвіра", 28, 10, 37000, true);
	MS1_2.Set("Вероніка", 25, 5, 34000, false);

	AA2_1.Set("Георгій", 40, 20, 50000, true);
	AA2_2.Set("Віталій", 20, 1, 32000, true);
	BA2_1.Set("Олексій", 24, 3, 45000, false);
	BA2_2.Set("Олександр", 38, 19, 65000, false);
	MS2_1.Set("Сергій", 19, 1, 20000, false);
	MS2_2.Set("Святослав", 26, 7, 34000, true);

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
	dep1.Set(vAA1, vBA1, vMS1, "Маркетинг");
	dep2.Set(vAA2, vBA2, vMS2, "Фінанси");
	items.push_back(dep1);
	items.push_back(dep2);
	Date createdAt;
	createdAt.Set("2000", "10", 10);
	string name = "NVIDIA Corp.";
	string owner = "Джен-Хсун Хуанг";
	double proceeds = 7640000000;
	try
	{
		Enterprise enterprise(items, createdAt,name,owner,proceeds);

		cout << "===Корпорація до додавання нового відділу та робітників:===" << endl;
		enterprise.Show();

		Department dep3;
		AdministrativeAssistant AA3_1, AA3_2, AA4_1, AA4_2;
		MarketingSpecialist MS3_1, MS3_2, MS4_1, MS4_2;
		BusinessAnalyst BA3_1, BA3_2, BA4_1, BA4_2;

		AA3_1.Set("Тетяна", 30, 10, 30000, true);
		AA3_2.Set("Ірина", 40, 15, 32000, true);
		BA3_1.Set("Наталья", 20, 2, 31000, false);
		BA3_2.Set("Джесіка", 36, 18, 48000, false);
		MS3_1.Set("Ярослава", 28, 10, 37000, true);
		MS3_2.Set("Яворина", 25, 5, 34000, false);

		AA4_1.Set("Джордж", 40, 20, 50000, true);
		AA4_2.Set("Джек", 20, 1, 32000, true);
		BA4_1.Set("Дмитро", 24, 3, 45000, false);
		BA4_2.Set("Стефан", 38, 19, 65000, false);
		MS4_1.Set("Джозеф", 19, 1, 20000, false);
		MS4_2.Set("Зигмунд", 26, 7, 34000, true);

		vector<AdministrativeAssistant> vAA3;
		vAA3.emplace_back(AA3_1);
		vAA3.emplace_back(AA3_2);
		vector<BusinessAnalyst> vBA3;
		vBA3.emplace_back(BA3_1);
		vBA3.emplace_back(BA3_2);
		vector<MarketingSpecialist> vMS3;
		vMS3.emplace_back(MS3_1);
		vMS3.emplace_back(MS3_2);

		vector<AdministrativeAssistant> vAA4;
		vAA4.emplace_back(AA4_1);
		vAA4.emplace_back(AA4_2);
		vector<BusinessAnalyst> vBA4;
		vBA4.emplace_back(BA4_1);
		vBA4.emplace_back(BA4_2);
		vector<MarketingSpecialist> vMS4;
		vMS4.emplace_back(MS4_1);
		vMS4.emplace_back(MS4_2);
		
		BusinessAnalyst newBA;
		newBA.Set("Ігор", 26, 4, 44000, false);
		AdministrativeAssistant newAA;
		newAA.Set("Хрістіна", 23, 1, 21000, true);
		MarketingSpecialist newMS;
		newMS.Set("Майкл", 47, 23, 67000, false);
		enterprise.GetDepartment(1)->InsertABA(&newBA);
		enterprise.GetDepartment(1)->InsertAnAA(&newAA);
		enterprise.GetDepartment(1)->InsertAMS(&newMS);

		cout << "===Корпорація після додавання нового відділу та робітників:===" << endl;
		enterprise.Show();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
