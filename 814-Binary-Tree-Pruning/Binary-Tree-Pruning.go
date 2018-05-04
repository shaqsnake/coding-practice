package main

import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// TreeNode with value and children
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (n *TreeNode) Insert(val int) *TreeNode {
	if n == nil {
		return &TreeNode{Val: val}
	} else if n.Left == nil {
		n.Left = &TreeNode{Val: val}
		return n.Left
	} else {
		n.Right = &TreeNode{Val: val}
		return n.Right
	}
}

func walkTree(root *TreeNode) {
	if root == nil {
		fmt.Printf("-1 ")
		return
	}
	fmt.Printf("%d ", root.Val)

	if root.Left != nil {
		walkTree(root.Left)
	}

	if root.Right != nil {
		walkTree(root.Right)
	}

	return
}

func pruneTree(root *TreeNode) *TreeNode {
	fmt.Println(root.Val)
	if root.Left != nil {
		root.Left = pruneTree(root.Left)
	}

	if root.Right != nil {
		root.Right = pruneTree(root.Right)
	}

	if root.Val == 0 && root.Left == nil && root.Right == nil {
		root = nil
	}

	return root
}

func main() {
	data := []int{1, 0, 1, -1, 0}
	var root *TreeNode
	for i := 0; i < len(data); i++ {
		root = root.Insert(data[i])
	}
	// root := &TreeNode{
	// 	Val:   1,
	// 	Left:  &TreeNode{Val: 0},
	// 	Right: &TreeNode{Val: 1}}

	walkTree(root)
}
