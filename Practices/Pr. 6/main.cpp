#include<iostream>
#include<vector>
using std::vector;

//»зучите основные операции над вектором и продемонстрируйте их работу :
//1. push_back, erase, insert
//2. emplace_back
//3. resize, reserve, shrink_to_fit, capacity
//4. clear
//5. оператор присваивани€ и []
//”знайте размер вектора и будьте готовы объ€снить, почему именно так.


void print(vector<int>& vect) // вывод содержимого вектора 
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
}

int main()
{
	vector<int> myVec = { 1,2,3,4 }; // создание вектора и инициализаци€ первых элементов
	std::cout << "MyVec: " << "\t";

	print(myVec);
	std::cout << std::endl;


	// 1.1 
	// push_back() - метод, позвол€ющий добавить элемент в конец вектора 

		//myVec.push_back(123); 
		//print(myVec);

	// 1.2
	// erase() - метод, удал€ющий элемент(или диапазон элементов) вектора

		//myVec.erase(myVec.begin()+1,myVec.end()-1); // begin() и end() - итераторы(?) на первый и последний элементы вектора соответственно 
		//print(myVec);

	// 1.3
	// insert() - метод, позвол€ющий добавить элемент(или несколько элементов) в определЄнную позицию в векторе

		//myVec.insert(myVec.begin() + 1, 5);
		//print(myVec);

	// 2
	// emplace_back() - метод, позвол€ющий добавить элемент в конце вектора (так же, как и push_back())

		//myVec.emplace_back(321);
		//print(myVec);

	// 3.1
	// resize() - метод, позвол€ющий изменить размер вектора 

		//myVec.resize(2); // изменить размер до 2 элементов
		//print(myVec);

		//myVec.resize(6, 9); // дополнит вектор до 6-и элементов, заполнив новые позиции элементом 9
		//print(myVec);


	// 3.2, 3.4 
	// reserve() - метод, дающий возможность зарезервировать пам€ть дл€ элементов вектора
	// capacity() - метод, которые возвращает количество элементов, выделенное дл€ вектора

		//std::cout << myVec.capacity() << std::endl; 

		//myVec.reserve(10);

		//std::cout << myVec.capacity() << std::endl;


	// 3.3
	// shrink_to_fit() - метод, позвол€ющий выровн€ть пам€ть, выделенную дл€ элементов вектора с пам€тью, зан€той элементами этого вектора

		//myVec.reserve(10);
		//std::cout << myVec.capacity() << std::endl;

		//myVec.shrink_to_fit();

		//std::cout << myVec.capacity() << std::endl;

	// 4
	// clear() - метод, удал€ющий все элементы вектора

		//myVec.clear();
		//print(myVec);

	// 5
	// ќператор присваивани€ и []

		//vector<int> myVec2(15);

		//myVec2 = myVec; // позвол€ет присвоить одному вектора значени€ другого 

		//print(myVec2);
		//std::cout << std::endl;

		//std::cout << myVec[0] << " < " << myVec[1] << std::endl; // позвол€ет обратитьс€ к определЄнному элементу 

	//std::cout << sizeof(myVec) << std::endl;
}