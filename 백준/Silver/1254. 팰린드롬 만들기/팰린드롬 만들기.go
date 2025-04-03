package main

import "fmt"

func isPalindrome(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if s[i] != s[n-1-i] {
			return false
		}
	}
	return true
}

func minPalindromeLength(s string) int {
	n := len(s)
	for i := 0; i <= n; i++ {
		if isPalindrome(s[i:]) {
			addLen := i
			return n + addLen
		}
	}
	return 2 * n
}

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(minPalindromeLength(s))
}