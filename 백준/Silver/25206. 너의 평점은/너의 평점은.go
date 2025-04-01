package main

import "fmt"
	
type Score struct {
	objectName string
	credit float32
	grade string
}

func main() {
	var sc Score
	var totalCredit float32
	var totalGrade float32

	m := map[string]float32{
		"A+": 4.5,
		"A0": 4.0,
		"B+": 3.5,
		"B0": 3.0,
		"C+": 2.5,
		"C0": 2.0,
		"D+": 1.5,
		"D0": 1.0,
		"F": 0.0,
	}
	
	N := 20

	for {
		if N == 0 {
			break
		}

		fmt.Scanln(&sc.objectName, &sc.credit, &sc.grade)

		if sc.grade != "P" {
			totalGrade += sc.credit * m[sc.grade]
			totalCredit += sc.credit
		}
		
		N--
	}
	if totalCredit == 0 {
		fmt.Print("0.000000")
	} else {
		fmt.Printf("%.6f", totalGrade / totalCredit)
	}
}