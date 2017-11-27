// BIO_Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int NumberOfPattern(string dnk0, string pattern0)
{
	const char* dnk = dnk0.c_str();
	const char* pattern = pattern0.c_str();
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
		string dnk;
		string pattern;
		getline(fin, dnk, '\n');	// cчитываем 1 строку
		getline(fin, pattern, '\n');	// считываем 2 строку
		fin.close();
		int tmp = 0;
		if (pattern.empty() || dnk.empty())
			tmp = 0;	// если нет одной из строк
		else
			tmp = NumberOfPattern(dnk, pattern);	// число вхождений
		ofstream fout("output.txt");
		fout << tmp;
		fout.close();
	}
    return 0;
}

