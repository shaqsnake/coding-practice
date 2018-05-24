package main

import "fmt"

func run(v *int) {
	fmt.Printf("v:%p\n", &v)
}

func main() {
	b := 10
	var a *int
	a = &b
	fmt.Printf("a:%p\n", &a)
	fmt.Printf("b:%p\n", &b)
	run(a)
}
