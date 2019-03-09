#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstring>			// ���������� ������ �� �������


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

	str -= i;	 // ���������� ������ � ������

	do
	{
		i--;
		number += ((*str++) - 48) * pow(10, i); // �������� ���������� ����� �� ������ � �����

	} while (i > 0);

	return number;
}

void changeVowelsToAlpha(char const *str, char *nstr)
{
	// Alphabetical number(Aa - 1)  (Ee - 5)  (Ii - 9)  (Oo - 15)  (Uu - 21)  (Yy - 25)
	
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] == 'A' || str[i] == 'a')			// (Aa - 1) 
		{
		nstr[i] = '0';
		nstr[i + 1] = '1';
		nstr++;
		i++;
		}

		else if (str[i] == 'E' || str[i] == 'e')	// (Ee - 5)
		{
			nstr[i] = '0';
			nstr[i + 1] = '5';
			nstr++;
			i++;
		}

		else if (str[i] == 'I' || str[i] == 'i')	// (Ii - 9)
		{
			nstr[i] = '0';
			nstr[i+1] = '9';
			nstr++;
			i++;
		}

		else if (str[i] == 'O' || str[i] == 'o')	// (Oo - 15)
		{
			nstr[i] = '1';
			nstr[i + 1] = '5';
			nstr++;
			i++;
		}

		else if (str[i] == 'U' || str[i] == 'u')	// (Uu - 21))
		{
			nstr[i] = '2';
			nstr[i + 1] = '1';
			nstr++;
			i++;
		}
		
		else if (str[i] == 'Y' || str[i] == 'y')	// (Uu - 21))
		{
			nstr[i] = '2';
			nstr[i + 1] = '5';
			nstr++;
			i++;
		}

		nstr[i] = str[i];
	}

}


void changeVowelsToASCII(char const *str, char *nstr)
{
	// ASCII number (Aa 65-97)  (Ee 69-101)  (Ii 73-105)  (Oo 79-111)  (Uu 85-117)  (Yy 89-121)

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'A')		// Aa - 65-97=32  
		{
			nstr[i] = '6';
			nstr[i + 1] = '5';
			nstr++;
			i++;
		}

		else if (str[i] == 'a')
		{
			nstr[i] = '9';
			nstr[i + 1] = '7';
			nstr++;
			i++;
		}

		else if (str[i] == 'E')	// Ee 69-101=32
		{
			nstr[i] = '6';
			nstr[i + 1] = '9';
			nstr++;
			i++;
		}

		else if (str[i] == 'e')
		{
			nstr[i] = '1';
			nstr[i + 1] = '0';
			nstr[i + 2] = '1';
			nstr += 2;
			i++;
		}

		else if (str[i] == 'I')	// Ii 73-105=32
		{
			nstr[i] = '7';
			nstr[i + 1] = '3';
			nstr++;
			i++;
		}

		else if (str[i] == 'i')
		{
			nstr[i] = '1';
			nstr[i + 1] = '0';
			nstr[i + 2] = '5';
			nstr += 2;
			i++;
		}

		else if (str[i] == 'O')	// Oo 79-111=32
		{
			nstr[i] = '7';
			nstr[i + 1] = '9';
			nstr++;
			i++;
		}

		else if (str[i] == 'o')
		{
			nstr[i] = '1';
			nstr[i + 1] = '1';
			nstr[i + 2] = '1';
			nstr += 2;
			i++;
		}

		else if (str[i] == 'U')	// Uu 85-117=32
		{
			nstr[i] = '8';
			nstr[i + 1] = '5';
			nstr++;
			i++;
		}

		else if (str[i] == 'u')
		{
			nstr[i] = '1';
			nstr[i + 1] = '1';
			nstr[i + 2] = '7';
			nstr += 2;
			i++;
		}

		else if (str[i] == 'Y')	// Yy 89-121=32
		{
			nstr[i] = '8';
			nstr[i + 1] = '9';
			nstr++;
			i++;
		}

		else if (str[i] == 'y')
		{
			nstr[i] = '1';
			nstr[i + 1] = '2';
			nstr[i + 2] = '1';
			nstr += 2;
			i++;
		}

		nstr[i] = str[i];
	}


}

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

	// � ���� ������������ �� ���� ��� ������� ����� � ������ �� �� ����� �� ��������

	char str[100] = "This is unit a red color, is ok";
	char nstr[100]="0";
		
	cout << str << endl;

	changeVowelsToAlpha(str, nstr);
	cout << endl << nstr << endl;

	changeVowelsToASCII(str, nstr);
	cout << endl << nstr << endl;


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
