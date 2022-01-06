class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        int left = 0, right = 0;
        int min_size = INT_MAX;
        
        for(int n: nums) {
            
            sum += n;

            while (sum >= target) {
                min_size = min(min_size, right - left + 1);
                sum -= nums[left++];
            }

            ++right;
        }

        return min_size == INT_MAX ? 0 : min_size;
    }
};