

from typing import List
from typing import Optional

class ListNode:
    def __init__(self,val,next = None):
        self.val = val
        self.next = next
        
class Solution:
    
    def addTwoNumbers(self, l1, l2):
        
        dummy = ListNode(0) #Initialize current node to dummy head of the returning list.
        res = dummy
        p,q = l1,l2       # Initialize p and q to head of l1 and l2 respectively.
        sum1,carry = 0,0  #Initialize sum and carry to 0
        
        while p or q: # Loop through lists l1 and l2 until the end
            if p:
                v1 = p.val  #Set v1 to node p's value. If p has reached the end of l1, set to 0.
            else:
                v1 = 0
                
            if q:
                v2 = q.val   #Set v2 to node q's value. If q has reached the end of l2, set to 0.
            else:
                v2 = 0
                
            sum1 = v1 + v2 +carry
            carry = sum1//10
            sum1 = sum1%10
            res.next = ListNode(sum1) #Create a new node with the digit value of sum1 
                                      # and set it to current node's next, then advance current node to next.
            if p:
                p = p.next            #Advance both p and q.
            if q:
                q = q.next
                
            res = res.next
            
        if carry>0:                     #Check if carry = 1, if so append a new node with digit 1 to the returning list.
            res.next = ListNode(carry) 
            
        #print(dummy.next.next.next.val)    
        return dummy.next
            
        
# On LeetCode:
#Runtime: 85 ms, faster than 44.27% of Python3 online submissions for Add Two Numbers.
#Memory Usage: 13.9 MB, less than 98.81% of Python3 online submissions for Add Two Numbers.


# Sample Test Inputs

n2 = ListNode(3)
n1 = ListNode(4,n2)
n = ListNode(2,n1)

m2 = ListNode(4)
m1 = ListNode(6,m2)
m = ListNode(5,m1)


s = Solution()
s.addTwoNumbers(n,m)






