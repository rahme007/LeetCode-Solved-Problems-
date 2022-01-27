from typing import List

class Solution:
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {} # Create Dictionary
        for i in range(len(nums)):
            j = target - nums[i] # since sum of two numbers is equal to target
            if j in d.keys(): # if the subtraction result is in the dictionary
                return [i,d[j]]
            else:
                d[nums[i]] = i # else the number is inserted as a key and its index as value
                
s = Solution()
s.twoSum([3,2,4],6)






