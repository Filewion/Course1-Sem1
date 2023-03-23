#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//�������������� ������ ��������� ���, �����������, � ����������� �����, ������� � ���� ������ ����������� 
// ����� ����������(�����) ��� ��������� ����� ��������� �������.
//
//����������� ������ ������� ���, ������������, ����� �� ��������� ������������� ����� ����������.
//
//�������� � ����� �������(������), ������� �������� ������ ������.����������������� �������.
//
//������� 4.
//
//����� �������� ��������������

class rectangle
{
private:

	double m_rectside_a=0,m_rectside_b=0; // �������
	double m_rectarea=0; // �������

public:
	rectangle(double rectside_a, double rectside_b)
	{
		if (rectside_a > 0 && rectside_b > 0)
		{
			m_rectside_a = rectside_a;
			m_rectside_b = rectside_b;
			m_rectarea = rectside_a * rectside_b;
		}
		else
			cout << "Error: incorrect data" << endl;
	}

	~rectangle() {}

	double AreaOfRectangle()
	{
		return m_rectarea;
	}
};

int main()
{
	double a, b;
	cin >> a >> b;

	rectangle rect1(a, b);
	cout<< rect1.AreaOfRectangle();
}