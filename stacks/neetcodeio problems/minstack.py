class MinStack:

    def __init__(self):
        self.items = []
        self.m_items = []
        self.m = float('inf')
        

    def push(self, val: int) -> None:
        self.items.append(val)
        if val < self.m:
            self.m = val

    def pop(self) -> None:
        self.items.pop()

        

    def top(self) -> int:
        if self.items:
            return self.items[-1]

    def getMin(self) -> int:
        return min(self.items)

        
