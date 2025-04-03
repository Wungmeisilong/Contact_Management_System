#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct Person {
	//姓名
	string m_Name;

	//性别	1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks 
{
	//通讯录中保存人数的数组
	struct Person presonArray[MAX];
	//通讯录中保存联系人的个数
	int m_Size;
};
//1.添加功能
void addPerson(Addressbooks* ads)
{
	//先判断人数是否满
	if (ads->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加。" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "输入姓名" << endl;
		cin >> name;
		ads->presonArray[ads->m_Size].m_Name = name;
		//性别
		cout << "请输入数字" << endl;
		cout << "1---男，2----女" << endl;
		int sex;
		while (true) {
			cin >> sex;//请放入循环中
			if (sex == 1 || sex == 2) {
				ads->presonArray[ads->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		while (true) {
			cin >> age;//请放入循环中
			if (age>0 && age<150) {
				ads->presonArray[ads->m_Size].m_Age = age;
				break;
			}
			cout << "请重新输入" << endl;
		}
		//电话
		string phone;
		cout << "输入电话号码" << endl;
		cin >> phone;
		ads->presonArray[ads->m_Size].m_Phone = phone;
		//住址
		string addr;
		cout << "请输入地址" << endl;
		cin >> addr;
		ads->presonArray[ads->m_Size].m_Addr = addr;

		//更新人数
		ads->m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}
//2.显示功能
void showPerson(Addressbooks* ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_Size; i++) {
			cout << "姓名：" << ads->presonArray[i].m_Name << "\t";
			cout << "性别：" << (ads->presonArray[i].m_Sex == 1 ? "男" :"女") << "\t";
			cout << "年龄：" << ads->presonArray[i].m_Age << "\t";
			cout << "电话：" << ads->presonArray[i].m_Phone << "\t";
			cout << "住址：" << ads->presonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//3.判断联系人是否存在,存在返回地址，否则返回-1
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
//4.删除联系人
void deletePerson(Addressbooks* ads)
{
	cout << "输入删除的人姓名" << endl;
	string name;
	cin >> name;
	if (isExist(ads, name) == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		for (int i=0; i< ads->m_Size; i++)
		{
			ads->presonArray[i] = ads->presonArray[i + 1];
		}
		ads->m_Size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}
//5.查找指定人信息
void findPerson(Addressbooks* ads)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	
	//判断指定联系人是的在通讯录中
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "姓名：" << ads->presonArray[ret].m_Name << '\t';
		cout << "性别：" << ads->presonArray[ret].m_Sex << '\t';
		cout << "年龄：" << ads->presonArray[ret].m_Age << '\t';
		cout << "电话：" << ads->presonArray[ret].m_Phone << '\t';
		cout << "地址：" << ads->presonArray[ret].m_Addr <<endl;
	}
	else
	{
		cout << "通讯录无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6.修改联系人信息
void updatePerson(Addressbooks* ads)
{
	cout << "请输入联系人名称" << endl;
	string name;
	cin >> name;

	//判断指定联系人是的在通讯录中
	int ret = isExist(ads,name);
	if (ret != -1)
	{
		//修改联系人信息

		//姓名
		cout << "请输入修改后的姓名" << endl;
		string name;
		cin >> name;
		ads->presonArray[ret].m_Name = name;
		//性别
		cout << "请输入修改后的性别" << endl;
		cout << "1---男，2---女" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex==1 || sex == 2) {
				ads->presonArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		}		
		//年龄
		cout << "请输入修改后的年龄" << endl;
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
				cout << "请重新输入" << endl;
			}
		}
		//电话
		cout << "请输入修改后的电话" << endl;
		string phone;
		cin >> phone;
		ads->presonArray[ret].m_Phone = phone;
		//地址
		cout << "请输入修改后的地址" << endl;
		string addr;
		cin >> addr;
		ads->presonArray[ret].m_Addr = addr;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//7.清空通讯录
void clearAddressbooks(Addressbooks* ads) {
	ads->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
//菜单
void showMenu() {
	cout << "\t|--------------|" << endl;
	cout << "\t| 1.添加联系人 |" << endl;
	cout << "\t| 2.显示联系人 |" << endl;
	cout << "\t| 3.删除联系人 |" << endl;
	cout << "\t| 4.查找联系人 |" << endl;
	cout << "\t| 5.修改联系人 |" << endl;
	cout << "\t| 6.清空联系人 |" << endl;
	cout << "\t| 0.退出通讯录 |" << endl;
	cout << "\t|--------------|" << endl;
}

int main() {
	Addressbooks ads;
	ads.m_Size = 0;//初始化人数为0

	int select = -1;
	while (true) {
		showMenu();//显示菜单
		cin >> select;//输入操作
		switch (select)
		{
		case 1:	//1.添加联系人
			addPerson(&ads);
			break;
		case 2:	//2.显示联系人
			showPerson(&ads);
			break;
		case 3:	//3.删除联系人
		/*{
			cout << "输入删除的人姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&ads, name) == -1) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "找到此人" << endl;
			}
		}*/
			deletePerson(&ads);
			break;
		case 4:	//4.查找联系人
			findPerson(&ads);
			break;
		case 5:	//5.修改联系人
			updatePerson(&ads);
			break;
		case 6:	//6.清空联系人
			clearAddressbooks(&ads);
			break;
		case 0:	//0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");//按任意键退出
	return 0;
}