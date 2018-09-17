#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  int N,n;
  int sz;
  cin >> sz;
  vector <vector<int> > MAT(sz,vector<int>(sz));
  //input sample using ints
  for(int r =0; r<sz;r++)
    for (int c =0; c<sz;c++)
      cin >> MAT[r][c];
  //print
  for(int r =0; r<sz;r++)
   { 
     for (int c =0; c<sz;c++)
      {
      cout << MAT[r][c];
      }
      cout << endl;
   }

   cin>> N >>n;
   while(!(N==0  && n==0))
   {
     
   }

}
