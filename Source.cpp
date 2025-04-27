#include <iostream>
#include <iomanip>
using namespace std;

const int M = 20, N = 20; // Максимальные размеры матрицы

// Функция ввода матрицы с проверкой размеров
void getMatrix(int matr[M][N], int& rows, int& cols) {
    do {
        cout << "Enter number of rows (2-20): ";
        cin >> rows;
        cout << "Enter number of columns (2-20): ";
        cin >> cols;
    } while (rows < 2 || rows > 20 || cols < 2 || cols > 20);

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matr[i][j];
        }
    }
}

// Функция вывода матрицы
void showMatrix(const int matr[M][N], int rows, int cols) {
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matr[i][j];
        }
        cout << endl;
    }
}

// Задание 1: Найти номер последней строки с только четными элементами
void task1() {
    int matr[M][N];
    int rows, cols;
    getMatrix(matr, rows, cols);
    showMatrix(matr, rows, cols);

    int result = 0;
    for (int i = 0; i < rows; ++i) {
        bool allEven = true;
        for (int j = 0; j < cols; ++j) {
            if (matr[i][j] % 2 != 0) {
                allEven = false;
                break;
            }
        }
        if (allEven) result = i + 1; // Нумерация с 1
    }

    cout << "\nResult (last row with all even elements): " << result << endl;
}

// Задание 2: Поменять местами минимальный и максимальный элемент в каждом столбце
void task2() {
    int matr[M][N];
    int rows, cols;
    getMatrix(matr, rows, cols);
    showMatrix(matr, rows, cols);

    for (int j = 0; j < cols; ++j) {
        int minRow = 0, maxRow = 0;
        for (int i = 1; i < rows; ++i) {
            if (matr[i][j] < matr[minRow][j]) minRow = i;
            if (matr[i][j] > matr[maxRow][j]) maxRow = i;
        }
        swap(matr[minRow][j], matr[maxRow][j]);
    }

    cout << "\nMatrix after swapping min and max elements in each column:\n";
    showMatrix(matr, rows, cols);
}

// Главное меню выбора задания
int main() {
    int choice;
    do {
        cout << "\nChoose task (1 or 2, 0 - exit): ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Exit.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}