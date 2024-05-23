<?php
declare(strict_types=1);

class TreeNode
{
  public int $data;
  public ?TreeNode $left;
  public ?TreeNode $right;

  public function __construct(int $data)
  {
    $this->data = $data;
    $this->left = null;
    $this->right = null;
  }
}

class Tree
{
  public TreeNode $root;

  public function __construct(TreeNode $root)
  {
    $this->root = $root;
  }

  public function preorder(?TreeNode $root, array &$arr)
  {
    if ($root === null) return;

    array_push($arr, $root->data);

    $this->preorder($root->left, $arr);
    $this->preorder($root->right, $arr);
  }

  public function inorder(?TreeNode $root, array &$arr)
  {
    if ($root === null) return;

    $this->inorder($root->left, $arr);

    array_push($arr, $root->data);

    $this->inorder($root->right, $arr);
  }

  public function postorder(?TreeNode $root, array &$arr)
  {
    if ($root === null) return;

    $this->postorder($root->left, $arr);
    $this->postorder($root->right, $arr);

    array_push($arr, $root->data);
  }

  public function levelorder(?TreeNode $root, array &$arr)
  {
    if ($root === null) return;

    $queue = [$root];

    while (count($queue) > 0) {
      $node = $queue[0];

      array_push($arr, $node->data);

      array_shift($queue);

      if ($node->left !== null) {
        array_push($queue, $node->left);
      }

      if ($node->right !== null) {
        array_push($queue, $node->right);
      }
    }
  }

  public function height(?TreeNode $root): int
  {
    if ($root === null) {
      return 0;
    } else {
      $left = $this->height($root->left);
      $right = $this->height($root->right);

      if ($left > $right) {
        return $left + 1;
      } else {
        return $right + 1;
      }
    }
  }

  public function print(array $arr, string $text)
  {
    echo "$text: [";

    foreach ($arr as $i => $val) {
      if ($i === count($arr) - 1) {
        echo "$val]\n";
      } else {
        echo "$val, ";
      }
    }
  }
}

$root = new TreeNode(1);
$tree = new Tree($root);

$root->left = new TreeNode(2);
$root->right = new TreeNode(3);

$root->left->left = new TreeNode(4);
$root->left->right = new TreeNode(5);

$root->right->right = new TreeNode(6);

$preorder = [];

$tree->preorder($root, $preorder);

$tree->print($preorder, "preorder");

$inorder = [];

$tree->inorder($root, $inorder);

$tree->print($inorder, "inorder");

$postorder = [];

$tree->postorder($root, $postorder);

$tree->print($postorder, "postorder");

$levelorder = [];

$tree->levelorder($root, $levelorder);

$tree->print($levelorder, "levelorder");

echo "height: " . $tree->height($root);