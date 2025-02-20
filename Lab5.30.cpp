#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void countingSort(vector<int>& arr, int k) {
    vector<int> count(k, 0);
    
    for (int num : arr) {
        count[num]++;
    }
    
    int index = 0;
    for (int i = 0; i < k; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void testCountingSort() {
    // Тест 1: Базовый тест с малым массивом
    vector<int> arr1 = {3, 1, 4, 1, 5, 9, 2, 6};
    int k1 = 10;
    
    auto start1 = high_resolution_clock::now();
    countingSort(arr1, k1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    
    cout << "Test 1 (small array). Time: " << duration1.count() << " microseconds\n";
    cout << "Sorted array: ";
    for (int num : arr1) cout << num << " ";
    cout << endl << endl;

    // Тест 2: Массив с одинаковыми элементами
    vector<int> arr2 = {2, 2, 2, 2, 2};
    int k2 = 3;
    
    auto start2 = high_resolution_clock::now();
    countingSort(arr2, k2);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    
    cout << "Test 2 (identical elements). Time: " << duration2.count() << " microseconds\n";
    cout << "Sorted array: ";
    for (int num : arr2) cout << num << " ";
    cout << endl << endl;

    // Тест 3: Средний массив
    vector<int> arr3 = {5, 2, 9, 1, 5, 6, 8, 3, 2, 5, 1, 7, 4, 0, 9};
    int k3 = 10;
    
    auto start3 = high_resolution_clock::now();
    countingSort(arr3, k3);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    
    cout << "Test 3 (medium array). Time: " << duration3.count() << " microseconds\n";
    cout << "Sorted array: ";
    for (int num : arr3) cout << num << " ";
    cout << endl << endl;

    // Тест 4: Большой массив
    vector<int> arr4(100000);
    int k4 = 1000;
    for(int i = 0; i < 100000; i++) {
        arr4[i] = rand() % 1000;
    }
    
    auto start4 = high_resolution_clock::now();
    countingSort(arr4, k4);
    auto end4 = high_resolution_clock::now();
    auto duration4 = duration_cast<milliseconds>(end4 - start4);
    
    cout << "Test 4 (large array, n=100000). Time: " << duration4.count() << " milliseconds\n";
    cout << "Array too large to display" << endl;
}

int main() {
    testCountingSort();
    return 0;
}

/*
Подсчет асимптотики:
1. Временная сложность: O(n + k)
   где n - размер массива, k - диапазон значений
   - Первый проход (подсчёт): O(n)
   - Второй проход (восстановление): O(k)
   Итоговая сложность: O(n + k)
   
   Лучший случай: O(n + k)
   Средний случай: O(n + k)
   Худший случай: O(n + k)

2. Подсчет памяти:
   Входные данные:
   - Исходный массив: n * sizeof(int) байт
   
   Дополнительная память:
   - Массив подсчета: k * sizeof(int) байт
   - Локальные переменные:
     * index: sizeof(int) байт
     * i: sizeof(int) байт
     * num: sizeof(int) байт
   
   Итого дополнительной памяти: O(k) байт
   
   Особенности:
   - Если k << n, то сортировка эффективна по памяти
   - Если k ≈ n или k > n, то требуется значительный объем дополнительной памяти
   - Сортировка не является in-place (требует дополнительную память)
*/
