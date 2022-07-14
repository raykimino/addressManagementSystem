/*
����C++ʵ��һ��ͨѶ¼����ϵͳ��ʵ�ֵĹ�������
�����ϵ�ˣ���ͨѶ¼���������ϵ�ˣ���Ϣ�������Ա����������䣬�绰סַ�������1000��
��ʾ��ϵ�ˣ���ʾͨѶ¼�������˵���Ϣ
ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
������ϵ�ˣ����������鿴��ϵ�˵���Ϣ
�޸���ϵ�ˣ��������������޸���ϵ��
�����ϵ�ˣ����ͨѶ¼��������Ϣ
�˳�ͨѶ¼���˳���ǰ����
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
	int p_Number;//ͨѶ¼����
};

//�����ϵ��
void addPerson(addressManagement* ex)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (ex->p_Number == MAX)
	{
		cout << "ͨѶ¼�����޷����" << endl;
		exit(0);
	}
	else
	{
		cout << "��������ӵ�ͨѶ¼������Ϊ��" << endl;
		int Count;
		cin >> Count;
		ex->p_Number = Count;
		if (Count < 1 || Count>1000)
		{
			cout << "�Ƿ����ݣ������˳�" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < Count; i++)
			{
				cout << "�������" << i + 1 << "λ��ϵ�˵�����:";
				string name;
				cin >> name;
				ex->personArray[i].Name = name;

				cout << endl;

				cout << "�������" << i + 1 << "λ��ϵ�˵��Ա�:";
				string sex;
				cin >> sex;
				ex->personArray[i].Sex = sex;

				cout << endl;

				cout << "�������" << i + 1 << "λ��ϵ�˵�����:";
				int age;
				cin >> age;
				ex->personArray[i].Age = age;

				cout << endl;

				cout << "�������" << i + 1 << "λ��ϵ�˵ĵ绰:";
				string phone_number;
				cin >> phone_number;
				ex->personArray[i].phoneNumber = phone_number;

				cout << endl;

				cout << "�������" << i + 1 << "λ��ϵ�˵���ϵ��ַ:";
				string address;
				cin >> address;
				ex->personArray[i].Address = address;

				cout << endl;
			}
			
			cout << endl;
			cout << "������" << endl;
		}
	}
}

//��ʾ������ϵ��
void showPersonInfo(addressManagement* ex)
{
	if (ex->p_Number == 0)
	{
		cout << "��ǰͨѶ¼û�м�¼��" << endl;
		return;
	}
	else {
		cout << "���� " << "�Ա� " << "���� " << "�绰 " << "סַ" << endl;
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

//�ж��Ƿ����
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

//ɾ����ϵ��
void deletePersomInfo(addressManagement* ex, string name, int e)
{
	for (int i = e; i < ex->p_Number; i++)
	{
		ex->personArray[i] = ex->personArray[i + 1];
	}
	ex->p_Number--;
	cout << "ɾ�����" << endl;
}


//�޸���ϵ��
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
		cout << "1,�޸�����" << endl;
		cout << "2,�޸��Ա�" << endl;
		cout << "3,�޸�����" << endl;
		cout << "4,�޸ĵ绰" << endl;
		cout << "5,�޸�סַ" << endl;
		cout << "6,����޸�" << endl;
		cout << "�����޸ĵ�ѡ��:";
		cin >> sel;
		if (sel < 1 || sel>6)
		{
			cout << "�Ƿ����룡" << endl;
			return;
		}
		else {
			switch (sel)
			{
			case 1:
				cout << "�����޸ĺ��������";
				cin >> name;
				ex->personArray[e].Name = name;
				break;
			case 2:
				cout << "�����޸ĺ���Ա�";
				cin >> sex;
				ex->personArray[e].Sex = sex;
				break;
			case 3:
				cout << "�����޸ĺ�����䣺";
				cin >> age;
				ex->personArray[e].Age = age;
				break;
			case 4:
				cout << "�����޸ĺ�ĵ绰��";
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

//���ͨѶ¼
void clearPersonInfo(addressManagement* ex)
{
	ex->p_Number = 0;
	cout << "�����ͨѶ¼" << endl;
}

//�˵�
void Menu()
{
	cout << "************************" << endl;
	cout << "***** 1,�����ϵ�� *****" << endl;
	cout << "***** 2,��ʾ��ϵ�� *****" << endl;
	cout << "***** 3,ɾ����ϵ�� *****" << endl;
	cout << "***** 4,������ϵ�� *****" << endl;
	cout << "***** 5,�޸���ϵ�� *****" << endl;
	cout << "***** 6,�����ϵ�� *****" << endl;
	cout << "***** 0,�˳����� *******" << endl; 
	cout << "************************" << endl;
}


int main()
{
	//��ʼ��
	addressManagement am;
	am.p_Number = 0;



	int n;
	string name_in1;
	string name_in2;
	string name_in3;
	while (1)
	{
		
		Menu();
		cout << "��������ѡ��";
		cin >> n;
		if (n < 1 || n>6)
		{
			cout << "�Ƿ�����" << endl;
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
			cout << "������ɾ����ϵ�˵�������";
			cin >> name_in1;
			if (isExist(&am, name_in1) == -1)
			{
				cout << "NOT FOUND ���޴���" << endl;
				break;
			}
			else {
				int number1 = isExist(&am, name_in1);
				cout << "���ҳɹ���׼��ɾ��" << endl;
				deletePersomInfo(&am, name_in1, number1);
			}
			break;
		case 4:
			cout << "�����������ϵ�˵�������";
			cin >> name_in2;
			if (isExist(&am, name_in2) == -1)
			{
				cout << "NOT FOUND ���޴���" << endl;
				break;
			}
			else {
				int number2 = isExist(&am, name_in2);
				cout << "���ҳɹ�" << endl
					<< "������" << am.personArray[number2].Name << " "
					<< "�Ա�" << am.personArray[number2].Sex << " "
					<< "����" << am.personArray[number2].Age << " "
					<< "�绰" << am.personArray[number2].phoneNumber << " "
					<< "��ַ" << am.personArray[number2].Address << endl;
			}
			break;
		case 5:
			cout << "�������޸�ԭ��ϵ�˵�������";
			cin >> name_in3;
			if (isExist(&am, name_in3) == -1)
			{
				cout << "NOT FOUND ���޴���" << endl;
				break;
			}else{
				cout << "��ѯ�ɹ�" << endl;
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