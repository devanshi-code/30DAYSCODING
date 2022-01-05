class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int start,end;
        start=end=0;
        long long int p=1;
        int count=0;
        while(end<n){
            p*=a[end];
            while(start<n && p>=k){
                p/=a[start];
                start++;
            }
            if(p<k){
              count+=end-start+1;
              end++;
            }
        }
        return count;
        
         
    }
};