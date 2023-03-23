#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//Воспользуйтесь первым принципом ООП, абстракцией, и сформируйте класс, включив в него только минимальный 
// набор переменных(полей) для заданного вашим вариантом объекта.
//
//Используйте второй принцип ООП, инкапсуляцию, чтобы не допустить некорректного ввода параметров.
//
//Добавьте в класс функции(методы), которые позволят решить задачу.Продемонстрируйте решение.
//
//Вариант 4.
//
//Найти периметр прямоугольника

class rectangle
{
private:

	double m_rectside_a=0,m_rectside_b=0; // стороны
	double m_rectarea=0; // площадь

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