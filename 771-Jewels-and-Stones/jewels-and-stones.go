package main

import (
	"fmt"
	"strings"
)

func numJewelsInStones(J string, S string) int {
	res := 0
	for _, v := range strings.Split(J, "") {
		res += strings.Count(S, v)
	}
	return res
}

func main() {
	fmt.Println(numJewelsInStones("aA", "aaAbbbdcA"))
}
