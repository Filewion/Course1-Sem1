#pragma once
#include<fstream>
#define n 5 

namespace mtrx
{
	void read(std::ifstream& fin, int mas[n][n]); // чтение массива из файла
	int minElement(int mas[n][n]); // нахождение минимального элемента 
	int countMins(int mas[n][n], int min); // кол-во минимальных элементов, равных минимальному
	bool isPrime(int x); // проверка на простоту числа 
	int countPrimes(int mas[n][n]); // кол-во простых чисел
	void multMas(int mas[n][n], int mas2[n]); // заполенение отдельного массива значениями произведений элементов строк 
	void swapstr(int mas[n][n], int a, int b); // свап строк 
	void swap(int& x, int& y); // свап элементов 
	void record(std::ofstream& fout, int mas[n][n]); // запись отредактированного массива в файл
}