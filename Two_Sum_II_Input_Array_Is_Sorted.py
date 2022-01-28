
# Note: The solution approach resembles Binary Search Algorithm

from typing import List

class Solution:
    
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l,r = 0, len(numbers)-1 # Declare left and right pointer
        
        while l<r:     # Same as Binary Search
            if numbers[l]+ numbers[r]>target: # Checking target if it is less than the sum since the array is sorted
                r -= 1              # if the condition meets, the right pointer will be decremented to get closer to the target
            
            elif numbers[l]+ numbers[r]<target: # Abovementioned rule can be applied in here for left pointer as well.
                l += 1                          # This time, the left pointer will be incremented 
            else:
                return [l+1,r+1] # Since the indices are needed to start from 1.
            
# Runtime: 100 ms, faster than 31.02% of Python3 online submissions for Two Sum II - Input Array Is Sorted.
# Memory Usage: 14.5 MB, less than 87.16% of Python3 online submissions for Two Sum II - Input Array Is Sorted.

s = Solution()
s.twoSum([2,7,11,15],9)






