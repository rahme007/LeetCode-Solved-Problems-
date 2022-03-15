
from typing import List

# The solution class concentrates on in-place with O(1) memory

class Solution:

    def removeDuplicates(self, nums: List[int]) -> int:

        left, right = 0, 1 # the approach starts with two pointer solution; left: for the unique values; 
                            # right: for traversing the list


        while right< len(nums):

            if nums[left]==nums[right]:    # if the element repeats, just increment the right pointer
                right += 1
            else:
                left +=1                  # increment the count of unique values
                temp = nums[right]        # start swapping values. Note: efficient way to swap in python is:
                nums[right] = nums[left]  # nums[left], nums[right] = nums[right], nums[left]
                nums[left] = temp
                right +=1                 # increment the right pointer


        return left+1

#on Leetcode
#Runtime: 103 ms, faster than 74.44% of Python3 online submissions for Remove Duplicates from Sorted Array.
#Memory Usage: 15.6 MB, less than 71.04% of Python3 online submissions for Remove Duplicates from Sorted Array.

s = Solution()
s.removeDuplicates([0,0,1,1,1,2,2,3,3,4])





