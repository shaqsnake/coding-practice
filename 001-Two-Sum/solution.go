package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for k, v := range nums {
		if _, ok := m[target-v]; ok {
			return []int{m[target-v], k}
		}
		m[v] = k
	}
	return []int{}
}

func main() {
	fmt.Println(twoSum([]int{2, 7, 9, 11}, 9))
}
