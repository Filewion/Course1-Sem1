#include <iostream>

//������� 4.
//
//���� ����� ����� ���� unsigned short, 
//�������� �� ����� ���������� ������� �� ��� ������, ��������� ������ �� ����������.

int main()
{
	unsigned short n; 
	std::cin >> n;

	unsigned char* pb = (unsigned char*)&n; // ��������� ���� unsigned char, �������� ����� ������� ����� ���������� n

	for (int i = 0; i < sizeof(n); i++)
	{
		std::cout << (int*)(pb+i) <<"\t"; //  ����� �����
		std::cout << (int)(*(pb+i)) << std::endl; // ���������� ����� � 10��.
	}


}