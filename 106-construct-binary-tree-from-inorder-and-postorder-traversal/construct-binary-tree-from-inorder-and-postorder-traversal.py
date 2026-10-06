class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> TreeNode | None:
        if not inorder or not postorder:
            return None

        inorder_map = {val: idx for idx, val in enumerate(inorder)}

        def build(in_start: int, in_end: int) -> TreeNode | None:
            if in_start > in_end:
                return None

            root_val = postorder.pop()
            root = TreeNode(root_val)
            idx = inorder_map[root_val]

            root.right = build(idx + 1, in_end)
            root.left = build(in_start, idx - 1)

            return root

        return build(0, len(inorder) - 1)