#include<iostream>
#include<string>
using namespace std;
typedef struct Student {
	struct Student *next;
	string name;//����
	int number;//ѧ��
	string banji;//�༶
}Student;
void menu()
{
	cout << "��ӭ����ѧ����Ϣ����ϵͳ" << endl;
	cout << "1.���ѧ����Ϣ" << endl;
	cout << "2.��ѯѧ����Ϣ" << endl;
	cout << "3.ɾ��ѧ����Ϣ" << endl;
	cout << "4.�޸�ѧ����Ϣ" << endl;
	cout << "0.�˳�����ϵͳ" << endl;
	cout << endl;

}
//��ʼ���ڵ�
void creat(Student*& L) {

	L = new Student;
	L->next = NULL;
}
//��ӽڵ�
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
	cout << "����������" << endl;
	cin >> name;
	cout << "������ѧ��" << endl;
	cin >> number;
	cout << "������༶" << endl;
	cin >> banji;
	temp = new Student;
	temp->name = name;
	temp->number = number;
	temp->banji = banji;
	head->next = temp;
	temp->next = NULL;
	head = temp;
}
//����ѧ�Ų�ѯѧ����Ϣ
void serchstudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	cout << "������ѧ��" << endl;
	cin >> number;
	while (head)
	{
		if (head->number==number)
		{
			cout << "ѧ���������ǣ�" << head->name << endl;
			cout << "ѧ����ѧ���ǣ�" << head->number << endl;
			cout << "ѧ���İ༶�ǣ�" << head->banji << endl;
			return;
		}
		head = head->next;
	}
	cout << "���޴���" << endl;
}
//����ѧ��ɾ��ѧ����Ϣ
void delatestudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	cout << "������ѧ��" << endl;
	cin >> number;
	while (head)
	{
		if (head->next!=NULL&&head->next->number == number)
		{
			temp = head->next;
			head->next = temp->next;
			delete temp;
			cout << "ɾ���ɹ�" << endl;
			return;
			
		}
		head = head->next;
	}
}
//����ѧ���޸�ѧ����Ϣ
void changestudent(Student*& L) {
	Student* head, * temp;
	head = L;
	int number;
	int choice;
	cout << "������ѧ��" << endl;
	cin >> number;
	while (head)
	{
		if (head!= NULL&&head->number == number)
		{
			cout << "�������޸ĵ�ѡ��\n1---����\n2---ѧ��\n3---�༶" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "����������" << endl;
				cin >> head->name;
				break;
			case 2:
				cout << "������ѧ��" << endl;
				cin >> head->number;
				break;
			case 3:
				cout << "������༶" << endl;
				cin >> head->banji;
				break;
			default:
				cout << "����������" << endl;
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
		cout << "������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			exit(0);

			break;
		case 1://1.���ѧ����Ϣ
			addstudent(L);
			break;
		case 2:////2.��ѯѧ����Ϣ
			serchstudent(L);
			break;
		case 3://3.ɾ��ѧ����Ϣ
			delatestudent(L);
			break;
		case 4://4.�޸�ѧ����Ϣ
			changestudent(L);
			break;
			
		}
	}
	system("pause");
	return 0;
}