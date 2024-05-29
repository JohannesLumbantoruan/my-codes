package main

import "fmt"

func main() {
	tree := []*int{}

	for i := 1; i <= 7; i++ {
		value := i

		if i == 6 {
			tree = append(tree, nil)
		} else if i == 7 {
			n := 6
			tree = append(tree, &n)
		} else {
			tree = append(tree, &value)
		}
	}

	arr := []int{}

	preorder(0, tree, &arr)

	fmt.Printf("preorder: %v\n", arr)

	arr = []int{}

	inorder(0, tree, &arr)

	fmt.Printf("inorder: %v\n", arr)

	arr = []int{}

	postorder(0, tree, &arr)

	fmt.Printf("postorder: %v\n", arr)

	arr = []int{}

	levelorder(0, tree, &arr)

	fmt.Printf("level orderR: %v\n", arr)

	fmt.Printf("height: %v", height(0, tree))
}

func preorder(start int, tree []*int, arr *[]int) {
	if tree[start] == nil {
		return
	}

	*arr = append(*arr, *tree[start])

	left := 2 * start + 1
	right := 2 * start + 2

	if left < len(tree) {
		preorder(left, tree, arr)
	}

	if right < len(tree) {
		preorder(right, tree, arr)
	}
}

func inorder(start int, tree []*int, arr *[]int) {
	if tree[start] == nil {
		return
	}

	left := start * 2 + 1
	right := start * 2 + 2

	if left < len(tree) {
		inorder(left, tree, arr)
	}

	*arr = append(*arr, *tree[start])

	if right < len(tree) {
		inorder(right, tree, arr)
	}
}

func postorder(start int, tree []*int, arr *[]int) {
	if tree[start] == nil {
		return
	}

	left := start * 2 + 1
	right := start * 2 + 2

	if left < len(tree) {
		postorder(left, tree, arr)
	}

	if right < len(tree) {
		postorder(right, tree, arr)
	}

	*arr = append(*arr, *tree[start])
}

func levelorder(start int, tree []*int, arr *[]int) {
	queue := []int{ start }

	for len(queue) > 0 {
		node := queue[0]

		queue = queue[1:]

		*arr = append(*arr, *tree[node])

		left := 2 * node + 1
		right := 2 * node + 2

		if left < len(tree) && tree[left] != nil {
			queue = append(queue, left)
		}

		if right < len(tree) && tree[right] != nil {
			queue = append(queue, right)
		}
	}
}

func height(start int, tree []*int) int {
	if tree[start] == nil {
		return 0
	} else {
		left := start * 2 + 1
		right := start * 2 + 2

		leftHeight := 0
		rightHeight := 0

		if left < len(tree) {
			leftHeight = height(left, tree)
		}

		if right < len(tree) {
			rightHeight = height(right, tree)
		}

		if leftHeight > rightHeight {
			return leftHeight + 1
		} else {
			return rightHeight + 1
		}
	}
}