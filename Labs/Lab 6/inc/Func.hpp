#pragma once
#include<fstream>
#define n 5 

namespace mtrx
{
	void read(std::ifstream& fin, int mas[n][n]); // ������ ������� �� �����
	int minElement(int mas[n][n]); // ���������� ������������ �������� 
	int countMins(int mas[n][n], int min); // ���-�� ����������� ���������, ������ ������������
	bool isPrime(int x); // �������� �� �������� ����� 
	int countPrimes(int mas[n][n]); // ���-�� ������� �����
	void multMas(int mas[n][n], int mas2[n]); // ����������� ���������� ������� ���������� ������������ ��������� ����� 
	void swapstr(int mas[n][n], int a, int b); // ���� ����� 
	void swap(int& x, int& y); // ���� ��������� 
	void record(std::ofstream& fout, int mas[n][n]); // ������ ������������������ ������� � ����
}