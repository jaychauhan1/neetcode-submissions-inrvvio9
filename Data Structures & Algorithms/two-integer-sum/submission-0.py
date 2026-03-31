class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for j, x in enumerate(nums):
            need = target - x 
            if need in seen: 
                i = seen[need]
                return [i, j]
            if x not in seen:
                seen[x] = j 
        raise ValueErorr("No valid pair found")
        