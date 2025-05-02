package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	originMatrix []int
	originVisitedMatrix []bool
	tmpMatrix []int
	N, M int
	w  = bufio.NewWriter(os.Stdout)
)

func backtrack(start int, depth int) {
	if depth == M {
		for i, v := range tmpMatrix {
			if i > 0 {
				fmt.Fprint(w, " ")
			}
			fmt.Fprint(w, v)
		}
		fmt.Fprintln(w)
		return
	}

	for i := start; i < len(originMatrix); i++ {
		if originVisitedMatrix[i] != true {
			tmpMatrix[depth] = originMatrix[i]
			originVisitedMatrix[i] = true
			backtrack(start, depth + 1)
			originVisitedMatrix[i] = false
		}
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)

	line, _ := r.ReadString('\n')
	each := strings.Fields(line)
	N, _ = strconv.Atoi(each[0])
	M, _ = strconv.Atoi(each[1])

	line, _ = r.ReadString('\n')
	each = strings.Fields(line)

	originMatrix = make([]int, N + 1)
	for i := 0; i < N; i++ {
		originMatrix[i + 1], _ = strconv.Atoi(each[i])
	}
	sort.Ints(originMatrix)

	originVisitedMatrix = make([]bool, N + 1)

	tmpMatrix = make([]int, M)

	backtrack(1, 0)

	w.Flush()
}