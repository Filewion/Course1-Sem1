#include<iostream>
#include<fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

//В текстовом файле input.txt записан русский текст.Найти в тексте слова, содержащие две одинаковые буквы подряд, записать их заглавными 
//буквами и указать после каждого такого слова в скобках найденные буквы.
//Полученный текст записать в файл output.txt.Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания



void upp(char a[],char &c)
{
	for (int i = 0; i < strlen(a); i++)
	{
		if ((a[i] >= 'а') && (a[i] <= 'я'))
		{
			a[i] = ((int)a[i]) - 32;
			c = '\0';
		}
		else if (a[i] == 'ё')
		{
			a[i] = 'Ё';
			c = '\0';
		}
		else if (a[i] < 'А' || a[i]>'я')
		{
			c = a[i];
			a[i] = '\0';
		}
	}
}
char doublecheck(char a[])
{
	for (int i = 0; i < strlen(a)-1; i++)
	{
		if (( (a[i] == a[i + 1]) || a[i]+32 == a[i+1] ) && ( (a[i+1] >= 'а') && (a[i+1] <= 'я')))
		{
			return a[i];
		}
	}
	return ' ';
}

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	const int n = 15;
	char a[n]{},b,c = '\0';
 	while(!fin.eof())
	{
		fin >> a;
		b = doublecheck(a);
		if (b != ' ')
		{
			upp(a,c);
			fout << a << "(" << b << b << ")" << c;
			if (c != '\0')
				fout << " ";
		}
		else
		{
			fout << a << " ";
		}
	}
}



