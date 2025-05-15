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
)

func main() {
	defer w.Flush()

	var opCnt int
	line, _ := r.ReadString('\n')
	each := strings.Fields(line)
	A, _ := strconv.Atoi(each[0])
	B, _ := strconv.Atoi(each[1])

	for B >= A {
		if B == A {
			fmt.Fprintln(w, opCnt + 1)
			return
		}

		if B % 2 == 0 {
			B /= 2
			opCnt++
		} else if B % 10 == 1 {
			B /= 10
			opCnt++
		} else {
			break
		}
	}

	fmt.Fprintln(w, -1)
}
