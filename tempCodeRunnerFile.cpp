#include <iostream>
#include <vector>
#include <cassert>

// Функция для вычисления суммы элементов главной диагонали
int sumMainDiagonal(const std::vector<std::vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size(); // Получаем размер матрицы
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i]; // Суммируем элементы на главной диагонали
    }
    return sum;
}

// Тестовые функции
void runTests() {
    // Тест 1: Матрица 2x2
    std::vector<std::vector<int>> matrix1 = {{1, 1}, {1, 2}};
    assert(sumMainDiagonal(matrix1) == 3); // 1 + 2 = 3

    // Тест 2: Матрица 3x3
    std::vector<std::vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    assert(sumMainDiagonal(matrix2) == 15); // 1 + 5 + 9 = 15

    // Тест 3: Матрица 4x4
    std::vector<std::vector<int>> matrix3 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    assert(sumMainDiagonal(matrix3) == 34); // 1 + 6 + 11 + 16 = 34

    // Тест 4: Матрица 3x3 с нулями
    std::vector<std::vector<int>> matrix4 = {{0, 2, 3}, {4, 0, 6}, {7, 8, 0}};
    assert(sumMainDiagonal(matrix4) == 0); // 0 + 0 + 0 = 0

    // Тест 5: Матрица 1x1
    std::vector<std::vector<int>> matrix5 = {{42}};
    assert(sumMainDiagonal(matrix5) == 42); // 42

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    // Запускаем тесты
    runTests();

    // Основная программа для ввода данных пользователем
    int n;
    std::cout << "Enter matrix size (n x n): ";
    std::cin >> n;
    
    // Вводим матрицу
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Enter matrix elements row by row:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Выводим сумму чисел главной диагонали
    int result = sumMainDiagonal(matrix);
    std::cout << "Sum of the main diagonal elements: " << result << std::endl;

    return 0;
}
