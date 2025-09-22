#include<iostream>
using namespace std;

void Elevator(int floor);
int Factorial(int N);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите номер этажа: "; cin >> n;
	Elevator(n);
	cout << "Введите число для вычисления факториала: "; cin >> n;
	Factorial(n);
	//cout << "Recursion";
	//main();
}

void Elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже" << endl;
	Elevator(floor - 1);
	cout << "Вы на " << floor << " этаже" << endl;
}
 int Factorial(int N)
{
	 if (N < 0) { return 0; }
	 if (N == 0) { return 1; }
	 else
	 {
		return N * Factorial(N - 1);
		
	 cout << "факториал числа " << " = " << Factorial(N) << endl;
	 }

}