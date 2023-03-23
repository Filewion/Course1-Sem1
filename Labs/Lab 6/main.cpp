#include<iostream>
#include<fstream>
#include "Func.hpp"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using namespace mtrx;


//���� ������������� �������{ Aij }i = 1...n; j = 1..n, n <= 100. ���� � ������� ���� ��� ���� �������, ������ �� 
//������������ ��������, � �� ����� 2 - � ���������, ���������� �������� ������� - ������� �����, ����������� ������ 
//������� �� ������������� ������������ ���������.



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

	if ((countMins(mas, minElement(mas)) > 1) && (countPrimes(mas) >= 2)) // �������� �� �������: ��� ���� ������� = min, >=2 ������� �����
	{
		int multies[n]{ 0 };
		multMas(mas, multies); // ���������� ������� � �������������� 
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