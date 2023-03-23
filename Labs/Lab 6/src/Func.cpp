#include "Func.hpp"
#include<fstream>


namespace mtrx
{
	void read(std::ifstream& fin, int mas[n][n])
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fin >> mas[i][j];
			}
		}
	}


	int minElement(int mas[n][n])
	{
		int minka = INT_MAX;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (mas[i][j] < minka)
					minka = mas[i][j];
			}
		return minka;
	}


	int countMins(int mas[n][n], int min)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mas[i][j] == min)
					count += 1;
			}
		}
		return count;
	}


	bool isPrime(int x)
	{
		if (x < 2)
			return false;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
				return false;
		}
		return true;
	}


	int countPrimes(int mas[n][n])
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (isPrime(abs(mas[i][j])))
				{
					count++;
				}
			}
		}
		return count;
	}


	void multMas(int mas[n][n], int mas2[n])
	{
		int c = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				c *= mas[i][j];
			}
			mas2[i] = c;
			c = 1;
		}
	}


	void swapstr(int mas[n][n], int a, int b)
	{
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			c = mas[a][i];
			mas[a][i] = mas[b][i];
			mas[b][i] = c;
		}

	}
	void swap(int& x, int& y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}


	void record(std::ofstream& fout, int mas[n][n])
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fout << mas[i][j] << " ";
			}
			fout << "\n";
		}
	}
}
