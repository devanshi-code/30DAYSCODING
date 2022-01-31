class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       long long ans = 1;
       long long n = N;
       while(R){
           if(R%2 == 0){
               n = (n*n)%mod;
               R = R/2;
           }else{
               ans = (ans*n)%mod;
               R--;
           }
       }
    return ans%mod;    
    }

};


long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




