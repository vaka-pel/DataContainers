#include<iostream>
using namespace std;

void elevator(int floor);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ����� �����: "; cin >> n;
	elevator(n);
	//cout << "Recursion";
	//main();
}

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������" << endl;
		return;
	}
	cout << "�� �� " << floor << " �����" << endl;
	elevator(floor - 1);
	cout << "�� �� " << floor << " �����" << endl;
}