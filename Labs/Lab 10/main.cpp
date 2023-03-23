#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;


//Вам даны два объекта, которые связаны между собой.Необходимо создать 2 класса, 
//описывающие эти объекты и принадлежность 2го объекта 1ому.
//Экземпляры классом храните в хипе.
// 
//Вариант 4.
//Страна и города.

class City // Класс "Город" 
{
private:
	unsigned int m_id; // id города
	string m_name;  // название
	unsigned int m_popul; // население 
	unsigned int m_datebuild; // год основания


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
	unsigned int m_id; // id страны
	string m_name;  // имя 
	unsigned int m_popul = 0; // население
	vector<City*> m_cities; // города, входящие в состав страны 
public:
	Country(unsigned int id, string name)
	{
		m_id = id;
		m_name = name;
	}
	void AddCity(City* city) // добавить город в страну
	{
		m_cities.push_back(city);
		m_popul += city->Popul(); // население страны, увеличиваемое с каждым городом
	}

	void PrintCities() // вывести названия городов, входящих в состав страны, их население и год основания
	{
		
		for (size_t i = 0; i < m_cities.size(); i++) 
		{
			cout << "Название города: "<< m_cities[i]->Name()<<endl;
			cout << "Население:       " << m_cities[i]->Popul() << endl;
			cout << "Год образования: " << m_cities[i]->DateBuild() << endl;
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
	City* city1 = new City(0, "Москва",13000000, 1147);
	City* city2 = new City(1, "Калининград", 500000, 1255);

	country1->AddCity(city1);
	country1->AddCity(city2);
	country1->PrintCities();

	cout << "Население страны: " << country1->Popul() << endl;

	


}