package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	matrix [][]int
	isVisited [][]bool
	M int
	N int
)

func BFS(i, j int) {
	queue := [][]int{}
	
	queue = append(queue, []int{i, j})	
	isVisited[i][j] = true

	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]

		dx := []int{1, 0, -1, 0}
		dy := []int{0, 1, 0, -1}

		for d := 0; d < 4; d++ {
			nx := front[0] + dx[d]
			ny := front[1] + dy[d]

			if nx >= 0 && nx < M && ny >= 0 && ny < N {
				if !isVisited[nx][ny] && matrix[nx][ny] == 1 {
					isVisited[nx][ny] = true
					queue = append(queue, []int{nx, ny})
				}
			}
		}
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)

	strT, _ := r.ReadString('\n')
	T, _ := strconv.Atoi(strings.TrimSpace(strT))

	for i := 0; i < T; i++ {
		line, _ := r.ReadString('\n')
		each := strings.Fields(line)
		M, _ = strconv.Atoi(each[0])
		N, _ = strconv.Atoi(each[1])
		K, _ := strconv.Atoi(each[2])

		matrix = make([][]int, M)
		isVisited = make([][]bool, M)
		for i := 0; i < M; i++ {
			matrix[i] = make([]int, N)
			isVisited[i] = make([]bool, N)
		}

		var X, Y int
		for j := 0; j < K; j++ {
			line, _ = r.ReadString('\n')
			each = strings.Fields(line)
			X, _ = strconv.Atoi(each[0])
			Y, _ = strconv.Atoi(each[1])

			matrix[X][Y] = 1
		}

		cnt := 0

		for i := 0; i < M; i++ {
			for j := 0; j < N; j++ {
				if !isVisited[i][j] && matrix[i][j] == 1 {
					BFS(i, j)
					cnt++
				}
			}
		}

		fmt.Println(cnt)
	}
}