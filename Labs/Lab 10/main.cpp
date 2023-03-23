#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;


//��� ���� ��� �������, ������� ������� ����� �����.���������� ������� 2 ������, 
//����������� ��� ������� � �������������� 2�� ������� 1���.
//���������� ������� ������� � ����.
// 
//������� 4.
//������ � ������.

class City // ����� "�����" 
{
private:
	unsigned int m_id; // id ������
	string m_name;  // ��������
	unsigned int m_popul; // ��������� 
	unsigned int m_datebuild; // ��� ���������


public:
	City(unsigned int id, string name,unsigned int popul,unsigned int datebuild)
	{
		m_id = id;
		m_name = name;
		m_popul = popul;
		m_datebuild = datebuild;
	}

	string Name() 
	{
		return m_name;
	}

	unsigned int Popul()
	{
		return m_popul;
	}
	unsigned int DateBuild()
	{
		return m_datebuild;
	}
};



class Country
{
private:
	unsigned int m_id; // id ������
	string m_name;  // ��� 
	unsigned int m_popul = 0; // ���������
	vector<City*> m_cities; // ������, �������� � ������ ������ 
public:
	Country(unsigned int id, string name)
	{
		m_id = id;
		m_name = name;
	}
	void AddCity(City* city) // �������� ����� � ������
	{
		m_cities.push_back(city);
		m_popul += city->Popul(); // ��������� ������, ������������� � ������ �������
	}

	void PrintCities() // ������� �������� �������, �������� � ������ ������, �� ��������� � ��� ���������
	{
		
		for (size_t i = 0; i < m_cities.size(); i++) 
		{
			cout << "�������� ������: "<< m_cities[i]->Name()<<endl;
			cout << "���������:       " << m_cities[i]->Popul() << endl;
			cout << "��� �����������: " << m_cities[i]->DateBuild() << endl;
			cout << endl;
		}
	}
	int Popul() 
	{
		return m_popul;
	}

};

int main()
{
	setlocale(LC_ALL, "rus");
	Country* country1 = new Country(0, "Russia");
	City* city1 = new City(0, "������",13000000, 1147);
	City* city2 = new City(1, "�����������", 500000, 1255);

	country1->AddCity(city1);
	country1->AddCity(city2);
	country1->PrintCities();

	cout << "��������� ������: " << country1->Popul() << endl;

	


}