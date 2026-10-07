class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # Step 1: Calculate minimum misplaced '(' and ')'
        left_rem = 0
        right_rem = 0
        
        for char in s:
            if char == '(':
                left_rem += 1
            elif char == ')':
                if left_rem > 0:
                    left_rem -= 1
                else:
                    right_rem += 1
        
        res = set()
        
        # Step 2: Backtracking function
        def backtrack(index, left_count, right_count, left_rem, right_rem, path):
            if index == len(s):
                if left_rem == 0 and right_rem == 0 and left_count == right_count:
                    res.add("".join(path))
                return
            
            char = s[index]
            
            # Option 1: Try removing the current parenthesis (if budget permits)
            if char == '(' and left_rem > 0:
                backtrack(index + 1, left_count, right_count, left_rem - 1, right_rem, path)
            elif char == ')' and right_rem > 0:
                backtrack(index + 1, left_count, right_count, left_rem, right_rem - 1, path)
                
            # Option 2: Keep the current character
            path.append(char)
            if char not in '()':
                backtrack(index + 1, left_count, right_count, left_rem, right_rem, path)
            elif char == '(':
                backtrack(index + 1, left_count + 1, right_count, left_rem, right_rem, path)
            elif char == ')' and left_count > right_count:
                # Only keep ')' if there is a matching open '('
                backtrack(index + 1, left_count, right_count + 1, left_rem, right_rem, path)
            path.pop()

        backtrack(0, 0, 0, left_rem, right_rem, [])
        return list(res)