#include<iostream>
#include<fstream>
#include <Windows.h>
#include <algorithm>
using namespace std;

//Дан файл, содержащий русский текст, размер текста не превышает 10 К байт. 
//Найти в тексте N (N ≤ 100) самых длинных слов, не содержащих ни одной буквы из заданного слова. 
//Записать найденные слова в текстовый файл в порядке не возрастания длины. Все найденные слова должны быть разными. Число N вводить из файла.

bool notInWord(string a, string b)    // функция, проверяющая наличие букв заданного слова в слове из массива 
{
	for (int i = 0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++)
			if ((a[i] == b[j]) || (abs((abs(int(a[i])) - abs(int(b[j]))) == 32)))
				return false;
	return true;
}

int compare(string& a, string& b)   // компаратор для sort
{
	if (a.length() > b.length())
		return 1;
	return 0;
}
//void onlyletters(string &a)  // удаление из массива НЕбуквенных символов 
//{
//	string b{ "!.,-—:?" };
//	for (int i = 0; i < a.length(); i++)
//		for (int j = 0; j < b.length(); j++)
//			if(a[i] == b[j])
//				a.erase(i,1);
//}

void onlyletters(string& a)  // удаление из массива НЕбуквенных символов 
{
	for (int i = 0; i < a.length(); i++)
		if (!((((int)a[i]) > 'А' && ((int)a[i]) < 'я') || a[i] == 'ё'))
		{
			a.erase(i, 1);
			i--;
		}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	const int N = 1000;
	string word, mas, helpmas[N]{}, newmas[N]{};

	ifstream fin("text.txt");
	ofstream fout("outtext.txt");

	fstream theN("nFile.txt");
	int N1;
	theN >> N1;

	if (fin.is_open())
		cout << "OK" << endl;  // проверка на открытие файла

	cin >> word; // задаём слово

	int i = 0;
	while (!fin.eof()) //цикл до окончания файла 
	{
		fin >> mas;// слово из файла 
		onlyletters(mas);  // удаление из массива небуквенных символов 
		if (notInWord(mas, word)) // проверка на буквы
		{
			newmas[i] = mas;
		}
		i++;
	}
	//for (int i = 0; i < N; i++)
	//	cout << newmas[i] << " ";
	//cout << endl;

	for (int i = 0; i < N1 - 1; i++)  //проверка на повтор слова
		for (int j = i + 1; j < N1; j++)
			if (newmas[i] == newmas[j])
				newmas[j] = "";

	sort(newmas, newmas + i, compare); // сортировка 

	for (int i = 0; i < N; i++) //запись в файл 
	{
		if (newmas[i] != "")
			fout << newmas[i] << " ";
	}




}
