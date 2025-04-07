package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N string
	var B int

	fmt.Scan(&N, &B)

	result, err := strconv.ParseInt(N, B, 64)
	if err != nil {
		fmt.Println("변환 오류:", err)
		return
	}

	fmt.Println(result)
}