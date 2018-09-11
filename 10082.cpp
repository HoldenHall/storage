// Your name : Holden Hall
//Problem name: WERTYU
// Problem UVa number: 10082
//Your UVa login name: SHOGUN_
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	string in = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./ ";
	string out = "``1234567890-QQWERTYUIOP[]AASDFGHJKL;ZZXCVBNM,. "; 
	while (getline(cin, input))
	{
		for (int i = 0; i < input.length(); i++)
		{
			int j = in.find(input[i]);
			cout << out[j];
		}
		cout << endl;
	}
	return 0;
}

