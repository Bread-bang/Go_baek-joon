package main

import "fmt"

func main() {
	n := 0
	fmt.Scan(&n)

	dp := make([]int, n + 1)

	dp[1] = 1

	for i := 2; i < n + 1; i++ {
		dp[i] = dp[i - 1] + dp[i - 2]
	}

	fmt.Println(dp[n])
}
