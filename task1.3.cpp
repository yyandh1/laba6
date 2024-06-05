#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "windows.h"

using namespace std;

const int STR= 40;//STR
const int STOLBS = 80;//столбцы

void createFigures(vector<vector<int>>& setka) {
    // Блок 
    setka[20][20] = 1; setka[20][21] = 1;
    setka[21][20] = 1; setka[21][21] = 1;

    // Мигалка 
    setka[30][30] = 1; setka[30][31] = 1; setka[30][29] = 1;

    // Планер 
    setka[0][1] = 1;
    setka[1][2] = 1;
    setka[2][0] = 1; setka[2][1] = 1; setka[2][2] = 1;
}

// Заполнение сетки случайными живыми клетками
void createRandomColony(vector<vector<int>>& setka) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < STOLBS; j++) {
            setka[i][j] = rand() % 2;
        }
    }
}

// Функция для подсчета живых соседей клетки
int countLiveNeighbors(vector<vector<int>>& setka, int stroka, int stolbec) {
    int count = 0;
    for (int i = stroka - 1; i <= stroka + 1; i++) {
        for (int j = stolbec - 1; j <= stolbec + 1; j++) {
            if (i == stroka && j == stolbec)
                continue;
            int x = i;
            int y = j;
            if (x < 0  || x >= STR || y < 0 || y >= STOLBS) {
                continue;
            }
            if (setka[x][y] == 1)
                count++;
        }
    }
    return count;
}


// Функция для обновления состояния клеток
void updatesetka(vector<vector<int>>& setka) {
    vector<vector<int>> newsetka(STR, vector<int>(STOLBS, 0));
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < STOLBS; j++) {
            int neighbors = countLiveNeighbors(setka, i, j);
            if (setka[i][j] == 1) {
                if (neighbors == 2 || neighbors == 3)
                    newsetka[i][j] = 1;
            }
            else {
                if (neighbors == 3)
                    newsetka[i][j] = 1;
            }
        }
    }
    setka = newsetka;
}

// Функция для отображения текущего состояния сетки
void displaysetka(vector<vector<int>>& setka) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < STOLBS; j++) {
            cout << (setka[i][j] == 1 ? "0" : " ");
        }
        cout << endl;
    }
}

int main() {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));

    // Создаем начальную сетку
    vector<vector<int>> setka(STR, vector<int>(STOLBS, 0));

    createFigures(setka);

    createRandomColony(setka);

    // Симулируем работу клеточного автомата
    while (true) {
        displaysetka(setka);
        updatesetka(setka);
#ifdef _WIN32
        Sleep(150);
#else
        usleep(1000000);
#endif
    }

    return 0;
}