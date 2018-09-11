// Your name : Holden Hall
//Problem name: Decoder
// Problem UVa number: 458
//Your UVa login name: SHOGUN_
/////////////////////////////////////////////////////////////////////


#include <iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		for (int i = 0; i < input.length(); i++)
		{
			input[i] -= 7;
			cout << input[i];
		}
		cout << endl;
	}
    return 0;
}
