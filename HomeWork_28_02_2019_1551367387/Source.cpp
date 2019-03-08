#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstring>			// ���������� ������ �� �������


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



void Task1()
{
	/* 1.	**���������� ������� ����� ����� �� ��������� �����������.
	������������:
	����� ����� ���� ���������, ��������� ������� ����������  ���������� �������� (������, ����� ����������) � ���������� 
	�� ���������� ��������.	���� � ���������� � ������� cin �� ��������� ������ �������, ������� ����� ������ �������� �������
	������ ������������� �_� ��� ��������������� cin.getline().
	char Mas[250];
	cin.getline(Mas,250);
	cout<<Mas; */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char Mas[250]; // = "Hello. It's wonderful, peace!";  // 28 ��������, 3 �������, 1 �����, 1 �������

	char *ptrMas = Mas;

	cin.ignore();
	cin.getline(Mas, 250);

	//cout << Mas<<endl;

	int cCh = 0;
	int cSpace = 1;
	float averageWordLength = 0;

	while (*ptrMas++ != '\0')
	{
		// ������� ��� ������� ����� ����

		if (*ptrMas >= 33 && *ptrMas <= 47 || *ptrMas >= 58 && *ptrMas <= 64 || *ptrMas >= 91 && *ptrMas <= 96 || *ptrMas >= 123 && *ptrMas <= 127)
			cCh++;

		// ������� ��� �������, ����� ������ ������� � ��� ���� � �������� ������ 

		else if (*ptrMas == 32)
			cSpace++;
	}

	// ���������� ������� ����� ����� � ��������� �����������-������

	averageWordLength = float(strlen(Mas) - cCh - cSpace + 1) / cSpace;

	cout << endl;
	cout << "���-�� �������� � ������ \t-> " << strlen(Mas) << endl;
	cout << "���-�� ��������, �� ���� \t-> " << cCh + cSpace - 1 << endl;
	cout << "���-�� ���� � ������     \t-> " << cSpace << endl;
	cout << "������� ����� ����� � ������ \t-> " << averageWordLength << endl;

}

int strToInt(char *str)
{
	int number = 0;
	int i = 0;

	do
	{
		if (*str >= 48 && *str <= 57)  // ������� ���-�� �����, ��� ����� ��������� ����������� �����
			i++;

		else if (i == 0)
		{
			return 0;	// ���� ������ ������ � ������ �� ����� ���������� 0
			break;
		}
	

	} while (*str++ >= 48 && *str <= 57); // ���� �� ������ ���� �� ���������� �����

	str-=i;	 // ���������� ������ � ������

	do
	{
		i--;
		number += ((*str++)- 48) * pow(10, i); // �������� ���������� ����� �� ������ � �����
		
	}while (i > 0);

	return number;
}


void Task2()
{
	/* 2.	**�������� �������, ������� ����������� ������ � ����� �����. ���� ������ �������� �� ��������
	������� � ������� ���������������. ��� ������ 123abc ���� ����� 123, � ������ a23f ���� ����� 0.
	!!! ����������� ������������ ������� ����� itoa & atoi */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char str[50] = "012345F6789abc";

	/*char str[50];
	cin.ignore();
	cin.getline(str, 50);*/

	cout << str << endl<<endl;
		
	cout<<strToInt(str);

}
	


void Task3()
{
	/*  3.	*�������� � ������  ��� ������� ����� �� �� ����� �� ��������. */



	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask3\n\n";
	SetConsoleTextAttribute(hConsole, 7);



}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_28_02_2019_1551367387 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (3) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;


		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
