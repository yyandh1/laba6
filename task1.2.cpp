#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    srand(time(NULL));

    const int M=10, N=10;

    int matrix[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % (200 - 100 + 1) + 100;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int maxRowSum = 0;
    int maxRowIndex = 0;
    for (int i = 0; i < M; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += sumOfDigits(matrix[i][j]);
        }
        if (rowSum > maxRowSum) {
            maxRowSum = rowSum;
            maxRowIndex = i;
        }
    }

    cout << "Строка с наибольшей суммой цифр элементов: " << maxRowIndex + 1 << endl;
    cout << "Сумма: " << maxRowSum;
    return 0;
}