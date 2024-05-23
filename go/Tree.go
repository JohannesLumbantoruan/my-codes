package main

import (
	"fmt"
)

type TreeNode struct {
	data int
	left *TreeNode
	right *TreeNode
}

type Tree struct {
	root *TreeNode
}

func (t Tree) preorder(root *TreeNode, arr *[]int) {
	if root == nil {
		return
	}

	*arr = append(*arr, root.data)

	t.preorder(root.left, arr)
	t.preorder(root.right, arr)
}

func (t Tree) inorder(root *TreeNode, arr *[]int) {
	if root == nil {
		return
	}

	t.inorder(root.left, arr)

	*arr = append(*arr, root.data)

	t.inorder(root.right, arr)
}

func (t Tree) postorder(root *TreeNode, arr *[]int) {
	if root == nil {
		return
	}

	t.postorder(root.left, arr)
	t.postorder(root.right, arr)

	*arr = append(*arr, root.data)
}

func (t Tree) levelorder(root *TreeNode, arr *[]int) {
	queue := []*TreeNode{ root }

	for len(queue) > 0 {
		node := queue[0]

		*arr = append(*arr, node.data)

		queue = queue[1:]

		if node.left != nil {
			queue = append(queue, node.left)
		}

		if node.right != nil {
			queue = append(queue, node.right)
		}
	}
}

func (t Tree) height(root *TreeNode) int {
	if root == nil {
		return 0
	} else {
		left := t.height(root.left)
		right := t.height(root.right)

		if left > right {
			return left + 1
		} else {
			return right + 1
		}
	}
}

func main() {
	root := TreeNode{ 1, nil, nil }
	tree := Tree{ &root }

	root.left = &TreeNode{ 2, nil, nil }
	root.right = &TreeNode{ 3, nil, nil }

	root.left.left = &TreeNode{ 4, nil, nil }
	root.left.right = &TreeNode{ 5, nil, nil }

	root.right.right = &TreeNode{ 6, nil, nil }

	preorder := []int{}

	tree.preorder(&root, &preorder)

	fmt.Printf("preorder: %v\n", preorder)

	inorder := []int{}

	tree.inorder(&root, &inorder)

	fmt.Printf("inorder: %v\n", inorder)

	postorder := []int{}

	tree.postorder(&root, &postorder)

	fmt.Printf("postorder: %v\n", postorder)

	levelorder := []int{}

	tree.levelorder(&root, &levelorder)

	fmt.Printf("level order: %v\n", levelorder)
	fmt.Printf("height: %v\n", tree.height(&root))
}