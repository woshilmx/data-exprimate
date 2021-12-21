#include<iostream>
using namespace std;
const int  MAX=20;
class statck {
public:
	statck();
	void push();
	int pop();
	int isempty();
	int isfull();
private:
	int top;
	int base;
	int data[MAX];
	
};
statck::statck() {
	this->top = this->base = 0;
}
int statck::isempty() {
	if (this->base == this->top) return 0;
	else return 1;
}
int statck::isfull() {
	if (this->top - this->base >= MAX - 1) return 0;
	else return 1;
}
void statck::push() {
	cout << "ÇëÊäÈëÊý×Ö" << endl;
	int number;
	cin >> number;
	if (this->isfull() == 1) {
		this->data[this->top++] = number;
		cout << this->top;
	}
	else cout << "Õ»ÒÑÂú" << endl;
}
int statck::pop() {
	if (this->isempty() == 1) {
		return this->data[--this->top];

	}
	else {
		cout << "Õ»¿Õ" << endl;
		return -1;
	}
}
void menu() {
	cout << "1.ÈëÕ»" << endl;
	cout << "2.³öÕ»" << endl;
	cout << "0.ÍË³ö" << endl;
}
int main() {
	statck *sta = new statck();
	int choice, number;
	menu();
	while (1)
	{
		cout << "ÇëÊäÈë²Ù×÷" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sta->push();
			break;
		case 2:
			number=sta->pop();
			cout << number;
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
	system("pause");

	return 0;
}