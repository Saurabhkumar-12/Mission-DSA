class Solution(object):
    def sumNumbers(self, root):
        if not root:
            return 0
        
        Q = [(root, root.val)]
        total_sum = 0
        
        while Q:
            node, current_sum = Q.pop(0)
            
            if not node.left and not node.right:
                total_sum += current_sum
                
            if node.left:
                Q.append((node.left, current_sum * 10 + node.left.val))
            if node.right:
                Q.append((node.right, current_sum * 10 + node.right.val))
                
        return total_sum