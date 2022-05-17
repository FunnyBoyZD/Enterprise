#define _CRT_SECURE_NO_WARNINGS 
#include "conio.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include <algorithm>
#include "Enterprise.h"

void SortWorkers(vector<Employee*>& workers);

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        AdministrativeAssistant AA1_1, AA1_2, AA2_1, AA2_2;
        MarketingSpecialist MS1_1, MS1_2, MS2_1, MS2_2;
        BusinessAnalyst BA1_1, BA1_2, BA2_1, BA2_2;

        AA1_1.Set("Анастасія", "Помічник адміністратора", 30, 10, 30000, true);
        AA1_2.Set("Єлизавета", "Помічник адміністратора", 40, 15, 32000, true);
        BA1_1.Set("Галина", "Бізнес-аналітик", 20, 2, 31000, false);
        BA1_2.Set("Стефанія", "Бізнес-аналітик", 36, 18, 48000, false);
        MS1_1.Set("Ельвіра", "Спеціаліст з маркетингу", 28, 10, 37000, true);
        MS1_2.Set("Вероніка", "Спеціаліст з маркетингу", 25, 5, 34000, false);

        AA2_1.Set("Георгій", "Помічник адміністратора", 40, 20, 50000, true);
        AA2_2.Set("Віталій", "Помічник адміністратора", 20, 1, 32000, true);
        BA2_1.Set("Олексій", "Бізнес-аналітик", 24, 3, 45000, false);
        BA2_2.Set("Олександр", "Бізнес-аналітик", 38, 19, 65000, false);
        MS2_1.Set("Сергій", "Спеціаліст з маркетингу", 19, 1, 20000, false);
        MS2_2.Set("Святослав", "Спеціаліст з маркетингу", 26, 7, 34000, true);

        vector<Employee*> vWorkers1;
        vWorkers1.emplace_back(&BA1_1);
        vWorkers1.emplace_back(&AA1_1);
        vWorkers1.emplace_back(&MS1_1);
        vWorkers1.emplace_back(&BA1_2);
        vWorkers1.emplace_back(&AA1_2);
        vWorkers1.emplace_back(&MS1_2);
        SortWorkers(vWorkers1);

        vector<Employee*> vWorkers2;
        vWorkers2.emplace_back(&MS2_2);
        vWorkers2.emplace_back(&AA2_2);
        vWorkers2.emplace_back(&BA2_1);
        vWorkers2.emplace_back(&MS2_1);
        vWorkers2.emplace_back(&AA2_1);
        vWorkers2.emplace_back(&BA2_2);
        SortWorkers(vWorkers2);

        Department dep1, dep2;
        vector<Department> items;
        dep1.Set(vWorkers1, "Маркетинг");
        dep2.Set(vWorkers2, "Фінанси");
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

        AA3_1.Set("Тетяна", "Помічник адміністратора", 30, 10, 30000, true);
        AA3_2.Set("Ірина", "Помічник адміністратора", 40, 15, 32000, true);
        BA3_1.Set("Наталья", "Бізнес-аналітик", 20, 2, 31000, false);
        BA3_2.Set("Джесіка", "Бізнес-аналітик", 36, 18, 48000, false);
        MS3_1.Set("Ярослава", "Спеціаліст з маркетингу", 28, 10, 37000, true);
        MS3_2.Set("Яворина", "Спеціаліст з маркетингу", 25, 5, 34000, false);

        vector<Employee*> vWorkers3;
        vWorkers3.emplace_back(&BA3_1);
        vWorkers3.emplace_back(&AA3_1);
        vWorkers3.emplace_back(&MS3_1);
        vWorkers3.emplace_back(&AA3_2);
        vWorkers3.emplace_back(&BA3_2);
        vWorkers3.emplace_back(&MS3_2);
        SortWorkers(vWorkers3);

        dep3.Set(vWorkers3, "Людські ресурси");
        enterprise.Insert(&dep3);

        BusinessAnalyst newBA;
        newBA.Set("Ігор", "Бізнес-аналітик", 26, 4, 44000, false);
        AdministrativeAssistant newAA;
        newAA.Set("Хрістіна", "Помічник адміністратора", 23, 1, 21000, true);
        MarketingSpecialist newMS;
        newMS.Set("Майкл", "Спеціаліст з маркетингу", 47, 23, 67000, false);
        enterprise.GetDepartment(1)->Insert(&newBA, "Бізнес-аналітик");
        enterprise.GetDepartment(1)->Insert(&newAA, "Помічник адміністратора");
        enterprise.GetDepartment(1)->Insert(&newMS, "Спеціаліст з маркетингу");

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

/*
Функція сортування співробітників за професіями
Вхід:
    workers - робітники для сортування, передача за посиланням
Вихід: відсутній
*/
void SortWorkers(vector<Employee*>& workers)
{
    static_cast<void>(workers.at(0));
    vector<Employee*> workersAA;
    copy_if(workers.begin(), workers.end(), back_inserter(workersAA), [](Employee*& workerAA)
        {
            return workerAA->GetProfession() == "Помічник адміністратора";
        });
    vector<Employee*> workersBA;
    copy_if(workers.begin(), workers.end(), back_inserter(workersBA), [](Employee*& workerBA)
        {
            return workerBA->GetProfession() == "Бізнес-аналітик";
        });
    vector<Employee*> workersMS;
    copy_if(workers.begin(), workers.end(), back_inserter(workersMS), [](Employee*& workerMS)
        {
            return workerMS->GetProfession() == "Спеціаліст з маркетингу";
        });
    workers.clear();
    for (auto item : workersAA)
    {
        workers.emplace_back(item);
    }
    for (auto item : workersBA)
    {
        workers.emplace_back(item);
    }
    for (auto item : workersMS)
    {
        workers.emplace_back(item);
    }
}
