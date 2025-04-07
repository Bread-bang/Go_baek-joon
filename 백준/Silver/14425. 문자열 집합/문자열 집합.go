package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
) 

func main() {
	reader := bufio.NewScanner(os.Stdin)
	reader.Scan()

	firstLine := strings.Fields(reader.Text())
	N, _ := strconv.Atoi(firstLine[0])
	M, _ := strconv.Atoi(firstLine[1])

	count := 0

	set := make(map[string]struct{})

	for i := 0; i < N; i++ {
		reader.Scan()
		set[reader.Text()] = struct{}{}
	}

	for i := 0; i < M; i++ {
		reader.Scan()

		if _, exists := set[reader.Text()]; exists {
			count++
		}
	}

	fmt.Println(count)
}