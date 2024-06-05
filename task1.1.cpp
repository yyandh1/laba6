#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    const int M = 10, N = 10;

    int matrix[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % (50 - 10 + 1) + 10;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Замена максимального и минимального элементов в каждой строке
    for (int i = 0; i < M; i++) {
        int minVal = matrix[i][0], minIndex = 0;
        int maxVal = matrix[i][0], maxIndex = 0;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minIndex = j;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxIndex = j;
            }
        }
        int temp = matrix[i][minIndex];
        matrix[i][minIndex] = matrix[i][maxIndex];
        matrix[i][maxIndex] = temp;
    }

    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Создание новой матрицы с минимальными и максимальными элементами
    int newMatrix[2][N];
    for (int j = 0; j < N; j++) {
        newMatrix[0][j] = matrix[0][j];
        newMatrix[1][j] = matrix[0][j];
        for (int i = 1; i < M; i++) {
            if (matrix[i][j] < newMatrix[0][j]) {
                newMatrix[0][j] = matrix[i][j];
            }
            if (matrix[i][j] > newMatrix[1][j]) {
                newMatrix[1][j] = matrix[i][j];
            }
        }
    }

    cout << "Новая матрица:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}