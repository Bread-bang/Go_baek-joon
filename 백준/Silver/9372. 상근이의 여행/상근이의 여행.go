package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	TestCaseStr, _ := r.ReadString('\n')
	T, _:= strconv.Atoi(strings.TrimSpace(TestCaseStr))

	for i := 0; i < T; i++ {
		line, _ := r.ReadString('\n')
		each := strings.Fields(line)
		N, _ := strconv.Atoi(each[0])
		M, _ := strconv.Atoi(each[1])

		for j := 0; j < M; j++ {
			r.ReadString('\n')
		}

		fmt.Println(N - 1)
	}
}