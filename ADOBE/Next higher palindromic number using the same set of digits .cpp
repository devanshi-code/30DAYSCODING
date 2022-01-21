#include <bits/stdc++.h>
using namespace std;


 

class Solution{
  public:
    string nextPalin(string num) { 
      
        int n= num.size();
        if (n <= 3) 
        {
        return "-1";
        }
    
       
        int mid = n / 2 - 1;
        int i, j;
    
        
        for (i = mid - 1; i >= 0; i--)
            if (num[i] < num[i + 1])
                break;
        
       
        if (i < 0) {
           
            return "-1";
        }
    
        
        int smallest;
        
        for (j = mid; j >=0; j--)
        {
            if (num[j] > num[i])
            {
                smallest = j;
                break;
            }
                
        }
        
            
    
        swap(num[i], num[smallest]);
    


        swap(num[n - i - 1], num[n - smallest - 1]);
    
        
        reverse(num.begin()+i+1,num.begin()+mid+1);
    
       
        if (n % 2 == 0)
            reverse(num.begin()+mid+1,num.begin()+n-i-1);
        else
        reverse(num.begin()+mid+2,num.begin()+n-i-1);
    
        
        return num;
    }
};



int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  