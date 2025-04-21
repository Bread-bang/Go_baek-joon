package main

import (
	"container/heap"
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int) 	 { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push (x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n - 1]		// Mark on the last element
	*h = old[0 : n- 1]	// Assign the heap except for last element
	return x
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	strN , _:= reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(strN))

	h := &IntHeap{}
	heap.Init(h)

	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		element, _ := strconv.Atoi(strings.TrimSpace(line)) 

		if element == 0 {
			if h.Len() == 0 {
				fmt.Fprintln(writer, 0)
				continue
			} else {
				fmt.Fprintln(writer, heap.Pop(h))
			}
		} else {
			heap.Push(h, element)
		}
	}
}