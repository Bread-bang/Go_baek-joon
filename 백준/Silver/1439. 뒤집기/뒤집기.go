package main

import (
	"bufio"
	"fmt"
	"os"
) 

func main() {
	reader := bufio.NewScanner(os.Stdin)
	reader.Scan()

	toggleCnt := 0

	str := reader.Text()
	isOff := false

	for i := 1; i < len(str); i++ {
		if str[i - 1] != str[i] {
			if !isOff {
				isOff = true
				toggleCnt++
			} else {
				isOff = false
			}
		}
	}

	fmt.Println(toggleCnt)
}