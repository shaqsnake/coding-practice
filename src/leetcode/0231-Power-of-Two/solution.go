package main

import (
	"fmt"
)

func isPowerOfTwo(n int) bool {
	return n > 0 && (n&-n) == n
}

func main() {
	for _, n := range []int{1, 16, 218} {
		fmt.Println(isPowerOfTwo(n))
	}
}
