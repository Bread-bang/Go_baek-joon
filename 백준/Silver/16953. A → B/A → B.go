package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	A, B int
)

func BFS(A int, opCnt int) {
	queue := [][2]int{}

	queue = append(queue, [2]int{A, opCnt})
	
	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]

		if B == front[0] {
			fmt.Fprintln(w, front[1])
			return
		}

		if front[0] * 2 <= B {
			queue = append(queue, [2]int{front[0] * 2, front[1] + 1})
		}

		if front[0] * 10 + 1 <= B {
			queue = append(queue, [2]int{front[0] * 10 + 1, front[1] + 1})
		}
	}
	
	fmt.Fprintln(w, -1)
}

func main() {
	defer w.Flush()

	line, _ := r.ReadString('\n')
	each := strings.Fields(line)
	A, _ = strconv.Atoi(each[0])
	B, _ = strconv.Atoi(each[1])

	BFS(A, 1)
}