// BIO_Lab1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int NumberOfPattern(char* dnk, char* pattern)
{
	int tmp = 0;	// ����� ���������
	for (int i = 0; i < strlen(dnk); i++)
	{
		// ���������� strlen(pattern) �������� dnk � pattern 
		if (strncmp((dnk + i), pattern, strlen(pattern)) == 0)
			tmp++;
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin("input.txt");
	if (!fin.is_open()) // ���� ���� �� ������
		cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
	else
	{
		char dnk[80];
		char *pattern = new char[80];
		fin.getline(dnk, 80);		// ������� 1 ������ ( �� ������ 30 ��������)
		fin.getline(pattern,80);	// ������� 2 ������
		fin.close();
		//cout << dnk << endl;
		//cout << pattern << endl;
		int tmp = NumberOfPattern(dnk, pattern);	// ����� ���������
		//cout << tmp << endl;
		ofstream fout("output.txt");
		fout << tmp;
		fout.close();
	}
    return 0;
}

