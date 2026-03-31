class Solution {
public:
    int findMin(std::vector<int>& nums) {
        // Initialize the left and right pointers for our search space.
        int left = 0;
        int right = nums.size() - 1;

        // Binary search loop
        while (left < right) {
            // Calculate the middle index safely to prevent integer overflow.
            int mid = left + (right - left) / 2;

            // This is the core logic. We compare the middle element with the rightmost element.
            if (nums[mid] > nums[right]) {
                // Case 1: The minimum element is in the right half.
                // If nums[mid] is greater than nums[right], it means the array is not sorted from mid to right.
                // The pivot point (minimum element) must lie somewhere in the range [mid + 1, right].
                // Example: [3, 4, 5, 6, 1, 2] -> if mid is 5, right is 2. 5 > 2, so the minimum is to the right.
                left = mid + 1;
            } else {
                // Case 2: The minimum element is in the left half, or is the mid element itself.
                // If nums[mid] is less than or equal to nums[right], the array segment from mid to right is sorted.
                // This implies that the minimum element is either nums[mid] or in the left half of the search space.
                // We update right to mid, because mid could be the minimum. We don't do mid - 1.
                // Example: [4, 5, 0, 1, 2, 3] -> if mid is 0, right is 3. 0 < 3, so the minimum is 0 or to the left.
                right = mid;
            }
        }
        
        // When the loop terminates, left and right will point to the same index.
        // This single remaining element is the minimum.
        return nums[left];
    }
};