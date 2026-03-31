class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0 # start index
        right = len(nums) - 1 #end index

        while left <= right:
            middle = (left + right) //  2 # finding the middle index

            if nums[middle] == target:
                return middle
            
            elif nums[middle] > target:
                right = middle - 1
            
            else:
                left = middle + 1

        return -1
