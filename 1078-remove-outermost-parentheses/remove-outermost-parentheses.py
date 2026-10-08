class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = []
        opened = 0
        
        for char in s:
            if char == '(':
                if opened > 0:
                    res.append(char)
                opened += 1
            else:
                opened -= 1
                if opened > 0:
                    res.append(char)
                    
        return "".join(res)