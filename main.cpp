#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void bubbleSortBase(vector<int> arr, int& comp, int& swaps) {
    comp = 0; swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void bubbleSortMejora1(vector<int> arr, int& comp, int& swaps) {
    comp = 0; swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void bubbleSortMejora2(vector<int> arr, int& comp, int& swaps) {
    comp = 0; swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int> arr, int& comp, int& swaps) {
    comp = 0; swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            swaps++;
        }
    }
}

void probar(const string& nombre, const vector<int>& arr) {
    cout << "--- Caso de prueba: " << nombre << " ---\n";
    int comp, swaps;

    bubbleSortBase(arr, comp, swaps);
    cout << "Bubble Sort Base:     Comparaciones = " << comp << ", Intercambios = " << swaps << "\n";

    bubbleSortMejora1(arr, comp, swaps);
    cout << "Bubble Sort Mejora 1: Comparaciones = " << comp << ", Intercambios = " << swaps << "\n";

    bubbleSortMejora2(arr, comp, swaps);
    cout << "Bubble Sort Mejora 2: Comparaciones = " << comp << ", Intercambios = " << swaps << "\n";

    selectionSort(arr, comp, swaps);
    cout << "Selection Sort:       Comparaciones = " << comp << ", Intercambios = " << swaps << "\n\n";
}

int main() {
    probar("", { 5, 3, 8, 2 });
    probar("", { 1, 2, 3, 4, 5 });
    probar("", { 5, 4, 3, 2, 1 });
    return 0;
}