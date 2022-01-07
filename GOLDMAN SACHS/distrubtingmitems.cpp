
#include<bits/stdc++.h>
using namespace std;

int lastpos(int A,int B,int C)
{
    if(B<=A-C+1)
      return B+C-1;

     B = B - (A - C + 1);  
     return (B % A == 0) ? A : (B % A);
}
int main()
{
    int A = 5;
    int B = 8;
    int C = 2;
    cout << lastPosition(A, B, C);
    return 0;

}
