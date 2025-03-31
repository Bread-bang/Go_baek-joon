package main

import "fmt"

func main() {
	var str string
	fmt.Scanln(&str)

	left := 0
	right := len(str) - 1

	N := len(str) / 2

	isPelindrome := true

	for {
		if N == 0 {
			break
		}

		if str[left] != str[right] {
			isPelindrome = false
			break
		}

		left++
		right--
		N--
	}

	if isPelindrome == true {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}