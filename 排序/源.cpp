#include<iostream>
using namespace std;

void qipao(int test[],int n) {
	int i, j, temp;
	for (i = 0; i < n ; i++)	
		for (j = 0; j <n - i-1; j++)	
			if (test[j] > test[j + 1])		
			{
				temp = test[j];
				test[j] = test[j + 1];
				test[j + 1] = temp;
			}
	for (i = 0; i < n; i++)
		cout << test[i] << "\t";
	cout << endl;
	
}
void zhijiecharu(int test[], int n) {
	int t[11];
	int j;
	for (int i = 1; i < 11; i++) {
		t[i] = test[i - 1];
	}
	for (int i = 2; i < 11; i++) {\
		if (t[i] < t[i - 1]) {
			t[0] = t[i];
			t[i] = t[i - 1];
			for (  j = i-2; t[0]<t[j];  j--)
			{
				t[j + 1] = t[j];
			}
			t[j + 1] = t[0];
		}
		
	}
	for (int i = 1; i < 11; i++)
		cout << t[i] << "\t";
	cout << endl;
}
void qucklysort(int test[], int low, int high) {
	if (low < high)
	{
		int i, j;
		i = low; j = high;
		int temp = test[low];
		while (i < j)
		{
			while (i<j && test[j]>=temp) j--;
			if (i < j)
			{
				test[i++] = test[j]; 
			}
			while (i < j && test[i] <= temp) i++;
			if (i < j)
			{
				test[j--] = test[i]; 
			}
		}
		test[i] = temp;
		qucklysort(test, low, i - 1);
		qucklysort(test, i+1,high);

	}
	
}
void xuersort(int test[], int n) {

		
	int  hill = int(n / 2);
	int i, j,temp;

		
		while (hill >= 1) {

			
			for ( i = hill; i < n; i++) {
				temp = test[i];
				j = i;
					while (test[j - hill] > temp && j - hill >= 0) {
						test[j] = test[j - hill];
						j -= hill;
					}

					test[j] = temp;
			}

			
			hill = int(hill / 2);
		}

		for (i = 0; i < n; i++)
			cout << test[i] << "\t";
		cout << endl;
		
}
void menu() {
	cout << "1.ÆðÅÝÅÅÐò" << endl;
	cout << "2.Ö±½Ó²åÈëÅÅÐò" << endl;
	cout << "3.¿ìËÙÅÅÐò" << endl;
	cout << "4.Ï£¶ûÅÅÐò" << endl;
}
int main()
{
	int  choice;
	int test[10] = { 25,30,1,85,13,20,95,33,24,68 };
	menu();
	while (1)
	{
		cout << "ÇëÊäÈë²Ù×÷ÐòºÅ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			qipao(test, 10);
			break;
		case 2:
			zhijiecharu(test, 10);
			break;
		case 3:
			qucklysort(test, 0, 9);
			for (int i = 0; i <10; i++)
				cout << test[i] << "\t";
			cout << endl;
			break;
		case 4:
			xuersort(test, 10);
			break;

			
		default:
			break;
		}

	}
	system("pause");
	return 0;
	
}