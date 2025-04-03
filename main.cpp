#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000
//�����ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;

	//�Ա�	1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks 
{
	//ͨѶ¼�б�������������
	struct Person presonArray[MAX];
	//ͨѶ¼�б�����ϵ�˵ĸ���
	int m_Size;
};
//1.��ӹ���
void addPerson(Addressbooks* ads)
{
	//���ж������Ƿ���
	if (ads->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӡ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "��������" << endl;
		cin >> name;
		ads->presonArray[ads->m_Size].m_Name = name;
		//�Ա�
		cout << "����������" << endl;
		cout << "1---�У�2----Ů" << endl;
		int sex;
		while (true) {
			cin >> sex;//�����ѭ����
			if (sex == 1 || sex == 2) {
				ads->presonArray[ads->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "����������" << endl;
			}
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		while (true) {
			cin >> age;//�����ѭ����
			if (age>0 && age<150) {
				ads->presonArray[ads->m_Size].m_Age = age;
				break;
			}
			cout << "����������" << endl;
		}
		//�绰
		string phone;
		cout << "����绰����" << endl;
		cin >> phone;
		ads->presonArray[ads->m_Size].m_Phone = phone;
		//סַ
		string addr;
		cout << "�������ַ" << endl;
		cin >> addr;
		ads->presonArray[ads->m_Size].m_Addr = addr;

		//��������
		ads->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//����
	}
}
//2.��ʾ����
void showPerson(Addressbooks* ads)
{
	if (ads->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_Size; i++) {
			cout << "������" << ads->presonArray[i].m_Name << "\t";
			cout << "�Ա�" << (ads->presonArray[i].m_Sex == 1 ? "��" :"Ů") << "\t";
			cout << "���䣺" << ads->presonArray[i].m_Age << "\t";
			cout << "�绰��" << ads->presonArray[i].m_Phone << "\t";
			cout << "סַ��" << ads->presonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//3.�ж���ϵ���Ƿ����,���ڷ��ص�ַ�����򷵻�-1
int isExist(Addressbooks* ads, string name)
{
	for (int i = 0; i < ads->m_Size; i++)
	{
		if (ads->presonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//4.ɾ����ϵ��
void deletePerson(Addressbooks* ads)
{
	cout << "����ɾ����������" << endl;
	string name;
	cin >> name;
	if (isExist(ads, name) == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		for (int i=0; i< ads->m_Size; i++)
		{
			ads->presonArray[i] = ads->presonArray[i + 1];
		}
		ads->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}
//5.����ָ������Ϣ
void findPerson(Addressbooks* ads)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	
	//�ж�ָ����ϵ���ǵ���ͨѶ¼��
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "������" << ads->presonArray[ret].m_Name << '\t';
		cout << "�Ա�" << ads->presonArray[ret].m_Sex << '\t';
		cout << "���䣺" << ads->presonArray[ret].m_Age << '\t';
		cout << "�绰��" << ads->presonArray[ret].m_Phone << '\t';
		cout << "��ַ��" << ads->presonArray[ret].m_Addr <<endl;
	}
	else
	{
		cout << "ͨѶ¼�޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6.�޸���ϵ����Ϣ
void updatePerson(Addressbooks* ads)
{
	cout << "��������ϵ������" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���ǵ���ͨѶ¼��
	int ret = isExist(ads,name);
	if (ret != -1)
	{
		//�޸���ϵ����Ϣ

		//����
		cout << "�������޸ĺ������" << endl;
		string name;
		cin >> name;
		ads->presonArray[ret].m_Name = name;
		//�Ա�
		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1---�У�2---Ů" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex==1 || sex == 2) {
				ads->presonArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "����������" << endl;
			}
		}		
		//����
		cout << "�������޸ĺ������" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				ads->presonArray[ret].m_Age = age;
				break;
			}
			else {
				cout << "����������" << endl;
			}
		}
		//�绰
		cout << "�������޸ĺ�ĵ绰" << endl;
		string phone;
		cin >> phone;
		ads->presonArray[ret].m_Phone = phone;
		//��ַ
		cout << "�������޸ĺ�ĵ�ַ" << endl;
		string addr;
		cin >> addr;
		ads->presonArray[ret].m_Addr = addr;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//7.���ͨѶ¼
void clearAddressbooks(Addressbooks* ads) {
	ads->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
//�˵�
void showMenu() {
	cout << "\t|--------------|" << endl;
	cout << "\t| 1.�����ϵ�� |" << endl;
	cout << "\t| 2.��ʾ��ϵ�� |" << endl;
	cout << "\t| 3.ɾ����ϵ�� |" << endl;
	cout << "\t| 4.������ϵ�� |" << endl;
	cout << "\t| 5.�޸���ϵ�� |" << endl;
	cout << "\t| 6.�����ϵ�� |" << endl;
	cout << "\t| 0.�˳�ͨѶ¼ |" << endl;
	cout << "\t|--------------|" << endl;
}

int main() {
	Addressbooks ads;
	ads.m_Size = 0;//��ʼ������Ϊ0

	int select = -1;
	while (true) {
		showMenu();//��ʾ�˵�
		cin >> select;//�������
		switch (select)
		{
		case 1:	//1.�����ϵ��
			addPerson(&ads);
			break;
		case 2:	//2.��ʾ��ϵ��
			showPerson(&ads);
			break;
		case 3:	//3.ɾ����ϵ��
		/*{
			cout << "����ɾ����������" << endl;
			string name;
			cin >> name;
			if (isExist(&ads, name) == -1) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "�ҵ�����" << endl;
			}
		}*/
			deletePerson(&ads);
			break;
		case 4:	//4.������ϵ��
			findPerson(&ads);
			break;
		case 5:	//5.�޸���ϵ��
			updatePerson(&ads);
			break;
		case 6:	//6.�����ϵ��
			clearAddressbooks(&ads);
			break;
		case 0:	//0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");//��������˳�
	return 0;
}