class Solution{
    public:
    string colName (long long int n)
    {
        string ans;

        while(n) {
            ans += (char) ('A' + (n-1) % 26);
            n = (n-1)/26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};