class Solution {
    public:
    vector<int> subarraySum(int arr[], int n, long long s) {

        int left = 0, right = 0;
        long long sum = (long long) arr[0];
        int changed = true;

        while(changed) {
            changed = false;
            while(left < n && sum > s) {
                sum -= (long long) arr[left];
                ++left;
                changed = true;
            }
            while(right < n - 1 && sum < s) {
                ++right;
                sum += (long long) arr[right];
                changed = true;
            }
            if(sum == s) {
                break;
            }
        }

        if(sum == s) {
            vector<int> ans(2, 0);
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        }
        else {
            vector<int> ans(1, -1);
            return ans;
        }
    }
};