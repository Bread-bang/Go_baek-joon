package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewScanner(os.Stdin)
	reader.Scan()

	str := reader.Text()
	length := len(str)

	set := make(map[string]struct{})

	for i := 0; i < length; i++ {
		for j := i; j < length; j++ {
			set[str[i : j + 1]] = struct{}{}
		}
	}

	// for str := range set {
	// 	fmt.Println(str)
	// }

	fmt.Println(len(set))

}