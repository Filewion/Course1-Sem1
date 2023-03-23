#include <iostream>
using std::cout;
class dynmassiv // свой дин. массив
{
private:
	int m_size;
	int* m_data;
public:
	dynmassiv()
	{
		m_size = 0;
		m_data = nullptr;
	}
	dynmassiv(int value)
	{
		m_size = value;
		m_data = new int[m_size];
		for (int i = 0; i < m_size; i++)
			m_data[i] = 0;
	}
	void push_back(int value)
	{
		m_size++;
		int* data = new int[m_size];
		for (int i = 0; i < m_size - 1; i++)
		{
			data[i] = m_data[i];
		}
		data[m_size - 1] = value;
		delete[] m_data;
		m_data = data;
	}
	int size()
	{
		return m_size;
	}
	int get(int i)
	{
		if (i < m_size)
			return m_data[i];
	}
	void set(int i, int value)
	{
		if (i < m_size)
		{
			m_data[i] = value;
		}
	}

	void erase(int i)
	{
		for (int j = i; j < m_size - 1; j++)
		{
			m_data[j] = m_data[j + 1];
		}
		m_size--;
		int* data = new int[m_size];
		for (int i = 0; i < m_size; i++)
		{
			data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
	}

	void insert(int i, int value)
	{
		m_size++;
		int* data = new int[m_size];
		for (int i = 0; i < m_size - 1; i++)
		{
			data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		for (int j = m_size - 1; j > i; j--)
			m_data[j] = m_data[j - 1];
		m_data[i] = value;
	}

	void print()
	{
		for (int i = 0; i < m_size; i++)
			cout << m_data[i];
	}


	~dynmassiv()
	{
		delete[] m_data;
	}

};

int main()
{
	dynmassiv qqq(5);
	qqq.set(0, 0);
	qqq.set(1, 1);
	qqq.set(2, 2);
	qqq.set(3, 3);
	qqq.set(4, 4);

	

	qqq.print();

}