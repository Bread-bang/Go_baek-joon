package main

import "fmt"

var sumArr []int

func fib(n int) int {
	if n <= 1 {
		return n 
	}

	if sumArr[n] != 0 {
		return sumArr[n]
	}

	sumArr[n] = fib(n - 1) + fib(n - 2)
	return sumArr[n]
}

func main() {
	n := 0
	fmt.Scan(&n)

	sumArr = make([]int, n + 1)

	sumArr[1] = 1

	fmt.Println(fib(n))
}
