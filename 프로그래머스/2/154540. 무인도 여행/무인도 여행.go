import "sort"

func solution(maps []string) []int {
	n := len(maps)
	m := len(maps[0])

	visited := make([][]bool, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]bool, m)
	}

	var result []int

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if maps[i][j] != 'X' && !visited[i][j] {
				sum := dfs(i, j, maps, visited)
				result = append(result, sum)
			}
		}
	}

	if len(result) == 0 {
		return []int{-1}
	}

	sort.Ints(result)
	return result
}

func dfs(x, y int, maps []string, visited [][]bool) int {
	visited[x][y] = true

	sum := int(maps[x][y] - '0')

	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if nx >= 0 && nx < len(maps) &&
			ny >= 0 && ny < len(maps[0]) &&
			maps[nx][ny] != 'X' &&
			!visited[nx][ny] {
			sum += dfs(nx, ny, maps, visited)
		}

	}
	return sum
}
