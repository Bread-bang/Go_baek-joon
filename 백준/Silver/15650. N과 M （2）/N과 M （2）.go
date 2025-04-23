package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	matrix []int
	N, M int
	w = bufio.NewWriter(os.Stdout)
)

func backtrack(start int, depth int) {
	if depth == M {
		for idx, value := range matrix {
			if idx > 0 {
				fmt.Fprint(w, " ")
			}
			fmt.Fprint(w, value)
		}
		fmt.Fprintln(w)
		return
	}

	for i := start; i <= N; i++ {
		matrix[depth] = i
		backtrack(i + 1, depth + 1)
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)

	line, _ := r.ReadString('\n')
	each := strings.Fields(line)
	N, _ = strconv.Atoi(each[0])
	M, _ = strconv.Atoi(each[1])

	matrix = make([]int, M)

	backtrack(1, 0)

	w.Flush()
}