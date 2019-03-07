#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstring>			// библиотека работы со строкам


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



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



}


void Task3()
{
	/*  3.	*Заменить в строке  все гласные буквы на их номер по алфавиту. */



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
