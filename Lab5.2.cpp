#include <iostream>
#include <vector>
#include <cmath>// Для floor и log2
#include <algorithm>// Для swap
#include <chrono> // Для измерения времени

using namespace std;
using namespace std::chrono;

// Функция для слияния двух "биномиальных списков"
void binomialMerge(vector<int>& arr, int start, int mid, int end) {
    vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

    int i = 0, j = 0, k = start;

    // Слияние двух подсписков
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Добавление оставшихся элементов
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

// Рекурсивная биномиальная сортировка
void binomialSortRecursive(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    // Рекурсивно сортируем левую и правую половины
    binomialSortRecursive(arr, start, mid);
    binomialSortRecursive(arr, mid + 1, end);
    
    // Слияние отсортированных половин
    binomialMerge(arr, start, mid, end);
}

// Функция-обертка для биномиальной сортировки
void binomialSort(vector<int>& arr) {
    if (arr.empty()) return;
    binomialSortRecursive(arr, 0, arr.size() - 1);
}

// Функция проверки отсортированности массива
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> testArrays = {
        {},
        {5},
        {9, 3, 7, 5, 6, 4, 2, 8, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5, 4, 3, 2, 1},
        {4, 2, 2, 8, 3, 3, 1, 5, 5}
    };

    for (size_t i = 0; i < testArrays.size(); ++i) {
        cout << "Test " << i + 1 << ": ";
        
        auto start = high_resolution_clock::now();
        binomialSort(testArrays[i]);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        if (isSorted(testArrays[i])) {
            cout << "PASSED. Time: " << duration.count() << " microseconds" << endl;
        } else {
            cout << "FAILED. Time: " << duration.count() << " microseconds" << endl;
        }
    }

    // Тесты производительности на разных размерах массива
    vector<int> sizes = {1000, 10000, 100000, 1000000};
    
    for(int N : sizes) {
        vector<int> largeArray(N);
        for (int i = 0; i < N; ++i) {
            largeArray[i] = rand() % 1000000;
        }

        cout << "Sorting array of size " << N << "..." << endl;
        
        auto start = high_resolution_clock::now();
        binomialSort(largeArray);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        if (isSorted(largeArray)) {
            cout << "PASSED. Time: " << duration.count() << " milliseconds" << endl;
        } else {
            cout << "FAILED. Time: " << duration.count() << " milliseconds" << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}

/*
Подсчет асимптотики:
1. Временная сложность:
   - Лучший случай: O(n log n)
   - Средний случай: O(n log n)
   - Худший случай: O(n log n)
   
   Обоснование: На каждом уровне рекурсии выполняется слияние, 
   которое требует O(n) операций. Глубина рекурсии - log n уровней.
   Итого: O(n) * O(log n) = O(n log n)

2. Подсчет памяти:
   Входные данные:
   - Исходный массив: n * sizeof(int) байт
   
   Дополнительная память:
   - Временные массивы для слияния: n * sizeof(int) байт
   - Рекурсивный стек: O(log n) * sizeof(int) байт
   - Локальные переменные в функциях:
     * start, mid, end: 3 * sizeof(int)
     * i, j, k: 3 * sizeof(int)
   
   Итого дополнительной памяти: O(n) байт
*/
