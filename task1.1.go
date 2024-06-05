package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	const M, N = 10, 10
	matrix := [M][N]int{}

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			matrix[i][j] = rand.Intn(41) + 10
		}
	}

	fmt.Println("Original matrix:")
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}

	for i := 0; i < M; i++ {
		minVal, minIndex := matrix[i][0], 0
		maxVal, maxIndex := matrix[i][0], 0
		for j := 0; j < N; j++ {
			if matrix[i][j] < minVal {
				minVal = matrix[i][j]
				minIndex = j
			}
			if matrix[i][j] > maxVal {
				maxVal = matrix[i][j]
				maxIndex = j
			}
		}
		matrix[i][minIndex], matrix[i][maxIndex] = matrix[i][maxIndex], matrix[i][minIndex]
	}

	fmt.Println("Modified matrix:")
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}

	newMatrix := [2][N]int{}
	for j := 0; j < N; j++ {
		newMatrix[0][j] = matrix[0][j]
		newMatrix[1][j] = matrix[0][j]
		for i := 1; i < M; i++ {
			if matrix[i][j] < newMatrix[0][j] {
				newMatrix[0][j] = matrix[i][j]
			}
			if matrix[i][j] > newMatrix[1][j] {
				newMatrix[1][j] = matrix[i][j]
			}
		}
	}

	fmt.Println("New matrix:")
	for i := 0; i < 2; i++ {
		for j := 0; j < N; j++ {
			fmt.Print(newMatrix[i][j], " ")
		}
		fmt.Println()
	}
}