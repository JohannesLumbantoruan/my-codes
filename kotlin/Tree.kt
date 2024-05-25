class TreeNode(
  val data: Int,
  var left: TreeNode? = null,
  var right: TreeNode? = null
)

class Tree(val root: TreeNode) {
  fun preorder(root: TreeNode?, arr: MutableList<Int>) {
    if (root == null) return

    arr.add(root.data)

    this.preorder(root.left, arr)
    this.preorder(root.right, arr)
  }

  fun inorder(root: TreeNode?, arr: MutableList<Int>) {
    if (root == null) return

    this.inorder(root.left, arr)

    arr.add(root.data)

    this.inorder(root.right, arr)
  }

  fun postorder(root: TreeNode?, arr: MutableList<Int>) {
    if (root == null) return

    this.postorder(root.left, arr)
    this.postorder(root.right, arr)

    arr.add(root.data)
  }

  fun levelorder(root: TreeNode, arr: MutableList<Int>) {
    val queue = mutableListOf(root)

    while (queue.size > 0) {
      val node = queue.removeAt(0)

      arr.add(node.data)

      val left = node.left;

      if (left != null) {
        queue.add(left)
      }

      val right = node.right;

      if (right != null) {
        queue.add(right)
      }
    }
  }

  fun height(root: TreeNode?): Int {
    if (root == null) {
      return 0
    } else {
      val left = this.height(root.left)
      val right = this.height(root.right)

      if (left > right) {
        return left + 1
      } else {
        return right + 1
      }
    }
  }
}

fun main() {
  val root = TreeNode(1)
  val tree = Tree(root)

  root.left = TreeNode(2)
  root.right = TreeNode(3)

  root.left?.left = TreeNode(4)
  root.left?.right = TreeNode(5)

  root.right?.right = TreeNode(6)

  val preorder = mutableListOf<Int>()

  tree.preorder(root, preorder)
  println("preorder: $preorder")

  val inorder = mutableListOf<Int>()

  tree.inorder(root, inorder)
  println("inorder: $inorder")

  val postorder = mutableListOf<Int>()

  tree.postorder(root, postorder)
  println("postorder: $postorder")

  val levelorder = mutableListOf<Int>()

  tree.levelorder(root, levelorder)
  println("level order: $levelorder")

  println("height: ${tree.height(root)}")
}