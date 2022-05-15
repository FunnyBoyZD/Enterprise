#define _CRT_SECURE_NO_WARNINGS 
#include "conio.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include <algorithm>
#include "Enterprise.h"

int main(void)
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	try
	{
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

		Enterprise enterprise(items, createdAt, name, owner, proceeds);

		cout << "===Корпорація до додавання нового відділу та робітників:===" << endl;
		enterprise.Show();

		Department dep3;
		AdministrativeAssistant AA3_1, AA3_2;
		MarketingSpecialist MS3_1, MS3_2;
		BusinessAnalyst BA3_1, BA3_2;

		AA3_1.Set("Тетяна", 30, 10, 30000, true);
		AA3_2.Set("Ірина", 40, 15, 32000, true);
		BA3_1.Set("Наталья", 20, 2, 31000, false);
		BA3_2.Set("Джесіка", 36, 18, 48000, false);
		MS3_1.Set("Ярослава", 28, 10, 37000, true);
		MS3_2.Set("Яворина", 25, 5, 34000, false);

		vector<AdministrativeAssistant> vAA3;
		vAA3.emplace_back(AA3_1);
		vAA3.emplace_back(AA3_2);
		vector<BusinessAnalyst> vBA3;
		vBA3.emplace_back(BA3_1);
		vBA3.emplace_back(BA3_2);
		vector<MarketingSpecialist> vMS3;
		vMS3.emplace_back(MS3_1);
		vMS3.emplace_back(MS3_2);

		dep3.Set(vAA3, vBA3, vMS3, "Людські ресурси");
		enterprise.Insert(&dep3);

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

		cout << "Імена службовців зі стажем не менше 10 років:" << endl;
		int numOfDep = enterprise.GetNumberOfDepartments();
		for (int i = 1; i <= numOfDep; i++)
		{
			auto vAA5 = enterprise.GetDepartment(i)->GetWorkersAA();
			vector<AdministrativeAssistant> correctAA;
			copy_if(vAA5.begin(), vAA5.end(), back_inserter(correctAA), [](const AdministrativeAssistant& AA)
				{
					return const_cast<AdministrativeAssistant*>(&AA)->GetExperience() >= 10;
				});
			for (auto AA : correctAA)
			{
				cout << AA.GetName() << endl;
			}

			auto vBA5 = enterprise.GetDepartment(i)->GetWorkersBA();
			vector<BusinessAnalyst> correctBA;
			copy_if(vBA5.begin(), vBA5.end(), back_inserter(correctBA), [](const BusinessAnalyst& BA)
				{
					return const_cast<BusinessAnalyst*>(&BA)->GetExperience() >= 10;
				});
			for (auto BA : correctBA)
			{
				cout << BA.GetName() << endl;
			}

			auto vMS5 = enterprise.GetDepartment(i)->GetWorkersMS();
			vector<MarketingSpecialist> correctMS;
			copy_if(vMS5.begin(), vMS5.end(), back_inserter(correctMS), [](const MarketingSpecialist& MS)
				{
					return const_cast<MarketingSpecialist*>(&MS)->GetExperience() >= 10;
				});
			for (auto MS : correctMS)
			{
				cout << MS.GetName() << endl;
			}
		}

		cout << endl << endl << "Імена всіх бізнес-аналітиків корпорації:" << endl;
		for (int i = 1; i <= numOfDep; i++)
		{
			auto vBA6 = enterprise.GetDepartment(i)->GetWorkersBA();
			for (auto BA : vBA6)
			{
				cout << BA.GetName() << endl;
			}
		}
	}
	catch (const out_of_range&)
	{
		cout << "Ви не передали колекцію для задання!" << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
