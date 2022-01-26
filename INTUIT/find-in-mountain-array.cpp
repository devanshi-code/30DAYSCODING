
class Solution {
public:
    int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool asc) {
        while(left <= right) {
            int mid = (left + right)/2;
            
            int val = mountainArr.get(mid);

            if(val == target) {
                return mid;
            }
            if(asc) {
                if(val > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if(val > target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        
        int left = 0, right = length - 1, mid, peek;
        
        while(left < right) {
            mid = (left + right)/2;
            
            int a = mountainArr.get(mid);
            int b = mountainArr.get(mid + 1);
            
            if(a > b) {
                right = mid;
                peek = mid;
            }
            else {
                left = mid + 1;
                peek = mid + 1;
            }
        }
        
        int leftSearch = binarySearch(target, mountainArr, 0, peek, true);
        if(leftSearch >= 0) return leftSearch;

        int rightSearch = binarySearch(target, mountainArr, peek, length - 1, false);
        return rightSearch;
    }
};