// BIO_Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int NumberOfPattern(char* dnk, char* pattern)
{
	int tmp = 0;	// число вхождений
	for (int i = 0; i < strlen(dnk); i++)
	{
		// сравнивает strlen(pattern) символов dnk с pattern 
		if (strncmp((dnk + i), pattern, strlen(pattern)) == 0)
			tmp++;
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin("input.txt");
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		char dnk[80];
		char *pattern = new char[80];
		fin.getline(dnk, 80);		// считать 1 строку ( не больше 30 символов)
		fin.getline(pattern,80);	// считать 2 строку
		fin.close();
		int tmp = NumberOfPattern(dnk, pattern);	// число вхождений
		ofstream fout("output.txt");
		fout << tmp;
		fout.close();
	}
    return 0;
}

