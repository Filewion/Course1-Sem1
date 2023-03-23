#include <iostream>

//Вариант 4.
//
//Дано целое число типа unsigned short, 
//выведите на экран содержимое каждого из его байтов, используя знания по указателям.

int main()
{
	unsigned short n; 
	std::cin >> n;

	unsigned char* pb = (unsigned char*)&n; // указатель типа unsigned char, хранящий адрес первого байта переменной n

	for (int i = 0; i < sizeof(n); i++)
	{
		std::cout << (int*)(pb+i) <<"\t"; //  адрес байта
		std::cout << (int)(*(pb+i)) << std::endl; // содержимое байта в 10сс.
	}


}