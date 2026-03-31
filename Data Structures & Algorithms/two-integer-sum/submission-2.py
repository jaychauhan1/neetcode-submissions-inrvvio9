class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # we need a hashmap
        # key is the number and the vlaue is the index
        hashmap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            else:
                hashmap[num] = i
                

        