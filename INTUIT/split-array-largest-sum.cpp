class Solution {
public:
    int minLargestSum(vector<int>& nums, int m, int start, int end, vector<int>& presum, vector<vector<int>>& cache) {
        if(m == 1) {
            return presum[end] - presum[start];
        }
        if(cache[start][m] != -1) return cache[start][m];

        int ans = INT_MAX;

        for(int i = start + 1; i <= end - m + 1; ++i) {
            int largest_sum = max(
                presum[i] - presum[start],
                minLargestSum(nums, m - 1, i, end, presum, cache)
            );
            ans = min(ans, largest_sum);
        }

        return cache[start][m] = ans;
    }
    
    int splitArray(vector<int>& nums, int m) {

        vector<int> presum(nums.size() + 1, 0);
        vector<vector<int>> cache(nums.size(), vector<int>(m+1, -1));

        for(int i = 0; i < nums.size(); ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }
        
        return minLargestSum(nums, m, 0, nums.size(), presum, cache);
    }
};