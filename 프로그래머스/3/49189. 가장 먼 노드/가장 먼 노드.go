func solution(n int, edge [][]int) int {
	adjList := make([][]int, n+1)

	for _, v := range edge {
		a, b := v[0], v[1]

		adjList[a] = append(adjList[a], b)
		adjList[b] = append(adjList[b], a)
	}

	dist := bfs(adjList)

	maxDist := 0
	for _, v := range dist {
		if maxDist < v {
			maxDist = v
		}
	}

	count := 0
	for _, v := range dist {
		if maxDist == v {
			count++
		}
	}

	return count
}

func bfs(adjList [][]int) []int {
	start := 1

	dist := make([]int, len(adjList))
	for i := 0; i < len(dist); i++ {
		dist[i] = -1
	}
	dist[start] = 0

	queue := []int{start}

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]

		for _, v := range adjList[cur] {
			if dist[v] == -1 {
				dist[v] = dist[cur] + 1
				queue = append(queue, v)
			}
		}
	}

	return dist[1:]
}