func solution(wallpaper []string) []int {
    isFirstFile := true
	var lux, luy, rdx, rdy int

	for i, row := range wallpaper {
		for j, column := range row {
			if column == '#' {
				if isFirstFile {
					lux = i
					luy = j
					isFirstFile = false
				}

				if i < lux {
					lux = i
				}

				if j < luy {
					luy = j
				}

				if rdx < i {
					rdx = i
				}

				if rdy < j {
					rdy = j
				}
			}
		}
	}

	return []int{lux, luy, rdx + 1, rdy + 1}
}