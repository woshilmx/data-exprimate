#include<iostream>
#include<string>
using namespace std;
typedef struct Student {
	struct Student *next;
	string name;//姓名
	int number;//学号
	string banji;//班级
}Student;
void menu()
{
	cout << "欢迎来到学生信息管理系统" << endl;
	cout << "1.添加学生信息" << endl;
	cout << "2.查询学生信息" << endl;
	cout << "3.删除学生信息" << endl;
	cout << "4.修改学生信息" << endl;
	cout << "0.退出管理系统" << endl;
	cout << endl;

}
//初始化节点
void creat(Student*& L) {

	L = new Student;
	L->next = NULL;
}
//添加节点
void addstudent(Student* &L) {
	Student *head,*temp;
	head = L;
	string name;
	int number;
	string banji;
	while (head->next)
	{
		head = head->next;
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入学号" << endl;
	cin >> number;
	cout << "请输入班级" << endl;
	cin >> banji;
	temp = new Student;
	temp->name = name;
	temp->number = number;
	temp->banji = banji;
	head->next = temp;
	temp->next = NULL;
	head = temp;
}
//根据学号查询学生信息
void serchstudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	cout << "请输入学号" << endl;
	cin >> number;
	while (head)
	{
		if (head->number==number)
		{
			cout << "学生的姓名是：" << head->name << endl;
			cout << "学生的学号是：" << head->number << endl;
			cout << "学生的班级是：" << head->banji << endl;
			return;
		}
		head = head->next;
	}
	cout << "查无此人" << endl;
}
//根据学号删除学生信息
void delatestudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	cout << "请输入学号" << endl;
	cin >> number;
	while (head)
	{
		if (head->next!=NULL&&head->next->number == number)
		{
			temp = head->next;
			head->next = temp->next;
			delete temp;
			cout << "删除成功" << endl;
			return;
			
		}
		head = head->next;
	}
}
//根据学号修改学生信息
void changestudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	int choice;
	cout << "请输入学号" << endl;
	cin >> number;
	while (head)
	{
		if (head!= NULL&&head->number == number)
		{
			cout << "请输入修改的选项\n1---姓名\n2---学号\n3---班级" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "请输入姓名" << endl;
				cin >> head->name;
				break;
			case 2:
				cout << "请输入学号" << endl;
				cin >> head->number;
				break;
			case 3:
				cout << "请输入班级" << endl;
				cin >> head->banji;
				break;
			default:
				cout << "请重新输入" << endl;
				break;
			}
		}
		head = head->next;
	}
}
int main() {
	int choice;
	Student* L;
	creat(L);
	menu();
	while (1)
	{
		cout << "请输入操作序号" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			exit(0);

			break;
		case 1://1.添加学生信息
			addstudent(L);
			break;
		case 2:////2.查询学生信息
			serchstudent(L);
			break;
		case 3://3.删除学生信息
			delatestudent(L);
			break;
		case 4://4.修改学生信息
			changestudent(L);
			break;
			
		}
	}
	system("pause");
	return 0;
}