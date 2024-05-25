class TreeNode:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

class Tree:
  def __init__(self, root):
    self.root = root

  def preorder(self, root, arr):
    if root == None: return

    arr.append(root.data)

    self.preorder(root.left, arr)
    self.preorder(root.right, arr)

  def inorder(self, root, arr):
    if root == None: return

    self.inorder(root.left, arr)

    arr.append(root.data)

    self.inorder(root.right, arr)

  def postorder(self, root, arr):
    if root == None: return

    self.postorder(root.left, arr)
    self.postorder(root.right, arr)

    arr.append(root.data)

  def levelorder(self, root, arr):
    queue = [root]

    while len(queue) > 0:
      node = queue.pop(0)

      arr.append(node.data)

      if node.left != None:
        queue.append(node.left)

      if node.right != None:
        queue.append(node.right)

  def height(self, root):
    if root == None:
      return 0
    else:
      left = self.height(root.left)
      right = self.height(root.right)

      if left > right:
        return left + 1
      else:
        return right + 1

root = TreeNode(1)
tree = Tree(root)

root.left = TreeNode(2)
root.right = TreeNode(3)

root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

root.right.right = TreeNode(6)

preorder = []
tree.preorder(root, preorder)

print(f"preorder: {preorder}")

inorder = []
tree.inorder(root, inorder)

print(f"inorder: {inorder}")

postorder = []
tree.postorder(root, postorder)

print(f"postorder: {postorder}")

levelorder = []
tree.levelorder(root, levelorder)

print(f"level order: {levelorder}")

print(f"height: {tree.height(root)}")