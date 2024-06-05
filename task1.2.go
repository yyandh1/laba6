package main

import (
	"fmt"
	"math/rand"
	"time"
)

func sumOfDigits(num int) int {
	sum := 0
	for num > 0 {
		sum += num % 10
		num /= 10
	}
	return sum
}

func main() {
	rand.Seed(time.Now().Unix())

	const M, N = 10, 10

	matrix := [M][N]int{}
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			matrix[i][j] = rand.Intn(101) + 100
		}
	}

	fmt.Println("Original matrix:")
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}

	maxRowSum := 0
	maxRowIndex := 0
	for i := 0; i < M; i++ {
		rowSum := 0
		for j := 0; j < N; j++ {
			rowSum += sumOfDigits(matrix[i][j])
		}
		if rowSum > maxRowSum {
			maxRowSum = rowSum
			maxRowIndex = i
		}
	}

	fmt.Println("Row with the highest sum of digits of elements:", maxRowIndex+1)
	fmt.Println("Sum:", maxRowSum)
}