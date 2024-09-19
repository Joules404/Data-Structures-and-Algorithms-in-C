class Solution:
    def isValid(self, s: str) -> bool:
        d_o = {
            '(':')',
            '{':'}',
            '[':']'
        }
        stack = []
        for c in s:
            if(c in d_o):
                stack.append(c)
            else:
                if(stack and d_o[stack[-1]] == c):
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
            
        