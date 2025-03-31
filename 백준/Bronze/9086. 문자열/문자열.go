package main

import "fmt"

func main() {
	var N int
	fmt.Scanln(&N)

	for {
		if N == 0 {
			break
		}

		var str string
		fmt.Scanln(&str)

		fmt.Printf("%c%c\n", str[0], str[len(str) - 1])

		N--
	}
}