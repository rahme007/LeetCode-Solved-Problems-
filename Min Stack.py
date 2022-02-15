
class MinStack:

    def __init__(self):
        self.stack = []
        self.mstack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.mstack:
            v = self.mstack[-1]
            if v>val:
                self.mstack.append(val)
            else:
                self.mstack.append(v)
        else:
            self.mstack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.mstack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.mstack[-1]

#Runtime: 56 ms, faster than 95.07% of Python3 online submissions for Min Stack.
#Memory Usage: 18.3 MB, less than 33.94% of Python3 online submissions for Min Stack.

minStack = MinStack()
minStack.push(-2)
minStack.push(0)
minStack.push(-3)
print(minStack.getMin()) # return -3
minStack.pop()
print(minStack.top())    # return 0
print(minStack.getMin()) # return -2





