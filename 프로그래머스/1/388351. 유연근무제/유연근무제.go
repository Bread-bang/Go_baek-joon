func solution(schedules []int, timelogs [][]int, startday int) int {
	n := len(schedules)
	isdiligent := make([]bool, n)
	for i := 0; i < n; i++ {
		isdiligent[i] = true
	}

	for i, v := range schedules {
		schedules[i] = addTenMinutes(v)
	}

	for i, s := range schedules {
		day := startday
		for _, t := range timelogs[i] {
			if day == 6 || day == 7 {
				day = day%7 + 1
				continue
			}

			if s < t {
				isdiligent[i] = false
				break
			}

			day++
		}
	}

	count := 0
	for _, v := range isdiligent {
		if v {
			count++
		}
	}

	return count
}

func addTenMinutes(schedules int) int {
	hour := schedules / 100
	minute := schedules % 100

	minute += 10
	hour += minute / 60
	minute %= 60

	return hour*100 + minute
}
