#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
     
    long long t[1000][1000];
    
    long long f(vector<int> &a,int n,int i,int j)
    {
        
        if(i==j)  return t[i][j]=a[i];
        
       
        if(j==i+1) return t[i][j]=max(a[i],a[j]);
        
      
        
       if(t[i][j]!=-1)  return t[i][j];
       
        
        return t[i][j]=max(a[i] + min(f(a,n,i+2, j), f(a,n,i+1, j-1) ),
                           a[j]+ min(f(a,n,i+1, j-1), f(a,n,i, j-2) )) ;
    }
    
    
    
    int maxCoins(vector<int>&A,int n)
    {
        memset(t,-1, sizeof t) ;
        
        return f(A,n,0,n-1) ;
	    
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}