class Solution {
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        ans.push_back(a[n-1]);

        int max_val = a[n-1];

        for(int i = 1; i < n; ++i){
            if(max_val <= a[n - i - 1]) {
                ans.push_back(a[n - i - 1]);
                max_val = a[n - i - 1];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};