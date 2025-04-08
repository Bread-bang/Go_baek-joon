package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewScanner(os.Stdin)
	reader.Scan()

	str := []byte(reader.Text())
	length := len(str)

	set := make(map[string]struct{})

	for i := 0; i < length; i++ {
		firstIdx := 0
		for j := i; j < length; j++ {
			partialStr := string(str[firstIdx : j + 1])
			// fmt.Println("[", firstIdx, j + 1, "]", partialStr)
			set[partialStr] = struct{}{}
			firstIdx++
		}
	}

	// for str := range set {
	// 	fmt.Println(str)
	// }

	fmt.Println(len(set))

}