//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//struct student
//{
//	void set(const char* name, int age, double score)//void set(const char* name, int age, double score.student*const this)
//	{
//		strcpy(_name, name);//�ײ���strcpy(this->_name,name)
//		_age = age;//�ײ���this->_age=age;
//		_score = score;//�ײ���this->_score=score;
//	}
//	void print()//void print(student*const this)
//	{
//		cout << "name :" << _name << endl;//�ײ���cout<<this->_name<<endl;
//		cout << "age:" << _age << endl;
//		cout << "score" << _score << endl;
//	}
//	char _name[15];
//	int _age;
//	double _score;
//};
//void test02()
//{
//	student* m1=nullptr;
//	m1->set("����", 18, 20);
//	m1->print();
//}
//void test01()
//{
//	student m1;
//	m1.set("����", 20, 98.9);//�ײ�������Ὣ���Ϊset("����", 20, 98.9,&m1);
//	m1.print();//�ײ�������Ὣ���Ϊprint(&m1);
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int year, month, day, times, add;
    cin >> times;
    int arr[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    while (times--)
    {
        cin >> year >> month >> day >> add;
        if ((year % 4 == 0 && year % 100 != 0))
        {
            day = day + add;
            if (day > arr[month - 1])
            {
                while (day > arr[month - 1])
                {
                    day -= arr[month - 1];
                    month += 1;
                    if (month > 12)
                    {
                        month = 1;
                        year += 1;
                    }
                }
            }
            day -= 1;
        }
        else
        {
            arr[1] -= 1;
            day = day + add;
            if (day > arr[month - 1])
            {
                while (day > arr[month - 1])
                {
                    day -= arr[month - 1];
                    month += 1;
                    if (month > 12)
                    {
                        month = 1;
                        year += 1;
                    }
                }
            }
            arr[1] += 1;
        }
        cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << endl;
    }
    return 0;
}