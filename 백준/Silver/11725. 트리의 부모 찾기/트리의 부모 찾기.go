package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	parentNodes []int
	matrix [][]int
	visited []bool
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func bfs(startNode int) {
	queue := []int{}

	queue = append(queue, startNode)
	visited[startNode] = true

	for {
		if len(queue) == 0 {
			break
		}

		front := queue[0]
		queue = queue[1:]

		for i := 0; i < len(matrix[front]); i++ {
			element := matrix[front][i]
			if !visited[element] {
				queue = append(queue, element)
				parentNodes[element] = front
				visited[element] = true
			}
		}
	}
}

func main() {
	defer w.Flush()

	strN, _ := r.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(strN))

	parentNodes = make([]int, N + 1)
	matrix = make([][]int, N + 1)
	visited = make([]bool, N + 1)

	for i := 1; i < N; i++ {
		line, _ := r.ReadString('\n')
		each := strings.Fields(line)
		num1, _ := strconv.Atoi(each[0])
		num2, _ := strconv.Atoi(each[1])
		matrix[num1] = append(matrix[num1], num2)
		matrix[num2] = append(matrix[num2], num1)
	}

	bfs(1)

	for i := 2; i < len(parentNodes); i++ {
		fmt.Fprint(w, parentNodes[i])
		fmt.Fprintln(w)
	}
}