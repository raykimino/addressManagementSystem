/*
利用C++实现一个通讯录管理系统，实现的功能如下
添加联系人：向通讯录中添加新联系人，信息包括（性别，姓名，年龄，电话住址），最多1000人
显示联系人：显示通讯录中所有人的信息
删除联系人：按照姓名进行删除指定联系人
查找联系人：按照姓名查看联系人的信息
修改联系人：按照姓名重新修改联系人
清空联系人：清空通讯录中所有信息
退出通讯录：退出当前程序
*/

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
	string Name;
	string Sex;
	int Age;
	string phoneNumber;
	string Address;
};

struct addressManagement
{
	struct Person personArray[MAX];
	int p_Number;//通讯录人数
};

//添加联系人
void addPerson(addressManagement* ex)
{
	//判断通讯录是否已满
	if (ex->p_Number == MAX)
	{
		cout << "通讯录已满无法添加" << endl;
		exit(0);
	}
	else
	{
		cout << "请输入添加到通讯录的人数为：" << endl;
		int Count;
		cin >> Count;
		ex->p_Number = Count;
		if (Count < 1 || Count>1000)
		{
			cout << "非法数据，程序退出" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < Count; i++)
			{
				cout << "请输入第" << i + 1 << "位联系人的姓名:";
				string name;
				cin >> name;
				ex->personArray[i].Name = name;

				cout << endl;

				cout << "请输入第" << i + 1 << "位联系人的性别:";
				string sex;
				cin >> sex;
				ex->personArray[i].Sex = sex;

				cout << endl;

				cout << "请输入第" << i + 1 << "位联系人的年龄:";
				int age;
				cin >> age;
				ex->personArray[i].Age = age;

				cout << endl;

				cout << "请输入第" << i + 1 << "位联系人的电话:";
				string phone_number;
				cin >> phone_number;
				ex->personArray[i].phoneNumber = phone_number;

				cout << endl;

				cout << "请输入第" << i + 1 << "位联系人的联系地址:";
				string address;
				cin >> address;
				ex->personArray[i].Address = address;

				cout << endl;
			}
			
			cout << endl;
			cout << "添加完成" << endl;
		}
	}
}

//显示所有联系人
void showPersonInfo(addressManagement* ex)
{
	if (ex->p_Number == 0)
	{
		cout << "当前通讯录没有记录！" << endl;
		return;
	}
	else {
		cout << "姓名 " << "性别 " << "年龄 " << "电话 " << "住址" << endl;
		for (int i = 0; i < ex->p_Number; i++)
		{
			cout << ex->personArray[i].Name << "    "
				<< ex->personArray[i].Sex << "    "
				<< ex->personArray[i].Age << "    "
				<< ex->personArray[i].phoneNumber << "    "
				<< ex->personArray[i].Address << endl;
		}
	}
}

//判断是否存在
int isExist(addressManagement* ex, string name)
{
	for (int i = 0; i < ex->p_Number; i++)
	{
		if (ex->personArray[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePersomInfo(addressManagement* ex, string name, int e)
{
	for (int i = e; i < ex->p_Number; i++)
	{
		ex->personArray[i] = ex->personArray[i + 1];
	}
	ex->p_Number--;
	cout << "删除完成" << endl;
}


//修改联系人
void changePersonInfo(addressManagement* ex, int e)
{
	int change = 1;
	int sel;
	string name;
	string sex;
	int age;
	string phone_number;
	string address;

	while (change)
	{
		cout << "1,修改姓名" << endl;
		cout << "2,修改性别" << endl;
		cout << "3,修改年龄" << endl;
		cout << "4,修改电话" << endl;
		cout << "5,修改住址" << endl;
		cout << "6,完成修改" << endl;
		cout << "输入修改的选项:";
		cin >> sel;
		if (sel < 1 || sel>6)
		{
			cout << "非法输入！" << endl;
			return;
		}
		else {
			switch (sel)
			{
			case 1:
				cout << "输入修改后的姓名：";
				cin >> name;
				ex->personArray[e].Name = name;
				break;
			case 2:
				cout << "输入修改后的性别：";
				cin >> sex;
				ex->personArray[e].Sex = sex;
				break;
			case 3:
				cout << "输入修改后的年龄：";
				cin >> age;
				ex->personArray[e].Age = age;
				break;
			case 4:
				cout << "输入修改后的电话：";
				cin >> phone_number;
				ex->personArray[e].phoneNumber = phone_number;
				break;
			case 5:
				break;
			case 6:
				change = 0;
				break;
			}
		}
		
	}
	cout << endl;
}

//清空通讯录
void clearPersonInfo(addressManagement* ex)
{
	ex->p_Number = 0;
	cout << "已清空通讯录" << endl;
}

//菜单
void Menu()
{
	cout << "************************" << endl;
	cout << "***** 1,添加联系人 *****" << endl;
	cout << "***** 2,显示联系人 *****" << endl;
	cout << "***** 3,删除联系人 *****" << endl;
	cout << "***** 4,查找联系人 *****" << endl;
	cout << "***** 5,修改联系人 *****" << endl;
	cout << "***** 6,清空联系人 *****" << endl;
	cout << "***** 0,退出程序 *******" << endl; 
	cout << "************************" << endl;
}


int main()
{
	//初始化
	addressManagement am;
	am.p_Number = 0;



	int n;
	string name_in1;
	string name_in2;
	string name_in3;
	while (1)
	{
		
		Menu();
		cout << "输入您的选择：";
		cin >> n;
		if (n < 1 || n>6)
		{
			cout << "非法数据" << endl;
			return 0;
		}
		cout << endl;
		switch (n)
		{
		case 1:
			addPerson(&am);
			break;
		case 2:
			showPersonInfo(&am);
			break;
		case 3:
			cout << "请输入删除联系人的姓名：";
			cin >> name_in1;
			if (isExist(&am, name_in1) == -1)
			{
				cout << "NOT FOUND 查无此人" << endl;
				break;
			}
			else {
				int number1 = isExist(&am, name_in1);
				cout << "查找成功，准备删除" << endl;
				deletePersomInfo(&am, name_in1, number1);
			}
			break;
		case 4:
			cout << "请输入查找联系人的姓名：";
			cin >> name_in2;
			if (isExist(&am, name_in2) == -1)
			{
				cout << "NOT FOUND 查无此人" << endl;
				break;
			}
			else {
				int number2 = isExist(&am, name_in2);
				cout << "查找成功" << endl
					<< "姓名：" << am.personArray[number2].Name << " "
					<< "性别" << am.personArray[number2].Sex << " "
					<< "年龄" << am.personArray[number2].Age << " "
					<< "电话" << am.personArray[number2].phoneNumber << " "
					<< "地址" << am.personArray[number2].Address << endl;
			}
			break;
		case 5:
			cout << "请输入修改原联系人的姓名：";
			cin >> name_in3;
			if (isExist(&am, name_in3) == -1)
			{
				cout << "NOT FOUND 查无此人" << endl;
				break;
			}else{
				cout << "查询成功" << endl;
				int number3 = isExist(&am, name_in3);
				changePersonInfo(&am, number3);
			}
			break;
		case 6:clearPersonInfo(&am);
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}