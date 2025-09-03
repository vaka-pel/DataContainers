#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
		cout << " EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr;
		cout << "FLConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "FLdestructor:\t" << this << endl;
	}

	// Adding elements
	void push_front(int Data)
	{
		// создаем элемент и сохраняем в него добавляемое значение
		Element* New = new Element(Data);

		// привязываем новый, созданный элемент к началу списка
		New->pNext = Head;

		// Переносим голову на новый элемент
		Head = New;

	}
	
    void push_back(int Data)
    {
		if (Head == nullptr)return push_front(Data);
	   Element* New = new Element(Data);
	   Element* Temp = Head;
	   while (Temp->pNext)Temp = Temp->pNext;
	   Temp->pNext = New;

    }
	void insert(int Data, int Index)
	{

		if (Index == 0)return push_front(Data);
		if (Index >= Element::count)return push_back(Data);
		//Доходим до нужного элемента (элемент перед добавляемым)
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;

		// создаем добавляемый элемент
		Element* New = new Element(Data);

		// прикркпляем новый элемент к его следующему элементу
		New->pNext = Temp->pNext;

		// прикрепляем предидущий элемент к новому
		Temp->pNext = New;
	
	}

	//         Removing elements:
	void pop_front()
	{
		// запоминаем адресс удаляемогмо элемента
		Element* Erased = Head;
		// исключаем удаляемый элемент из списка
		Head = Head->pNext;
		// удаляем удаляемый элемент из памяти
		delete Erased;

	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}
	//          Methods:
	void print()const
	{
		Element* Temp = Head; // Temp - это итератор (указатель при помощи которго можно перебирать элементы структуры данных)
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		Temp;
		cout << " Количество элементов списка: " << Element::count << endl;

	}
};
//#define BASE_CHECK


void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	cout << "ForwardList" << endl;
	//Element element = 5;

	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
		//list.push_front(rand() % 100);
	}
	//list.push_back(123);
	list.print();
	//list.pop_back();
	int index;
	int value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите значение добавляемого значения: "; cin >> value;
	list.insert(value, index);
	list.print();
#endif // BASE_CHECK

	ForwardList list1;
	list1.push_back(0);
	list1.push_back(1);
	list1.push_back(1);
	list1.push_back(2);
	list1.print();

	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.push_back(13);
	list2.push_back(21);
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list1.insert(value, index);
	list1.print();






}