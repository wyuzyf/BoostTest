

#include <iostream>


using namespace std;

int main()
{
	int i, k,l,p;
	k = 0;
	p = 0;


	for (i = 0; i < 10; k = i, ++i)
	{
		cout << "---\n" << endl;
		cout << k << endl;
		cout << i << endl;
	}

	cout << "i====== \n" <<i<< endl;
	cout << "\\\\\\\\\\\n" << endl;

	for (l = 0; l < 10; p = l, l++)
	{
		cout << "---\n" << endl;
		cout << p << endl;
		cout << l << endl;
	}
	cout << "l====== \n" << l << endl;

	system("pause");
}
