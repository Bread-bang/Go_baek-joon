import "math"

func solution(k int, d int) int64 {
    count := 0
	doubleD := d * d

	for i := 0; i <= d && i*i <= doubleD; i += k {
		maxJ := int(math.Sqrt(float64(doubleD - i*i)))
		count += maxJ/k + 1
	}

	return int64(count)
}