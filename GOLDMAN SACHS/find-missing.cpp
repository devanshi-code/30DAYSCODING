class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        vector<bool> nums(n+1, 0);

        int repeated;
        
        int ans[2];

        for(int i = 0; i < n; ++i) {
            int num = arr[i];
            if(nums[num]) {
                ans[0] = num;
            }
            nums[num] = nums[num] ^ 1;
        }

        for(int i = 1; i <= n; ++i) {
            if(nums[i] == 0 && i != ans[0]) {
                ans[1] = i;
                break;
            }
        }

        int *ptr;
        ptr = ans;

        return ptr;

    }
};