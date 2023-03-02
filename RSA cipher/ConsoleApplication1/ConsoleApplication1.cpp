#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void Encryption(string alphabet);
void Decryption(string alphabet);
int NOD(int num_1, int num_2);
int FuncE(int f);
int SymToInt(char sym, string alphabet);
unsigned long long int ModExhibitor(unsigned long long int m, unsigned long long int e, unsigned long long int n);

void main()
{
	string alphabet = "**abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	setlocale(LC_ALL, "ru");

	string test;

	while (true)
	{
		cout << "Введите (enc) для шифрования, (dec) для дешифрования или (end) для завершения программы: ";
		cin >> test;

		if (test == "enc")
			Encryption(alphabet);
		else if (test == "dec")
			Decryption(alphabet);
		else if (test == "end")
			break;
		else
			cout << "Вы ввели некорректное значение и всё сломалось :(" << endl;
	}
}

void Encryption(string alphabet)
{
	unsigned long long int m1 = 0, m2 = 0, m3 = 0;
	int p = 1553, q = 1559, n = 0, f = 0, e = 0, d = 0;
	string surname;

	while (true)
	{
		cout << "\nВведите 3 первые буквы своей фамилии: ";
		cin >> surname;
		if (surname.length() == 3)
			break;
	}

	n = p * q;
	f = (p - 1) * (q - 1);
	e = FuncE(f);

	// Вычисление закрытого ключа
	int i_temp = 1;
	while (true)
	{
		if ((i_temp * e) % f == 1)
		{
			d = i_temp;
			break;
		}
		i_temp++;
	}

	cout << "\np = " << p << endl;
	cout << "q = " << q << endl;
	cout << "n = " << n << endl;
	cout << "f = " << f << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl;

	m1 = SymToInt(surname[0], alphabet);
	m2 = SymToInt(surname[1], alphabet);
	m3 = SymToInt(surname[2], alphabet);

	cout << "\nm1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m3 = " << m3 << endl;

	m1 = ModExhibitor(m1, e, n);
	m2 = ModExhibitor(m2, e, n);
	m3 = ModExhibitor(m3, e, n);

	cout << "\nm1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m3 = " << m3 << endl;

	cout << "\n-------------------------------------------------" << endl;
	cout << "Зашифрованное сообщение: " << m1 << " " << m2 << " " << m3 << endl;
	cout << "-------------------------------------------------" << endl;
}

void Decryption(string alphabet)
{
	unsigned long long int m1 = 0, m2 = 0, m3 = 0;
	int p = 1553, q = 1559, n = 0, f = 0, e = 0, d = 0;
	string surname;

	cout << "\nВведите 3 десятичных числа зашифрованного сообщения:" << endl;
	cout << "№1: "; cin >> m1;
	cout << "№2: "; cin >> m2;
	cout << "№3: "; cin >> m3;

	n = p * q;
	f = (p - 1) * (q - 1);
	e = FuncE(f);

	// Вычисление закрытого ключа
	int i_temp = 1;
	while (true)
	{
		if ((i_temp * e) % f == 1)
		{
			d = i_temp;
			break;
		}
		i_temp++;
	}

	cout << "\np = " << p << endl;
	cout << "q = " << q << endl;
	cout << "n = " << n << endl;
	cout << "f = " << f << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl;

	m1 = ModExhibitor(m1, d, n);
	m2 = ModExhibitor(m2, d, n);
	m3 = ModExhibitor(m3, d, n);

	cout << "\nm1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m3 = " << m3 << endl;

	cout << "\n-------------------------------------------------" << endl;
	cout << "Расшифрованное сообщение: " << alphabet[m1] << alphabet[m2] << alphabet[m3] << endl;
	cout << "-------------------------------------------------" << endl;
}

int NOD(int num_1, int num_2)
{
	int i = 0;
	for (i = num_1; i > 0; i--)
	{
		if (num_1 % i == 0 && num_2 % i == 0)
			break;
	}
	return i;
}

int FuncE(int f)
{
	int x = 0, e = 0;
	for (int i = 0; i < f; i++)
	{
		int k = 0;
		for (int j = 1; j <= i; j++)
			if (i % j == 0)
				k++;

		if (k == 2)
		{
			x++;
			if (NOD(i, f) == 1)
			{
				e = i;
				break;
			}
		}
	}
	return e;
}

int SymToInt(char sym, string alphabet)
{
	int j = 0;
	for (int i = 0; i < 54; i++)
	{
		if (sym == alphabet[i])
			j = i;
	}
	return j;
}

unsigned long long int ModExhibitor(unsigned long long int m, unsigned long long int e, unsigned long long int n)
{
	unsigned long long int result = 1;

	while (e > 0)
	{
		if (e % 2 != 0)
			result = (m * result) % n;
		m = (m * m) % n;
		e /= 2;
	}

	return result;
}