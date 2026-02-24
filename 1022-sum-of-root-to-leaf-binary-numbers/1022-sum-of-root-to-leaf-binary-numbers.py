# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def calculate_sum(root, binary_str):
            if root is None:
                return 0
            binary_str += str(root.val)
            if root.left is None and root.right is None:
                return binary_to_decimal(binary_str)
            return calculate_sum(root.left, binary_str) + calculate_sum(root.right, binary_str)
        
        def binary_to_decimal(binary_str):
            decimal = 0
            power = 0
            for digit in reversed(binary_str):
                if digit == '1':
                    decimal += 2 ** power
                power += 1
            return decimal
        
        return calculate_sum(root, "")