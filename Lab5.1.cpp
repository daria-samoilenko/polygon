#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void runTests() {
    // Тест 1: Пустой массив
    {
        vector<int> arr;
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(arr.empty());
        cout << "Test 1 passed: Empty array. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 2: Массив с одним элементом
    {
        vector<int> arr = {42};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(arr.size() == 1 && arr[0] == 42);
        cout << "Test 2 passed: Single element array. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 3: Массив с одинаковыми элементами
    {
        vector<int> arr = {7, 7, 7, 7, 7};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(std::is_sorted(arr.begin(), arr.end()));
        cout << "Test 3 passed: Array with identical elements. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 4: Уже отсортированный массив
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(std::is_sorted(arr.begin(), arr.end()));
        cout << "Test 4 passed: Already sorted array. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 5: Обратно отсортированный массив
    {
        vector<int> arr = {5, 4, 3, 2, 1};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(std::is_sorted(arr.begin(), arr.end()));
        cout << "Test 5 passed: Reverse sorted array. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 6: Массив с отрицательными числами
    {
        vector<int> arr = {-3, -1, -7, 0, -5};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(std::is_sorted(arr.begin(), arr.end()));
        cout << "Test 6 passed: Array with negative numbers. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 7: Массив с дублирующимися элементами
    {
        vector<int> arr = {4, 2, 7, 2, 9, 2};
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        assert(std::is_sorted(arr.begin(), arr.end()));
        cout << "Test 7 passed: Array with duplicate elements. Time: " << duration.count() << " microseconds" << endl;
    }

    // Тест 8: Большой массив (проверка производительности)
    {
        vector<int> sizes = {1000, 5000, 10000, 20000};
        for(int n : sizes) {
            vector<int> arr(n);
            srand(time(0));
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 10000;
            }
            
            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            
            assert(std::is_sorted(arr.begin(), arr.end()));
            cout << "Test 8 passed: Large array of size " << n << ". Time: " << duration.count() << " milliseconds" << endl;
        }
    }
}

int main() {
    runTests();
    cout << "All tests passed!" << endl;
    return 0;
}

/*
Анализ алгоритма Bubble Sort:

Временная сложность:
- Лучший случай: O(n) - когда массив уже отсортирован
- Средний случай: O(n^2)
- Худший случай: O(n^2) - когда массив отсортирован в обратном порядке

Пространственная сложность:
- O(1) - константная, требуется только одна дополнительная переменная для swap
- Сортировка выполняется in-place (на месте)
- Не требует дополнительной памяти, кроме переменной для обмена элементов

Подсчет памяти:
1. Входной массив размера n: sizeof(int) * n байт
2. Дополнительные переменные:
   - i (int): 4 байта
   - j (int): 4 байта
   - n (int): 4 байта
   - swapped (bool): 1 байт
   - временная переменная для swap (int): 4 байта

Итого дополнительной памяти: 17 байт (константная память)
Общая память: sizeof(int) * n + 17 байт = O(1) дополнительной памяти
*/
