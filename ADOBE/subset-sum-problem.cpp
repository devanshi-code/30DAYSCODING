class Solution {
public:
    int equalPartition(int N, int arr[])
    {
        sort(arr, arr+N);

	    int sum = accumulate(arr, arr + N, 0);

	    if(sum & 1) return 0;

	    int half = sum/2;

	    vector< vector<int> > dp(N + 1, vector<int>(half + 1, 0));

	    for(int i = 0; i < N; ++i) {
	        for(int j = 1; j <= half; ++j) {
	            if(j < arr[i]) {
	                dp[i+1][j] = dp[i][j];
	                continue;
	            }
	            dp[i+1][j] = max({arr[i], dp[i][j - arr[i]] + arr[i], dp[i][j]});
	        }
	    }

        return half == dp.back().back();
    }
};