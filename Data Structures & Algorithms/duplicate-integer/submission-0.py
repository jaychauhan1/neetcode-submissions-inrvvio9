from typing import List
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set() # create an empty set to store see seen numbers
        # A set automatically removes duplicates 
        for num in nums:
            if num in seen:
                return True # return if the duplicate is found 
            seen.add(num) # add the duplicate num to seen

        return False
