class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Keep searching while the left boundary does not cross the right
        while (left <= right) {
            // find the middle index
            int mid = left + (right - left) / 2; // avoid potential integer overflow 

            // edge case: if the middle element is the target
            if (nums[mid] == target) {
                return mid; // found the target, return the index
            }
            // if the middle element is smaller than the target
            else if (nums[mid] < target) {
                left = mid + 1; // search the right half
            }
            // if the middle element is larger than the target
            else {
                right = mid - 1; // search the left half
            }  
        } 
        return -1; // target not found
    }
};
