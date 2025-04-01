package main

import "fmt"

func main() {
	var str string
	var alphabetArray [26]int

	fmt.Scan(&str)

	for _, v := range str {
		idxOfA := 97
		alphabetArray[v - rune(idxOfA)]++	// rune()을 사용하는 이유는 v의 타입이 int32이기 때문에
	}
	
	for _, v := range alphabetArray {
		fmt.Printf("%d ", v)
	}
}