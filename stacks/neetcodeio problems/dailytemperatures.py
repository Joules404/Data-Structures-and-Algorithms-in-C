class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = [] #should keep track of (value,index)
        res = [0] * len(temperatures) 
        for index,temp in enumerate(temperatures): 
            while stack and temp > stack[-1][0]:
                top_v,top_i = stack.pop()
                res[top_i] = index - top_i
            stack.append((temp,index))
        return res
                        

        