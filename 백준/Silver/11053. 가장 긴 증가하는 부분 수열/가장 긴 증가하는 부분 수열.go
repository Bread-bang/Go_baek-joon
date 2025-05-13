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
	LIS []int
)

func findMaxValue(t []int) int {
	if len(t) == 0 {
		panic("slice is empty")
	}

	max := t[0]
	for _, value := range t {
		if value > max {
			max = value
		}
	}

	return max
}

func main() {
	var N int
	fmt.Scan(&N)

	arr := make([]int, N + 1)

	line, _ := r.ReadString('\n')
	each := strings.Fields(line)
	
	for i := 1; i <= N; i++ {
		arr[i], _ = strconv.Atoi(each[i - 1])
	}
	
	for i := 0; i <= 1; i++ {
		LIS = append(LIS, arr[i])
	}

	for i := 2; i <= N; i++ {
		if arr[i] > LIS[len(LIS) - 1] {
			LIS = append(LIS, arr[i])
		} else {
			for j := 1; j <= N; j++ {
				if arr[i] <= LIS[j] {
					LIS[j] = arr[i]
					break
				}
			}
		}
	}
	fmt.Println(len(LIS) - 1)
}