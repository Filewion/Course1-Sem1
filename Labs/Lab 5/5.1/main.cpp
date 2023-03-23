#include<iostream>
using std::cout;
using std::endl;
using std::cin;
//
// Дана строка длиной не более 100 символов. Удалить в ней все согласные буквы.
//

int main()
{
	const int N = 100;
	char str[N]{}, letters[] = "eyuio", rightstr[N]{};
	cin.getline(str, N + 1);
	cout << str << endl;

	int t = 0;
	for (int i = 0; i < strlen(str); i++)
		for (int j = 0; j < strlen(letters); j++)
			if (str[i] == letters[j])
			{
				rightstr[t] = str[i];
				t++;
				break;
			}
	for (int i = 0; i < strlen(rightstr); i++)
		cout << rightstr[i];

}