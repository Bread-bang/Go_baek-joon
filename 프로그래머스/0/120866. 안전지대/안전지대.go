type Pair struct {
	X int
	Y int
}

func solution(board [][]int) int {
    // 1인 좌표 찾기
	p := []Pair{}
	for i, line := range board {
		for j, v := range line {
			if v == 1 {
				p = append(p, Pair{i, j})
			}
		}
	}

	// 해당 좌표의 사방을 1로 표시
	dx := []int{1, -1, 0, 0, 1, -1, 1, -1}
	dy := []int{0, 0, -1, 1, 1, -1, -1, 1}

	for _, v := range p {
		for i := 0; i < 8; i++ {
			adjX := v.X + dx[i]
			adjY := v.Y + dy[i]

			if 0 <= adjX && adjX < len(board) && 0 <= adjY && adjY < len(board[0]) {
				if board[adjX][adjY] != 1 {
					board[adjX][adjY] = 1
				}
			}
		}
	}

	// 순회하면서 0인것들의 cnt를 체크
	cnt := 0
	for _, line := range board {
		for _, v := range line {
			if v == 0 {
				cnt++
			}
		}
	}

	return cnt
}