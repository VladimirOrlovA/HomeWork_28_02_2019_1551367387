#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstring>			// библиотека работы со строкам


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int strToInt(char *str)
{
	int number = 0;
	int i = 0;

	do
	{
		if (*str >= 48 && *str <= 57)  // считаем кол-во чисел, тем самым определяя разрядность числа
			i++;

		else if (i == 0)
		{
			return 0;	// если первый символ в строке не цифра возвращаем 0
			break;
		}


	} while (*str++ >= 48 && *str <= 57); // идем по строке пока не закончатся цифры

	str -= i;	 // возвращаем строку в начало

	do
	{
		i--;
		number += ((*str++) - 48) * pow(10, i); // собираем полученные цифры из строки в число

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
	/* 1.	**Подсчитать среднюю длину слова во введенном предложении.
	Рекомендации:
	Чтобы легче было посчитать, вычислите сначала количество  пробельных символов (пробел, знаки препинания) и количество 
	не пробельных символов.	Ввод с клавиатуры с помощью cin не позволяет ввести пробелы, поэтому можно вместо пробелов вводить
	символ подчеркивания «_» или воспользоваться cin.getline().
	char Mas[250];
	cin.getline(Mas,250);
	cout<<Mas; */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char Mas[250]; // = "Hello. It's wonderful, peace!";  // 28 символов, 3 пробела, 1 точка, 1 запятая

	char *ptrMas = Mas;

	cin.ignore();
	cin.getline(Mas, 250);

	//cout << Mas<<endl;

	int cCh = 0;
	int cSpace = 1;
	float averageWordLength = 0;

	while (*ptrMas++ != '\0')
	{
		// Считаем все символы кроме букв

		if (*ptrMas >= 33 && *ptrMas <= 47 || *ptrMas >= 58 && *ptrMas <= 64 || *ptrMas >= 91 && *ptrMas <= 96 || *ptrMas >= 123 && *ptrMas <= 127)
			cCh++;

		// Считаем все пробелы, чтобы узнать сколько у нас слов в введеной строке 

		else if (*ptrMas == 32)
			cSpace++;
	}

	// Определяем среднюю длину слова в введенном предложении-строке

	averageWordLength = float(strlen(Mas) - cCh - cSpace + 1) / cSpace;

	cout << endl;
	cout << "Кол-во символов в строке \t-> " << strlen(Mas) << endl;
	cout << "Кол-во символов, не букв \t-> " << cCh + cSpace - 1 << endl;
	cout << "Кол-во слов в строке     \t-> " << cSpace << endl;
	cout << "Средняя длина слова в строке \t-> " << averageWordLength << endl;

}

void Task2()
{
	/* 2.	**Написать функцию, которая преобразует строку в целое число. Если строка содержит не цифровые
	символы – подсчет останавливается. Так строка 123abc даст число 123, а строка a23f даст число 0.
	!!! запрещается использовать готовый метод itoa & atoi */

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
	/*  3.	*Заменить в строке  все гласные буквы на их номер по алфавиту. */



	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask3\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	// В этом приедолжении мы ищем все гласные буквы и меняем их на номер по алфафиту

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
