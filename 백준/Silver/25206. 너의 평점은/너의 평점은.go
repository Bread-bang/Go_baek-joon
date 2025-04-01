package main

import (
	"fmt"
)

func main() {
	var credit float32
	var objectName string
	var grade string
	
	var totalCredit float32
	var totalGrade float32
	
	N := 20

	for {
		if N == 0 {
			break
		}

		fmt.Scanln(&objectName, &credit, &grade)
		
		switch grade {
		case "A+":
			totalGrade += credit * 4.5
			totalCredit += credit
		case "A0":
			totalGrade += credit * 4.0
			totalCredit += credit
		case "B+":
			totalGrade += credit * 3.5
			totalCredit += credit
		case "B0":
			totalGrade += credit * 3.0
			totalCredit += credit
		case "C+":
			totalGrade += credit * 2.5
			totalCredit += credit
		case "C0":
			totalGrade += credit * 2.0
			totalCredit += credit
		case "D+":
			totalGrade += credit * 1.5
			totalCredit += credit
		case "D0":
			totalGrade += credit * 1.0 
			totalCredit += credit
		case "F":
			totalGrade += credit * 0.0
			totalCredit += credit
		}

		N--
	}
	if totalCredit == 0 {
		fmt.Print("0.000000")
	} else {
		fmt.Printf("%.6f", totalGrade / totalCredit)
	}
}