from Node import Node

class TreeNode(Node):
    left: 'TreeNode'
    right: 'TreeNode'
    
    
    def setLeft(self, left: 'TreeNode'):
        self.left = left
        
    def setRight(self, right: 'TreeNode'):
        self.right = right
        
        