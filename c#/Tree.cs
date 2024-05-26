var root = new TreeNode(1);
var tree = new Tree(root);

root.left = new TreeNode(2);
root.right = new TreeNode(3);

root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);

root.right.right = new TreeNode(6);

List<int> preorder = new List<int>();

tree.preorder(root, preorder);
tree.print_tree(preorder, "preorder");

List<int> inorder = new List<int>();

tree.inorder(root, inorder);
tree.print_tree(inorder, "inorder");

List<int> postorder = new List<int>();

tree.postorder(root, postorder);
tree.print_tree(postorder, "postorder");

List<int> levelorder = new List<int>();

tree.levelorder(root, levelorder);
tree.print_tree(levelorder, "level order");

Console.WriteLine($"height: {tree.height(root)}");
class TreeNode
{
  public int data;
  public TreeNode left;
  public TreeNode right;

  public TreeNode(int data)
  {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  public TreeNode root;

  public Tree(TreeNode root)
  {
    this.root = root;
  }

  public void print_tree(List<int> tree, string text)
  {
    Console.Write($"{text}: [");

    for (int i = 0; i < tree.Count; i++) {
      if (i == tree.Count - 1) {
        Console.Write($"{tree[i]}]\n");
      } else {
        Console.Write($"{tree[i]}, ");
      }
    }
  }

  public void preorder(TreeNode root, List<int> arr)
  {
    if (root == null) return;

    arr.Add(root.data);

    this.preorder(root.left, arr);
    this.preorder(root.right, arr);
  }

  public void inorder(TreeNode root, List<int> arr)
  {
    if (root == null) return;

    this.inorder(root.left, arr);

    arr.Add(root.data);

    this.inorder(root.right, arr);
  }

  public void postorder(TreeNode root, List<int> arr)
  {
    if (root == null) return;

    this.postorder(root.left, arr);
    this.postorder(root.right, arr);

    arr.Add(root.data);
  }

  public void levelorder(TreeNode root, List<int> arr)
  {
    List<TreeNode> queue = new List<TreeNode>();

    queue.Add(root);

    while (queue.Count > 0) {
      TreeNode node = queue[0];

      queue.RemoveAt(0);

      arr.Add(node.data);

      if (node.left != null) {
        queue.Add(node.left);
      }

      if (node.right != null) {
        queue.Add(node.right);
      }
    }
  }

  public int height(TreeNode root)
  {
    if (root == null) {
      return 0;
    } else {
      int left = this.height(root.left);
      int right = this.height(root.right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    }
  }
}