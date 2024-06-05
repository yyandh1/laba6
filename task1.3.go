package main

import (
	"fmt"
	"math/rand"
	"time"
)

const STR = 40
const STOLBS = 80

func createFigures(setka [][]int) {
	setka[20][20] = 1
	setka[20][21] = 1
	setka[21][20] = 1
	setka[21][21] = 1

	setka[30][30] = 1
	setka[30][31] = 1
	setka[30][29] = 1

	setka[0][1] = 1
	setka[1][2] = 1
	setka[2][0] = 1
	setka[2][1] = 1
	setka[2][2] = 1
}

func createRandomColony(setka [][]int) {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < STR; i++ {
		for j := 0; j < STOLBS; j++ {
			setka[i][j] = rand.Intn(2)
		}
	}
}

func countLiveNeighbors(setka [][]int, stroka, stolbec int) int {
	count := 0
	for i := stroka - 1; i <= stroka+1; i++ {
		for j := stolbec - 1; j <= stolbec+1; j++ {
			if i == stroka && j == stolbec {
				continue
			}
			x, y := i, j
			if x < 0 || x >= STR || y < 0 || y >= STOLBS {
				continue
			}
			if setka[x][y] == 1 {
				count++
			}
		}
	}
	return count
}

func updateSetka(setka [][]int) {
	newSetka := make([][]int, STR)
	for i := range newSetka {
		newSetka[i] = make([]int, STOLBS)
	}

	for i := 0; i < STR; i++ {
		for j := 0; j < STOLBS; j++ {
			neighbors := countLiveNeighbors(setka, i, j)
			if setka[i][j] == 1 {
				if neighbors == 2 || neighbors == 3 {
					newSetka[i][j] = 1
				}
			} else {
				if neighbors == 3 {
					newSetka[i][j] = 1
				}
			}
		}
	}
	copy(setka, newSetka)
}

func displaySetka(setka [][]int) {
	for i := 0; i < STR; i++ {
		for j := 0; j < STOLBS; j++ {
			if setka[i][j] == 1 {
				fmt.Print("0")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	setka := make([][]int, STR)
	for i := range setka {
		setka[i] = make([]int, STOLBS)
	}

	createFigures(setka)
	createRandomColony(setka)

	for {
		displaySetka(setka)
		updateSetka(setka)
		time.Sleep(150 * time.Millisecond)
	}
}