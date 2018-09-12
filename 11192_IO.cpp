#include <iostream>
#include<string>
using namespace std;

int main()
{
	int c;
	string input;
	cin >> c;

	while ((!(c == 0)))
	{
		cin >> input;
		cout << c << endl << input << endl;
		cin >> c;
	}
	return 0;
}
