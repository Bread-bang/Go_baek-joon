func solution(spell []string, dic []string) int {
   for _, word := range dic {
		m := make(map[string]int)
		for _, v := range spell {
			m[v] = 0
		}

		cnt := 0
		for _, char := range word {
			c := string(char)

			v, ok := m[c]

			if ok {
				if v != 1 {
					cnt++
					m[c] += 1
				}

				if cnt == len(m) {

					return 1
				}
				continue
			}
			break
		}
		for _, v := range spell {
			m[v] = 0
		}
	}
	return 2
}