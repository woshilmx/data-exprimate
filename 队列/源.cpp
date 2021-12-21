#include<iostream>
using namespace std;
class dui {
public:
	dui();
	int data;
	dui* next;
};
dui::dui() {
	this->next = NULL;
}
class queue {
public:
	queue();
	void push();
	int pop();
private:
	dui *d;
	dui* front;
	dui* rear;
	
};
queue::queue() {
	this->front = new dui();
	this->rear = new dui();
	this->front = this->rear;
	
}
void queue::push() {
	cout << "�������������" << endl;
	int num;
	cin >> num;
	dui* du = new dui();
	du->data = num;
	this->rear->next = du;
	this->rear = du;
}
int queue::pop() {
	if (this->front == this->rear) return 0;
	dui* temp;
	temp = this->front->next;
	int e = temp->data;
	this->front->next = temp->next;
	if (temp == this->rear) this->rear = this->front;
	delete temp;
	return e;
}
void menu() {
	cout << "1.��Ӳ���" << endl;
	cout << "2.���Ӳ���" << endl;
}
int main()
{
	queue *que = new queue();
	int choice;
	menu();
	while (1)
	{
		cout << "������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			que->push();
			break;
		case 2:
			
			cout << que->pop()<<endl;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}