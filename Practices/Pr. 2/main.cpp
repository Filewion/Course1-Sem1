#include<iostream>
#define N 1000
using std::cout;
using std::cin;
using std::endl;


//for (int i = 0; i < strlen(A); i++)
	//cout << A[i];

//Даны 2 числа A и B, количество цифр в которых может достигать 1000. Необходимо реализовать операцию сложения и умножения над этими числами.
//Будет засчитана только честная реализация(без спецбиблиотек и т.п.).



// отзеркаливание строки
void reverse(char a[])   
{
	int c = 0, j, i;
	for (i = 0, j = strlen(a) - 1; i < j; i++, j--)
	{
		c = a[i];
		a[i] = a[j];
		a[j] = c;
	}
} 

//свой max
int max(int a, int b) 
{
	if (a > b)
		return a;
	else
		return b;

}

// копирование строки
void mycpy(char a[], char b[]) 
{
	int len = max(strlen(a), strlen(b));
	for (int i = 0; i < len; i++)
		a[i] = b[i];
}

//реализация суммы
void sum(char a[], char b[])  
{
	reverse(a), reverse(b);
	int  c = 0, i = 0, q = 0, w = 0, lena = strlen(a), lenb = strlen(b), len = max(lena, lenb);
	while (i <= len)
	{
		q = max((a[i] - '0'), 0);
		w = max((b[i] - '0'), 0);
		c = c + q + w;
		if ( !((i == len) && (c==0)))
			a[i] = (char)(((int)'0') + c % 10);
		c /= 10;
		i++;
	}

	reverse(a);
	reverse(b);
}

//реализация умножения
void mult(char a[], char b[])
{
	reverse(a), reverse(b);
	int  c = 0, i = 0, j = 0, q = 0, w = 0,k = 0, lena = strlen(a), lenb = strlen(b), len = max(lena, lenb);
	char massi[N]{ '0' }, massi2[N]{'0'};
	while (j < lenb)
	{
		if (i <= lena)
		{
			w = max((b[j] - '0'), 0);
			q = max((a[i] - '0'), 0);
			c = c + q * w;
			if (!((i == lena) && (c == 0)))
				massi[i+j] = (char)(((int)'0') + c % 10);
			c /= 10;
			i++;
		}
		else
		{
			reverse(massi);
			sum(massi2, massi);
			for (int f = 0; f < strlen(massi); f++)
				massi[f] = '0';
			j++;
			k++;
			i = 0;
		}
	}
	mycpy(a, massi2);
}


int main()
{
	setlocale(LC_ALL, "rus");
	char A[N]{ '0' }, B[N]{ '0' }, A2[N]{'0'};

	cout << "Введите два числа" << endl;

	cin >> A;
	cin >> B;

	mycpy(A2, A);

	sum(A2, B);

	cout << "Сумма:" << "\t" << "\t";
	for (int i = 0; i < strlen(A2); i++)
		cout << A2[i];

	cout << "\n";
	mycpy(A2, A);

	mult(A2, B);

	cout << "Произведение:"<<"\t";
	for (int i = 0; i < strlen(A2); i++)
		cout << A2[i];

}