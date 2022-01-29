
# The first two methods inside the Solution class are used to sort the list
# However, one can use built-in sorting methods in python

from typing import List

class Solution:
    
    def mergeSort(self,a: List[int],b: List[int])-> List[List[int]]: # easy and popular sorting method
        pa,pb = 0,0           # Declaring pa and pb poiners for a and b lists, respectively
        mergedList = []       # Initialization of mergedList as an empty list
        
        while pa<len(a) and pb<len(b):
            if a[pa]< b[pb]:              # if true, then the element of list a gets inserted 
                mergedList.append(a[pa])  #and pa pointer will be incremented
                pa += 1
            else:
                mergedList.append(b[pb])
                pb += 1
            
        if a:
            mergedList.extend(a[pa:])
        if b:
            mergedList.extend(b[pb:])
        
        return mergedList
    
    def divideConquer(self,n: List[int]) -> List[List[int]]: #divide and conquer approach i.e. recursive method applied 
                                                             #to sort the first and second half of the list
        
        lengthList = len(n)
        
        if lengthList<=1:
            return n
        
        else:
            mid = lengthList//2
            left = self.divideConquer(n[:mid])
            right = self.divideConquer(n[mid:])
            return self.mergeSort(left,right)
            
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        sorted_nums = self.divideConquer(nums)
        
        l,r = 0, len(nums)-1
        triplets = []
        
        for n,a in enumerate(sorted_nums):
            if n>0 and a==sorted_nums[n-1]: # The statement is checking 
                continue
            l = n+1
            r = len(nums)-1
            
            while l<r:  # using the idea of Binary Search algorithm
                k = sorted_nums[l]+sorted_nums[r] 
                if k+a == 0: 
                    triplets.append([a,sorted_nums[l],sorted_nums[r]])
                    l += 1                                           # pointer increment (r -= 1 is also correct)
                    while sorted_nums[l]== sorted_nums[l-1] and l<r: # This is to avoid repetition inside the traversing list
                        l += 1
                elif k+a <0:
                    l += 1
                else:
                    r -= 1
                    
        return triplets

# On LeetCode:
#Runtime: 1118 ms, faster than 56.04% of Python3 online submissions for 3Sum.
#Memory Usage: 18.3 MB, less than 15.22% of Python3 online submissions for 3Sum.

s= Solution()
s.divideConquer([1,4,5,2,4,3])
s.threeSum([-1,0,1,2,-1,-4])





