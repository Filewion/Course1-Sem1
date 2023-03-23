#include<iostream>
#include<fstream>
#include "Func.hpp"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using namespace mtrx;


//ƒана целочисленна€ матрица{ Aij }i = 1...n; j = 1..n, n <= 100. ≈сли в матрице есть еще один элемент, равный ее 
//минимальному элементу, и не менее 2 - х элементов, абсолютные величины которых - простые числа, упор€дочить строки 
//матрицы по невозрастанию произведений элементов.



/*for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << mas[i][j] << " ";
	}
	cout << endl;
}*/



int main()
{
	ifstream infile("numstest.txt");
	ofstream outfile("outnums.txt");
	int mas[n][n]{ 0 };

	mtrx::read(infile, mas);

	infile.close();
	cout << "\n";

	if ((countMins(mas, minElement(mas)) > 1) && (countPrimes(mas) >= 2)) // проверка на услови€: ещЄ один элемент = min, >=2 простых числа
	{
		int multies[n]{ 0 };
		multMas(mas, multies); // заполнение массива с произведени€ми 
		int tmp = 0;
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (multies[i] < multies[j])
				{
					swapstr(mas, i, j);
					swap(multies[i], multies[j]);
				}
			}
		}
	}


	record(outfile, mas);

}