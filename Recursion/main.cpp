#include<iostream>
using namespace std;

void Elevator(int floor);
int Factorial(int N);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ����� �����: "; cin >> n;
	Elevator(n);
	cout << "������� ����� ��� ���������� ����������: "; cin >> n;
	Factorial(n);
	//cout << "Recursion";
	//main();
}

void Elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������" << endl;
		return;
	}
	cout << "�� �� " << floor << " �����" << endl;
	Elevator(floor - 1);
	cout << "�� �� " << floor << " �����" << endl;
}
 int Factorial(int N)
{
	 if (N < 0) { return 0; }
	 if (N == 0) { return 1; }
	 else
	 {
		return N * Factorial(N - 1);
		
	 cout << "��������� ����� " << " = " << Factorial(N) << endl;
	 }

}