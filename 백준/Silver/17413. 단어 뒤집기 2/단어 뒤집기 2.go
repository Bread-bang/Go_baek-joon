package main

import (
	"container/list"
	"fmt"
	"os"
)

type Stack struct {
	v *list.List
}

func NewStack() *Stack {
	return &Stack{ list.New() }
}

func (s *Stack) Push(val interface {}) {
	s.v.PushBack(val)
}

func (s *Stack) Pop() interface {} {
	back := s.v.Back()
	if back != nil {
		return s.v.Remove(back)
	}
	return nil
}

func main() {
	stack := NewStack()

	buf := make([]byte, 100001)
	n, _ := os.Stdin.Read(buf)
	str := string(buf[:n - 1])

	var result []byte

	isTagOpened := false

	for i := 0; i < len(str); i++ {
		if str[i] == '<' {
			for val := stack.Pop(); val != nil; val = stack.Pop() {
				// fmt.Printf("%c", val)
				result = append(result, val.(byte))
			}
			isTagOpened = true
			// fmt.Printf("%c", str[i])
			result = append(result, str[i])

		} else if str[i] == '>' {
			isTagOpened = false
			// fmt.Printf("%c", str[i])
			result = append(result, str[i])

		} else if !isTagOpened {
			if str[i] == ' ' {
				for val := stack.Pop(); val != nil; val = stack.Pop() {
					// fmt.Printf("%c", val)
					result = append(result, val.(byte))
				}
				// fmt.Printf("%c", str[i])
				result = append(result, str[i])
			} else {
				stack.Push(str[i])
			}

		} else if isTagOpened {
			// fmt.Printf("%c", str[i])
			result = append(result, str[i])
		}
	}
	
	for val := stack.Pop(); val != nil; val = stack.Pop() {
		// fmt.Printf("%c", val)
		result = append(result, val.(byte))
	}

	fmt.Println(string(result))
}